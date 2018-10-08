#include<iostream>
#include<cmath>
#include <chrono>
using namespace std::chrono;
using namespace std;

bool find_exists(long long test,long long *arr, long long begin,long long end){
	for(long long i = begin; i<=end;i++){
		if(test == arr[i]) return 1;
	}
	return 0;
}

bool check_D(long long d,long long* arr, long long test,long long end){
	for(long long m = 1; m<=end; m++){
 		if(abs(arr[m]-test) <= d) return 1;
        }
	return 0;
}

long long gukiz(){
	long long N,K,x,D;
	cin >> N >> K >> x >> D;
	long long p[N];
	for(long long i = 1;i<=K;i++){
        cin >> p[i];
    }
	auto start = high_resolution_clock::now();
	long long xx = x;
        for(long long i = K+1; i<N+1;i++){
                while(xx>0){
                        if(!find_exists(xx,p,1,i-1)){
                                if(check_D(D,p,xx,i-1)){
                                        p[i] = xx;
                                        break;
                                }
                                else{
                                        if(xx==1){
                                                return -1;
                                        }
                                }
                        }

                        else{
                                if(xx != 1) xx--;
                        }
                }
        }
	for(long long n = 2; n<=N;n++){
                if(!check_D(D,p,p[n],n-1)) return -1;
        }

        long long sum=0;
        for(long long i = 1;i<=N;i++){
                sum += p[i];
        }
		auto stop = high_resolution_clock::now();
	    auto duration = duration_cast<microseconds>(stop - start);

	    cout << "Time taken by function: "
	         << duration.count() << " microseconds" << endl;
        return sum;
}

int main(){
	long long T;
	cin >> T;
	long long output[T];
	for(long long i = 0;i<T;i++){
		output[i] = gukiz();
	}
	for(long long i = 0;i<T;i++){
                cout << output[i] << endl;
        }
	return 0;
}
