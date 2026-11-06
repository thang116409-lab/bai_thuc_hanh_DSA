#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int ma;
	char hoTen[30];
	float d1,d2,d3;
}SinhVien;
int main(){
	int n; scanf("%d",&n);
	SinhVien *a = (SinhVien*)malloc(n*sizeof(SinhVien));
	if(a==NULL){
		printf("Khong du bo nho.");
		return 0;
	}
	for(int i = 0;i<n;i++){
		printf("\nSinh vien thu %d:\n",i+1);
		printf("Ten: "); scanf("%s",(a+i)->hoTen);
		printf("\nMa: "); scanf("%d",&(a+i)->ma);
		printf("\nDiem 1: "); scanf("%f",&(a+i)->d1);
		printf("\nDiem 2: "); scanf("%f",&(a+i)->d2);
		printf("\nDiem 3: "); scanf("%f",&(a+i)->d3);
		
	}
	for(int i = 0;i<n;i++){
		printf("\nSinh vien thu %d:\n",i+1);
		printf("Ten: %s\n",(a+i)->hoTen);
		printf("Ma: %d\n",(a+i)->ma);
		printf("Diem 1: %f\n",(a+i)->d1);
		printf("Diem 2: %f\n",(a+i)->d2);
		printf("Diem 3: %f\n",(a+i)->d3);
		
	}
	
	
}
