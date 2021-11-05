#include<iostream>
#define MOD 1000000007
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll prod = 1;
	for(int i = 0; i < n; i++){
		prod = prod * 2;
		prod = prod % MOD;
	}
	cout << prod;
	return 0;
}
