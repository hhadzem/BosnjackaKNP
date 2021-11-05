#include<iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while(n--){
		long long int x, y;
		cin >> x >> y;
		
		if(x > y){
			if(x & 1){
				long long int tt = (x - 1)*(x-1);
				cout << tt + y << endl;
			}else{
				long long int tt = x*x;
				cout << tt - y + 1 << endl;
			}
		}
		else{
			if( (y & 1) == 0){
				long long int tt = (y-1)*(y-1);
				cout << tt + x <<endl;
			}else{
				long long int tt = y*y;
				cout << tt - x + 1 << endl;
			}
		}
	}
	return 0;
}
