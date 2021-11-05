#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
class booking{
public:
	int time; 
	short value; 
	booking(int time, int value):time(time), value(value){}
	friend bool operator<(const booking &a, const booking &b){
		return a.time < b.time;
	}
};
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<booking> b;
	for(int i = 0 ; i < n; i++){
		int from, to;
		cin >> from >> to;
		b.push_back(booking(from, 1));
		b.push_back(booking(to, -1));
	}
	sort(b.begin(), b.end());
	int counter = 0, res = INT_MIN;
	for(unsigned int i = 0; i < b.size(); i++){
		counter += b[i].value;
		res = max(res, counter);
	}
	cout << res << endl;
	return 0;
}
