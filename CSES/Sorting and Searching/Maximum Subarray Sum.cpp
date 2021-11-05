#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long curr = 0, sum = 0, maxi = LONG_MIN;
	int n; cin >> n;
	for(int i = 0 ; i < n; i++){
		long long  v; cin >> v;
		curr += v;
		if(curr < 0) curr = 0;
		maxi = max(maxi, v);
		sum = max(sum, curr);
	}
	if(maxi < 0)
		cout << maxi << endl;
	else
		cout << sum << endl;
	return 0;
}
