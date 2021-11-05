#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class movie{
public:
	int sTime, eTime;
	movie(int s, int e): sTime(s), eTime(e){}
	friend bool operator<(const movie &a, const movie &b){
		return a.eTime < b.eTime;
	}
};
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<movie> m;
	for(int i = 0 ; i < n ; i++){
		int s, e;
		cin >> s >> e;
		m.push_back(movie(s, e));
	}
	sort(m.begin(), m.end());
	int past_end = 0;
	int counter = 0;
	for(int i = 0; i < n; i++){
		if(m[i].sTime >= past_end){
			counter++;
			past_end = m[i].eTime;
		}
	}
	cout << counter << endl;
	return 0;
}
