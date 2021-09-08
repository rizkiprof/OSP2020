#include <bits/stdc++.h>
using namespace std;

int N, K;
long long jarak[100002];
int binser(long long target) {
    int L = 0;
    int R = N;
    while(L < R) {
        int mid = (L + R) / 2;
        if(target == jarak[mid]) {
            return mid;
        }
        else if(target < jarak[mid]) {
            if(target >= jarak[mid-1] ){
                return mid-1;
            }
            else {
                R = mid - 1;
            }
        }
        else {
            if(target < jarak[mid+1] ){
                return mid;
            }
            L = mid + 1;
        }
    }
    return (L + R) / 2;
}

int main () {
    cin >> N >> K;
    long long tmp;
    for(int i = 1; i<= N; i++){
        cin >> tmp;
        jarak[i] = jarak[i-1] + tmp;
    }
    
    for(int i = 1; i<= K; i++){
        cin >> tmp;
        cout << binser(tmp) <<endl;
    }
    
}