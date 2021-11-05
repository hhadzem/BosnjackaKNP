#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
void solve(){
    long long int ur, k;
    scanf("%lld %lld", &ur, &k);
    
    long long int h = 0, br = 1;
    while(br <= k && br < ur){
        br *= 2;
        h++;
    }
    long long int rem = (ur - br + (k-1))/k;
    printf("%lld\n", h + max(rem, 0LL));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}