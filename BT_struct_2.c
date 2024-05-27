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

void output(FILE *f, SV sv[], int n, int i){
    fprintf(f, "Ho va ten: %s", sv[i].ht);
    fprintf(f, "Diem: %.2f\n", sv[i].tong);
    fprintf(f, "___________________\n");
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

void trungtuyen(FILE *f, SV sv[], int n){
    float dc;
    printf("Nhap diem chuan: ");
    scanf("%f", &dc);
    f = fopen("output.txt", "w");
    fprintf(f, "Danh sach trung tuyen: \n");
    fprintf(f, "___________________\n");
    sort(sv, n);
    for(int i = 0; i < n; i++){
        if(sv[i].tong >= dc && (sv[i].t != 0 || sv[i].l != 0 || sv[i].h != 0)){
            output(f, sv, n, i);
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
    trungtuyen(f, sv, n);
}
