#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n, x;
	cin >> n >> x;
	vector<int> w(n);
	for(int i = 0 ; i < n; i++)
		cin >> w[i];
	sort(w.begin(), w.end());
	vector<int>::iterator it1 = w.begin(), it2 = w.end() - 1;
	int counter = 0;
	while(it1 <= it2){
		if(it1 == it2){
			counter++;
			break;
		}
		if(*it1 + *it2 > x){
			it2--;
			counter++;
		}else{
			it1++;
			it2--;
			counter++;
		}
	}
	cout << counter << endl;
	return 0;
}
