#include<iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;	
		if((2 * a - b) % 3 == 0){
			int m = (2 * a - b) / 3;
			int n = a - 2 * m;
			if(m >= 0 && n >= 0)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}
