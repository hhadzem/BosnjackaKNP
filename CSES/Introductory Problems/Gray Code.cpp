#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;
void printArray(vector<string> s){
	for(unsigned int i = 0; i < s.size(); i++) cout << s[i] << endl;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	if(n == 1){
		cout << "0\n1" << endl;
		return 0;
	}
	
	vector<string> sol{"00", "01", "11", "10"};
	for(int i = 3 ; i <= n; i++){
		int _size = sol.size(); 
		for(int j = _size - 1; j >= 0; j--){
			string s = sol[j];
			s = '1' + s;
			sol[j] = '0' + sol[j];
			sol.push_back(s);
		}
	}
	
	printArray(sol);
	return 0;
}
