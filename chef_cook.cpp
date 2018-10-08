#include<iostream>
using namespace std;
#define ll long long

int main(){
    ll T,p1,p2,k,d,n;
    cin >> T;
    n = T;
    string a[T];
    while(T--){
        cin >> p1 >> p2 >> k;
        d = (p1+p2)/k;
        if((d%2)==0) a[n-T-1] = "CHEF";
        else a[n-T-1] = "COOK";
    }
    T = n;
    while(T--){
        cout << a[n-T-1] <<endl;
    }
    return 0;
}
