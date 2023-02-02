#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", st)
    int n; cin >> n;
    vector<int>vec(n);
    for (int&i : vec){
        cin >> i;
    }
    sort(vec.begin(), vec.end(), cmp);
    ll ans= 0;
    for (int i = 0; i < n; i++){
        if (ans > vec[i]) break;
        ans ++;
    }
    cout << ans << endl;
}