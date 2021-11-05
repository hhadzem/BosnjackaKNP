#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct number{
	int idx, value;
	number(int idx, int value): idx(idx), value(value){}
};
bool compare(const number &a, const number &b){
	return a.value < b.value;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<number> num;
	num.push_back(number(0, 0));
	for(int i = 0 ; i < n; i++){
		int val; cin >> val;
		num.push_back(number(i, val));
	}
	sort(num.begin(), num.end(), compare);
	int round = 0;
	for(int i = 1; i < n + 1; i++){
		if(num[i].idx < num[i-1].idx)
			round++;
	}
	cout << round + 1 << endl;
	return 0;
}
