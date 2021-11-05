#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<algorithm>
#include<list>
using namespace std;
int main(){
	string s; cin >> s;
	sort(s.begin(), s.end());
	vector<string> permutations;
	permutations.push_back(s);
	while(next_permutation(s.begin(), s.end())){
		permutations.push_back(s);
	}
	cout << permutations.size() << endl;
	unique(permutations.begin(), permutations.end());
	for(size_t i = 0; i < permutations.size(); i++)
		cout << permutations[i] << endl;
	return 0;
}
