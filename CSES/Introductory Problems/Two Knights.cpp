#include<iostream>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n;
	cin >> n;
	cout << "0" << endl;
	if(n == 1)
		return 0;
	cout << "6" << endl;
	if(n == 2)
		return 0;
	cout << "28" << endl;
	if(n == 3)
		return 0;
		
	for(long long int i = 4; i <= n; i++){
		long long int inner_circle = (i-4)*(i-4) * 8;
		long long int first_row_middle = (i-4) * 4 * 4;
		int second_row_middle = (i - 4) * 6 * 4;
		
		int side_corner = 8 * 3;
		int diagonal_corner = 4 * 4;
		int corner = 4 * 2;
		long long int k = inner_circle + first_row_middle + second_row_middle + side_corner + diagonal_corner + corner;
		cout << (i*i*(i*i-1))/2 - k/2 << endl;
	}
	return 0;
}
