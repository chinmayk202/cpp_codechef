#include<iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
#define ll long long
#define f(i,m,n) for(int i = m; i<n;i++)

ll* find_maxes(ll* a,ll n){
    ll max=0,smax=0,maxi=0,smaxi=0;
    ll *mx = (ll*)malloc(4*sizeof(ll));
    if(a[0] >= a[1]){
        max = a[0];
        maxi = 0;
        smaxi = 1;
        smax = a[1];
    }
    else{
        max = a[1];
        smax = a[0];
        smaxi = 0;
        maxi = 1;
    }
    f(i,2,n){
        if(a[i]>smax){
            if(a[i]>max){
                smax = max;
                smaxi = maxi;
                max = a[i];
                maxi = i;
            }
            else{
                smax = a[i];
                smaxi = i;
            }
        }
    }
    mx[1] = maxi;
    mx[0] = max;
    mx[3] = smaxi;
    mx[2] = smax;
    return mx;
}

ll second_max(ll* a,ll n,ll p){
    ll tmaxi=0;
    f(i,1,n){
        if(a[i] != a[p]){
            if(a[i] > a[tmaxi]){
                tmaxi = i;
            }
        }
    }
    return tmaxi;
}

int main(){
    ll N,M,T,min_temp;
    ll* maxes;
    cin >> N >> M;
    ll A[N],B[N],P[N];
    T = N;
    while(T--){
        cin >> A[N-T-1];
    }
    T = N;
    while(T--){
        cin >> B[N-T-1];
    }
    //auto start = high_resolution_clock::now();
    T = N;
    maxes = find_maxes(A,N);
    //cout << maxes[0] << endl << maxes[1] << endl;
    f(i,0,T){
        P[i] = A[i] * B[i];
        //cout << P[i] << endl;
    }
    while(M > 0){
        /*f(i,0,T){
            P[i] = A[i] * B[i];
            //cout << P[i] << endl;
        }*/
        maxes = find_maxes(P,N);

        //cout << A[maxes[1]] << endl << maxes[1] << endl;
        while(A[maxes[1]]*B[maxes[1]] >= A[maxes[3]]*B[maxes[3]]){
            if(M!=0){
                if(A[maxes[1]] <= A[maxes[3]]){
                    A[maxes[1]]--;
                    P[maxes[1]] = A[maxes[1]] * B[maxes[1]];
                    M--;
                }
                else{
                    min_temp = min(M,(A[maxes[1]]-A[maxes[3]]+1));
                    A[maxes[1]] -= min_temp;
                    P[maxes[1]] = A[maxes[1]] * B[maxes[1]];
                    M -= min_temp;
                }
            }
            else break;
        }
        //maxes[1] = maxes[3];
        //maxes[3] = second_max(P,N,maxes[1]);

    }
    /*f(i,0,T){
        P[i] = A[i] * B[i];
        //cout << P[i] << endl;
    }
    maxes = find_maxes(P,N);
    cout << maxes[0] << endl;*/
    if(A[maxes[3]]*B[maxes[3]] > A[maxes[1]]*B[maxes[1]]){
        cout << A[maxes[3]]*B[maxes[3]] << endl;
    }
    else cout << A[maxes[1]]*B[maxes[1]] << endl;
    /*auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;*/
    return 0;
}
