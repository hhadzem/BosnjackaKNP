#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

void printVector(vector<int> m){
	for(size_t i = 0; i < m.size(); i++)
		printf("%d ", m[i]);
	printf("\n");
}

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> mice(k);
    for(int i = 0 ; i < k; i++)
        scanf("%d", &mice[i]);
    
    sort(mice.rbegin(), mice.rend());e
    
    int counter_mice = 0, moves = 0;
    
    while(counter_mice < mice.size()){
		if(moves >= mice[counter_mice])
			break;
		moves += n - mice[counter_mice];
		counter_mice++;
	}
    
    printf("%u\n", counter_mice);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        solve();
    return 0;
}
