#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--){
        ll n; cin >> n;
        vector<ll>vec(n);
        for (ll&i : vec) cin >> i;
        sort(vec.begin(), vec.end());
        ll p1 = 0, p2 = n-1;
        vector<ll>ans(n);
        ll idx = n-1;
        if (n % 2 == 0){
            while (p1 < p2){
                ans[idx--] = vec[p2--];
                ans[idx--] = vec[p1++];
            }
        }
        else {
            while (p1 <= p2){
                if (p1 == p2){
                    ans[idx] = ans[p1];
                    break;
                } else{
                    ans[idx--] = vec[p2--];
                    ans[idx--] = vec[p1++];
                }
            }
        }
        for (auto i : ans){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}