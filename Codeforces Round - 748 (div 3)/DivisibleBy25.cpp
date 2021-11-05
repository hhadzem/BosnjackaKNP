#include<stdio.h>
#include<algorithm>
 
using namespace std;
 
void solve(){
    long long int N;
    long long int kopija = N;
    scanf("%lld", &N);
    int rje = 1000, brojac = 0;
    int counter = 0;
    
    brojac = 0;
    kopija = N;
    // tražimo 50 ili 00
    while(kopija != 0){
        counter++;
        if(brojac == 0 && kopija % 10 == 0){
            brojac++;
        }
        else if(brojac == 1 && (kopija % 10 == 5 || kopija % 10 == 0) ){
            rje = min(rje, counter - 2);
            break;
        }
        kopija /= 10;
    }
    
    brojac = 0;
    kopija = N;
    counter = 0;
    // tražimo 25 ili 75
    while(kopija != 0){
        counter++;
        if(brojac == 0 && kopija % 10 == 5){
            brojac++;
        }
        else if(brojac == 1 && (kopija % 10 == 2 || kopija % 10 == 7) ){
            rje = min(rje, counter - 2);
            break;
        }
        kopija /= 10;
    }
    printf("%d\n", rje);
}
 
int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        solve();
    return 0;
}