#include<iostream>
#include<cmath>
using namespace std;
 
void move(int from, int aux, int to, int n){
	if(n == 1){
		cout << from << " " << to << endl;
		return;
	}
	if(n == 2){
		cout << from << " " << aux << endl;
		cout << from << " " << to << endl;
		cout << aux << " " << to << endl;
		return ;
	}
	
	move(from, to, aux, n - 1);
	cout << from << " " << to << endl;
	move(aux, from, to, n - 1);
}
 
int main(){
	int n; cin >> n;
	cout << pow(2, n) - 1 << endl;
	move(1, 2, 3, n);
	return 0;
}
