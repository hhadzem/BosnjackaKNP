#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int counter = 1;
	int maxi = 0;
	for(unsigned int i = 1 ; i < s.length(); i++){
		if(s[i] == s[i-1])
			counter++;
		else{
			maxi = max(counter, maxi);
			counter = 1;
		}
	}
	maxi = max(counter, maxi);
	cout << maxi;
	return 0;
}
