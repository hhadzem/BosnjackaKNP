#include<stdio.h>
#include<algorithm>
 
using namespace std;
int s(int a, int b, int c){
    return max(0, max(b,c)-a+1);
}
 
void solve(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d %d %d\n", s(a, b, c), s(b, a, c), s(c, a, b));
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        solve();
    return 0;
}