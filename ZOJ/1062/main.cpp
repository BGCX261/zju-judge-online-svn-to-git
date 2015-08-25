#include <iostream>
//#include <vector>

using namespace std;
typedef long ull;

//void calculateMax(){
//	vector<ull> maxes;
//	maxes.push_back(1);
//	maxes.push_back(1);
//
//	ull curMax = 1;
//	while(curMax <500000000ull){
//		ull curIdx = maxes.size();
//		ull mm = 0;
//		for(ull l = 0;l<curIdx;l++)
//			mm += maxes[l]*maxes[curIdx-1-l];
//		maxes.push_back(mm);
//		curMax = mm;
//	}
//
//	for(ull i=0;i<maxes.size();i++)
//		cout<<maxes[i]<<endl;
//
//	cin.get();
//}

void treeSolve(ull ntree, ull curNum,const ull treeNum[]){
	ull nleft = 0,nright = ntree-1;
	while((curNum -= treeNum[nleft]*treeNum[nright]) > 0){
		nleft++;
		nright--;
	}

	curNum += treeNum[nleft]*treeNum[nright];

	ull rightIdx = curNum % treeNum[nright];
	ull leftIdx = curNum / treeNum[nright];
	if(rightIdx == 0){
		rightIdx = treeNum[nright];
	}
	else
		leftIdx ++;

	
	if(nleft > 0){
		cout<<"(";
		treeSolve(nleft, leftIdx,treeNum);
		cout<<")";
	}
	cout<<"X";
	if(nright > 0){
		cout<<"(";
		treeSolve(nright,rightIdx,treeNum);
		cout<<")";
	}
}
void solve(ull curNum, const ull treeNum[]){
	ull ntree = 0;
	ull curLeft = curNum;

	while(curLeft>0){
		ntree++;
		curLeft -= treeNum[ntree];
	}

	curLeft += treeNum[ntree];
	treeSolve(ntree,curLeft,treeNum);
	cout<<endl;
}


int main(){
	//calculateMax();
	ull treeNum[] = {1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700};
	ull curNum;
	while(((cin>>curNum)) &&(curNum!=0)){
		//cout<<"To solve:"<<curNum<<endl;
		solve(curNum,treeNum);
	}
}