#include<iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	int temp;
	cin >> temp;
	long long int sum = 0;
	for(int i = 0 ; i < n - 1; i++){
		int temp2; cin >> temp2;
		if(temp2 < temp){
			sum += temp - temp2;
			temp2 = temp;
		}
		temp = temp2;
	}
	cout << sum;
	return 0;
}
