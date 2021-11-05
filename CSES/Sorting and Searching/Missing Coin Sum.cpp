#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> coins(n);
	for(int i = 0 ; i < n; i++)
		cin >> coins[i];
	sort(coins.begin(), coins.end());
	priority_queue<int> *pq = new priority_queue<int>();
	ll counter = 0;
	for(int i = 0; i < n; i++){
		if(counter < coins[i] - 1){
			cout << counter + 1 << endl;
			return 0;
		}
		counter = counter + coins[i];
		//cout << coins[i] << " " << counter << endl;
		
		while(!pq->empty() && pq->top() < coins[i])
			pq->pop();
		priority_queue<int> *pq2 = new priority_queue<int>();
		while(!pq->empty()){
			int curr = pq->top(); pq->pop();
			curr += coins[i];
			pq2->push(curr);
		}
		delete pq;
		pq = pq2;
	}
	cout << counter + 1 << endl;
	return 0;
}
