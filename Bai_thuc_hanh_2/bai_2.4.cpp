#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char hoTen[30];
	int ma;
	float d1,d2,d3;
}SinhVien;
struct Node{
	SinhVien data;
	struct Node*next;
	
};
struct Node *head = NULL;
int main(){
	return 0;
}

