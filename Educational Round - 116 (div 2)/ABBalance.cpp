/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include<vector>
using namespace std;

int solveSimple(string s){
    int ab = 0, ba = 0;
    int l = s.length();
    for(int i = 0; i < l - 1; i++)
        if(s[i] != s[i+1])
            if(s[i] == 'a') ab++;
            else ba++;
    return abs(ab - ba);
}
char flip(char a){
    if(a == 'a') return 'b'; 
    return 'a';
}

void solve(){
    string s; 
    cin >> s;
    int l = s.length();
    vector<string> helpers;
    // Isti
    helpers.push_back(s);
    // Zamijeni samo prvo
    string t = s; t[0] = flip(t[0]);
    helpers.push_back(t);
    // Zamijeni samo zadnje
    t[0] = flip(t[0]); t[l-1] = flip(t[l-1]); 
    helpers.push_back(t);
    // Zamijeni i prvo i zadnje
    t[0] = flip(t[0]);
    helpers.push_back(t);
    for(unsigned int i = 0 ; i < helpers.size(); i++){
        if(solveSimple(helpers[i]) == 0){
            cout << helpers[i] << endl;
            return;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    while(n--)
        solve();
    return 0;
}
