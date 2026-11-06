#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	float *a= (float *)malloc(n * sizeof(float));
	if(a== NULL){
		printf("Khong du bo nho");
		return 0;
	}
	for(int i = 0;i<n;i++){
		scanf("%f",a+i);
	}
	printf("Mang vua nhap:\n");
	for(int i = 0;i<n;i++){
		printf("%.2f ",*(a+i));
	}
	free(a);
	return 0;
}
