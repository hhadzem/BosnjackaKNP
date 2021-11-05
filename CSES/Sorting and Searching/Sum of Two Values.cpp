#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct item{
	int idx, value;
	item(int idx, int value):idx(idx), value(value){}
};
bool compare(const item &a, const item &b){
	return a.value < b.value;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	vector<item> items;
	for(int i = 0; i < n; i++){
		int v; cin >> v;
		items.push_back(item(i, v));
	}
	sort(items.begin(), items.end(), compare);
	vector<item>::iterator it1 = items.begin(), it2 = items.end() - 1;
	while(it1 < it2){
		//cout << it1->value << " " << it2->value << endl;
		if(it1->value + it2->value == x){
			cout << it1->idx + 1 << " " << it2->idx + 1 << endl;
			return 0;
		}else if(it1->value + it2->value > x)
			it2--;
		else 
			it1++;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
