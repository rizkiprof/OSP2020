#include <bits/stdc++.h>
using namespace std;

struct xx {
    int start, end;
    long long price;
}job[10001];

bool cmp (xx i, xx j) {
    if(i.end != j.end) return i.end < j.end;
    if(i.start != j.start) return i.start < j.start;
    return i.price < j.price;
}

long long dp[10001][10001];

long long f(int n, int H) {
    if(n < 1 || H < 1) {
        return dp[n][H]=0;
    }
    if(dp[n][H] == -1) {
        if(job[n].end <= H) {
            long long ambil = job[n].price + f(n-1, job[n].start);
            long long gakambil = f(n-1, H);
            dp[n][H] = max(ambil, gakambil);
        }
        else {
            dp[n][H] = f(n-1, H);
        }
    }
    return dp[n][H];
}

int main () {
    memset(dp, -1, sizeof(dp));
    int N;
    cin >> N;
    int maxHari = 0;
    for(int i = 1; i <= N; i++) {
        cin >> job[i].start >> job[i].end >> job[i].price;
        maxHari = max(maxHari, job[i].end);
    }
    
    sort(job+1, job+N+1, cmp);

    cout << f(N, maxHari) <<endl;

}