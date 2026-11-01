#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; 
		cout<<"So phan tu cua mang: ";
	cin>>n;
	float max = 0, m[n];
	for(int i = 0;i<n;i++){
		cin>>m[i];
	}
	for(int i = 0;i<n;i++){
		if(m[i]>max){
			max = m[i];
		}
	}
	cout<<"So lon nhat mang la: "<<max<<endl;
}