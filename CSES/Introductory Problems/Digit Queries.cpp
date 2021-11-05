#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
ll solve(ll t){
	ll start = 1;
	ll n = 1;
	ll end = 9;
	ll p = 1;
	while(end < t){
		start = end + 1;
		n++; p *= 10;
		end += p * 9 * n;
	}
	
	ll num = p + (t - start) / n;
	vector<short> digits;
	while(num != 0){
		digits.push_back(num % 10);
		num /= 10;
	}
	return digits[digits.size() - 1 - ( (t - start) % n)];
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	while(n--){
		ll t; cin >> t;
		cout << solve(t) << endl;
	}
	return 0;
}
 
