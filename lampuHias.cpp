#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector <int> W (26,0);
    for(int i = 0; i < S.length(); i++){
        W[ S[i] -'A' ]++;
    }
    sort(W.begin(), W.end(), greater<int>() );
    int a = W[0], b = W[1], c = W[2]; 
    int hasil;
    if(c >= 1){
        hasil = c*3;
        a -= c;
        b -= c;
        if(a > 0) hasil++;
        if(b > 0) hasil++;
    }
    else {
        hasil = -1;
    }
    cout << hasil ;
}