#include <iostream>
#include <cassert>
using namespace std;

int YSFWinner(int n,int m);
int main(){
	int n;
	while(cin>>n){
		if(0==n)
			break;
		int m=2;
		while(0!=YSFWinner(n-1,m)) m++;
		cout<<m<<endl;
	}

	return 0;
}

int YSFWinner(int n,int m){
	assert((n>0) && (m>0));
	if(1==n)
		return 0;
	else{
		int lastWin = 0;
		for(int i=2;i<=n;i++){
			lastWin = (lastWin+m)%i;
		}
		return lastWin;
	}

}