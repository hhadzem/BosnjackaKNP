#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

void solve(){
    int n; long long int k;
    scanf("%d %lld", &n, &k);
    vector<long long int> apoeni;
    for(int i = 0; i < n; i++){
        int temp; scanf("%d", &temp);
        apoeni.push_back(pow(10, temp));
    }
    
    k = k + 1;
    vector<int> lim;
    for(int i = 0; i < n-1; i++)
        lim.push_back(apoeni[i+1]/apoeni[i]-1);
    
    long long int res = 0;
    int counter = 0;
    while(k > 0 && counter < n - 1){
        if(lim[counter] > k){
            res += apoeni[counter] * k;
            printf("%lld\n", res);
            return;
        }
        res += apoeni[counter] * lim[counter];
        k -= lim[counter];
        counter++;
    }
    
    if(k > 0)
        res += k * apoeni[counter];
    printf("%lld\n", res);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}