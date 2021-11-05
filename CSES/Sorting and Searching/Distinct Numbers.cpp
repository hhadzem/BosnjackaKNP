#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> numbers(n);
	for(int i = 0 ; i < n; i++)
		cin >> numbers[i];
	sort(numbers.begin(), numbers.end());
	int counter = 1;
	for(int i = 1; i < n; i++)
		if(numbers[i] != numbers[i-1])	
			counter++;
	cout << counter;
	return 0;
}
