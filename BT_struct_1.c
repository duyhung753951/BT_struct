#include<stdio.h>

typedef struct{
    char ht[20];
    float t, l, h, tong;
}SV;

void input(FILE *f, int n,SV sv[]){
    for(int i = 0; i < n; i++){
        fgets(sv[i].ht, 20, f);
        fscanf(f, "%f%f%f\n", &sv[i].t, &sv[i].l, &sv[i].h);
        sv[i].tong = sv[i].t + sv[i].l + sv[i].h;
    }
}

void output(SV sv[], int n, int i){
    printf("Ho va ten: %s", sv[i].ht);
    printf("Diem: %.2f\n", sv[i].tong);
    printf("___________________\n");
}

void sort(SV sv[], int n){
    SV x;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(sv[j].tong > sv[i].tong){
                x = sv[j];
                sv[j] = sv[i];
                sv[i] = x;
            }
        }
    }
}

void trungtuyen(SV sv[], int n){
    float dc;
    printf("Nhap diem chuan: ");
    scanf("%f", &dc);
    printf("Danh sach trung tuyen: \n");
    printf("___________________\n");
    sort(sv, n);
    for(int i = 0; i < n; i++){
        if(sv[i].tong >= dc){
            output(sv, n, i);
        }
    }
}

int main(){
    FILE *f;
    char tenf[20];
    scanf("%s", &tenf);
    f = fopen(tenf, "rt");
    if(f == NULL){
        perror("Can't open file!");
        return -1;
    }
    int n;
    fscanf(f, "%d\n", &n);
    SV sv[n];
    input(f, n, sv);
    trungtuyen(sv, n);
}
