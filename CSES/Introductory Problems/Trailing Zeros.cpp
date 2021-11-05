#include<iostream>
typedef long long ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	ll fives = 5;
	int sum = 0;
	while(fives <= n){
		sum += n / fives;
		fives *= 5;
	}
	cout << sum;
	return 0;
}
