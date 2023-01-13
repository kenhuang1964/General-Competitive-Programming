#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K, B;
ll ans = INT32_MAX;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    cin >> N >> K >> B;
    vector<ll>dp(N+1, 0);
    //first set those broken positions to 1
    for (int i = 0; i < B; i++){
        int index; cin >> index;
        dp[index] = 1;
    }
    //we can loop through again and add the current term with the previous term
    for (int i = 1; i < N+1; i++){
        dp[i] += dp[i-1];
    }
    //we can loop through the ranges i to i+K inclusively and get the number of broken signs. Try to get the min.
    for (int i = 0; i < N-K+1; i++){
        ans = min(ans, dp[i+K-1]-dp[i]);
    }
    cout << ans;
    return 0;
}