#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int a0 = a,b0 = b;
	if(a<b){
		int tg = a;
		a = b;
		b = tg;
	}
	while(b>0){
	int	tg = b;
		b = a%b;
		a = tg;
	}
	cout<<(a0*b0)/a;
}