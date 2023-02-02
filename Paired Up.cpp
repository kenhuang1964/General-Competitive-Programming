#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
ll ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    cin >> N;
    vector<pair<ll,ll>>vec(N);
    for (ll i = 0; i < N; i++){
        ll a, b; cin >> a >> b;
        vec[i] = {b, a};
    }
    sort(vec.begin(), vec.end());
    ll left_pointer = 0;
    ll right_pointer = N-1;
    while (left_pointer <= right_pointer){
        ans = max(ans, vec[left_pointer].first + vec[right_pointer].first);
        //update cow count
        ll subtract_amount = min(vec[left_pointer].second, vec[right_pointer].second);
        vec[left_pointer].second -= subtract_amount;
        vec[right_pointer].second -= subtract_amount;
        if (vec[left_pointer].second <= 0) left_pointer++;
        if (vec[right_pointer].second <= 0) right_pointer--;
    }
    cout << ans;
    return 0;
}