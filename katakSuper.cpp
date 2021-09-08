#include <bits/stdc++.h>
using namespace std;

long long dp[100010], h[100002];

long long sqr (long long x) {
    return x * x;
}

long long f(int n) {
    if(n == 1) {
        return dp[n] = 0;
    }
    if(dp[n] == -1){
        long long biasa = f(n-1) + sqr(h[n] - h[n-1]) ;
        if(n > 2) {
            long long super = f(n-2) + 3 * sqr(h[n] - h[n-2]);
            dp[n] = min (biasa, super);
        }
        else {
            dp[n] = biasa;
        }
    }
    return dp[n];
}
int main () {
    int n; 
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    cout<< f(n) <<endl;
    // for(int i= 1; i <= n; i++) cout<< dp [i] << " ";
}