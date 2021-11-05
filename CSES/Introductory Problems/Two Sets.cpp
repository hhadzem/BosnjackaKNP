#include<iostream>
#include<vector>
typedef long long ll;
 
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if(n % 4 == 0 || n % 4 == 3){
		cout << "YES" << endl;
		vector<int> arr1, arr2;
		int start = 1;
		if(n & 1){
			arr1.push_back(1); arr1.push_back(2);
			arr2.push_back(3);
			start = 4;
		}	
		bool s = true;
		for(int i = start; i <= n; i+=2, s = !s){
			if(s){
				arr1.push_back(i);
				arr2.push_back(i+1);
			}else{
				arr1.push_back(i+1);
				arr2.push_back(i);
			}
		}
		
		cout << arr1.size() << endl;
		for(unsigned int i = 0 ; i < arr1.size(); i++)
			cout << arr1[i] << " ";
		cout << endl << arr2.size() << endl;
		for(unsigned int i = 0; i < arr2.size(); i++)
			cout << arr2[i] << " ";
	}else{
		cout << "NO";
	}
	return 0;
}
