#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
vector<int> parent;
int findParent(int idx){
	if(parent[idx] == -1)
		return -1;
	if(parent[idx] == idx)
		return idx;
	return parent[idx] = findParent(parent[idx]);
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> prices(n);
	for(int i = 0; i < n; i++)
		parent.push_back(i);
		
	for(int i = 0 ; i< n; i++)
		cin >> prices[i];
	sort(prices.begin(), prices.end());
	for(int j = 0 ; j < m; j++){
		int max_price; cin >> max_price;
		if(max_price < prices[0]){
			cout << "-1" << endl;
			continue;
		}
		vector<int>::iterator it = upper_bound(prices.begin(), prices.end(), max_price);
		int idx = distance(prices.begin(), it) - 1;
		int p = findParent(idx);
		if(p == -1){
			cout << "-1" << endl;
			continue;
		}
		cout << prices[p] << endl;
		parent[p]--;
	}
	return 0;
}
