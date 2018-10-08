#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long T,n,bits,nibs,bytes,N;
    cin >> T;
    N = T;
    long long out[T][3];
    while(T--){
        cin >> n;
        bits = (n-1)/26;
        n = n - (bits*26);
        bits = pow(2,bits);
        if(n>10){
            bytes = bits;
            bits = 0;
            nibs = 0;
        }
        else if(n>2){
            nibs = bits;
            bits = 0;
            bytes = 0;
        }
        else{
            nibs = 0;
            bytes = 0;
        }
        out[N-T-1][0] = bits;
        out[N-T-1][1] = nibs;
        out[N-T-1][2] = bytes;
    }
    T = N;
    while(T--){
        cout << out[N-T-1][0] << " " << out[N-T-1][1] << " "
        << out[N-T-1][2] << endl;
    }
    return 0;
}
