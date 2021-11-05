#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> app(n), sizes(m);
	for(int i = 0 ; i < n; i++)
		cin >> app[i];
	sort(app.begin(), app.end());
	for(int j = 0; j < m; j++)
		cin >> sizes[j];
	sort(sizes.begin(), sizes.end());
	vector<int>::iterator it1 = app.begin(), it2 = sizes.begin();
	int counter = 0;
	while(it1 != app.end() && it2 != sizes.end()){
		if(*it2 <= *it1 + k && *it2 >= *it1 - k){
			counter++;
			it1++;
			it2++;
		}
		else if(*it2 < *it1 - k)
			it2++;
		else if(*it2 > *it1 + k)
			it1++;
	}
	cout << counter << endl;
	return 0;
}
