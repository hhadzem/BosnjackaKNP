#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;
typedef long long ll;
void perm(ll sum, unsigned int idx, vector<int> &arr, ll &best){
	if(idx == arr.size()){
		best = min(best, llabs(sum));
		return;
	}
	perm(sum + arr[idx], idx + 1, arr, best);
	perm(sum - arr[idx], idx + 1, arr, best);
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0 ; i < n; i++)
		cin >> arr[i];
	ll sum = 0, best = INT_MAX;
	perm(sum, 0, arr, best);
	cout << best;
	return 0;
}
