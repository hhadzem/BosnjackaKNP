#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<map>

using namespace std;

struct m_pair{
	int first, second;
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; 
	cin >> n;
	map<int, int> last_occ;
	int res = 0, temp = 0, start = 0;
	
	for(int i = 0; i < n; i++){
		int next; cin >> next;
		if(last_occ.find(next) == last_occ.end())
			last_occ[next] = -1;
			
		int last = last_occ[next];
		if(last < start)
			temp++;
		else{
			start = last + 1;
			res = max(temp, res);
			temp = i - last;
		}	
		last_occ[next] = i;
	}
	res = max(temp, res);
	cout << res << endl;	
	return 0;
}
