#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//must be linear or linearithmic solution

//multiple cities with same name can exist but in different states
// MIAMI TX
// MIAMI FL

//DAIN TX
//DALLAS TX
map<pair<string, string>, int>counter;
map<string, bool>seen; //seen a city or not
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    ll N; cin >> N;
    ll ans = 0;
    for (ll i = 0; i < N; i++){
        string city, state_code; cin >> city >> state_code;
        int counted = counter[{state_code, city.substr(0, 2)}];
        if (counted && state_code != city.substr(0, 2)){
            ans+= counted;
        }
        counter[{city.substr(0, 2), state_code}]++;
    }
    cout << ans;
    return 0;
}