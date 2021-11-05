#include<iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	if(n == 1){
		cout << "1";
		return 0;
	}else if(n == 2 || n == 3){
		cout << "NO SOLUTION";
		return 0;
	}else if(n == 4){
		cout << "2 4 1 3";
		return 0;
	}
	
	int t = n;
	while(t > 0){
		cout << t << " ";
		t -= 2;
	}
	
	t = n - 1;
	while(t > 0){
		cout << t << " ";
		t -= 2;
	}
	return 0;
}
