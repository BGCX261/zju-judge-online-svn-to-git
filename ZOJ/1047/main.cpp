#include <iostream>

using namespace std;

const int MaxRow = 20;
const int MaxCol = 20;

int g_Perimeter = 0;
void solve(char data[MaxRow][MaxCol],int nRow,int nCol,int curRow,int curCol){
	if((curRow>=nRow)||(curRow<0)||(curCol>=nCol)||(curCol<0))
		return;
	//already checked
	if(('\0'==data[curRow][curCol]) | ('.'==data[curRow][curCol]))
		return;

	data[curRow][curCol] = '\0';

	if(nCol == (curCol+1)){
		g_Perimeter++;
	}
	else if('.'==data[curRow][curCol+1]){
		g_Perimeter++;
	}
	else{
		solve(data,nRow,nCol,curRow,curCol+1);
	}

	if(0 == (curCol)){
		g_Perimeter++;
	}
	else if('.'==data[curRow][curCol-1]){
		g_Perimeter++;
	}
	else{
		solve(data,nRow,nCol,curRow,curCol-1);
	}

	if(nRow == (curRow+1)){
		g_Perimeter++;
	}
	else if('.'==data[curRow+1][curCol]){
		g_Perimeter++;
	}
	else{
		solve(data,nRow,nCol,curRow+1,curCol);
	}


	if(0 == (curRow)){
		g_Perimeter++;
	}
	else if('.'==data[curRow-1][curCol]){
		g_Perimeter++;
	}
	else{
		solve(data,nRow,nCol,curRow-1,curCol);
	}

	solve(data,nRow,nCol,curRow+1,curCol+1);
	solve(data,nRow,nCol,curRow-1,curCol+1);
	solve(data,nRow,nCol,curRow-1,curCol-1);
	solve(data,nRow,nCol,curRow+1,curCol-1);
}

int main(){
	char data[MaxRow][MaxCol];
	int nRow,nCol,curRow,curCol;
	while(cin>>nRow>>nCol>>curRow>>curCol){
		if(!nRow)
			break;
		while('\n'!=cin.get());
		for(int i=0;i<nRow;i++){
			for(int j=0;j<nCol;j++)
				data[i][j] = char(cin.get());
			while('\n'!=cin.get());
		}
		g_Perimeter = 0;
		solve(data,nRow,nCol,curRow-1,curCol-1);
		cout<<g_Perimeter<<endl;
	}

	cin.get();
}