#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s; cin >> s;
	int letters[30];
	int counter = 0;
	char charToUse = ' ';
	memset(letters, 0, sizeof(letters));
	for(unsigned int i = 0 ; i < s.length(); i++)
		letters[s[i] - 'A']++;
		
	for(int i = 0; i < 28; i++)
		if(letters[i] % 2 == 1){
			charToUse = (i + 'A');
			counter++;
		}
		
	if(counter > 1){
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	
	string res = "";
	for(unsigned int i = 0 ; i < 30; i++){
		if(letters[i] != 0 && (letters[i] % 2 == 0)){
			for(int j = 0; j < letters[i] / 2; j++){
				char a = 'A' + i;
				res += a;
			}
		}
	}
	if(counter == 1)
		for(int j = 0; j < letters[charToUse-'A']; j++)
			res += charToUse;
			
	for(int i = 29; i >= 0; i--){
		if(letters[i] != 0 && (letters[i] % 2 == 0)){
			for(int j = 0; j < letters[i] /2 ; j++){
				char a = 'A' + i;
				res += a;
			}
		}
	}
	cout << res << endl;
	return 0;
}
