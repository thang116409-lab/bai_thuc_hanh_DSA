#include<stdio.h>
#include<stdlib.h>
int main(){
	int h,c;
	scanf("%d%d",&h,&c);
	float *a = (float*)malloc(h*c*sizeof(float));
	if(a==NULL){
		printf("Khong du bo nho");
		return 0;
	}
	for(int i = 0;i<h;i++){
		for(int j=0;j<c;j++){
			scanf("%f",a+i*c+j);
		}
	}
	for(int i = 0;i<h;i++){
		for(int j = 0;j<c;j++){
			printf("%f ",*(a+i*c+j));
		}
		printf("\n");
	}
	free(a);
}
