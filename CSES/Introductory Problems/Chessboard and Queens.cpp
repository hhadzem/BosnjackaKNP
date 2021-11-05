#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
typedef long long ll;
int fix(int a){return a + 7;}
void solve(	bool table[8][8], bool rows[], bool cols[], bool diag[], bool sdiag[], int placed, 
			int &counter, int i0, int j0){
	if(placed == 8){
		counter++;
		return;
	}
	
	for(int i = i0 ; i < 8; i++){
		if(!rows[i])
			continue;
		for(int j = 0 ; j < 8; j++){
			if(i == i0 && j < j0) 
				continue;
			//cout << "placed: " << placed << " " << i << " " << j << endl;
			if(!cols[j])
				continue;
			
			if(!diag[fix(i-j)])
				continue;
			if(!sdiag[i+j])
				continue;
			if(!table[i][j])
				continue;
				
			rows[i] = false; cols[j] = false;
			diag[fix(i-j)] = false; sdiag[i+j] = false;
			solve(table, rows, cols, diag, sdiag, placed + 1, counter, i, j);
			rows[i] = true; cols[j] = true;
			diag[fix(i-j)] = true; sdiag[i+j] = true;
		}
	}
}
 
int main(){
	bool table[8][8];
	memset(table, true, sizeof(table));
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			char c; cin >> c;
			if(c == '*')
				table[i][j] = false;
		}
	}
	
	bool rows[8], cols[8], diag[15], sdiag[15];
	memset(rows, true, sizeof(rows));
	memset(cols, true, sizeof(cols));
	memset(diag, true, sizeof(diag));
	memset(sdiag, true, sizeof(diag));
	int counter = 0;
	solve(table, rows, cols, diag, sdiag, 0, counter, 0, 0);
	cout << counter << endl;
	return 0;
}
