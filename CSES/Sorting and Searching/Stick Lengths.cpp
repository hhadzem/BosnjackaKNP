#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n; cin >> n;
	vector<int> l(n);
	for(int i = 0 ; i < n; i++)
		cin >> l[i];
	sort(l.begin(), l.end());
	ll res = 0, len = l[n/2];
	for(int i = 0; i < n; i++)
		res += llabs(l[i] - len);
	cout << res << endl;
	return 0;
}
