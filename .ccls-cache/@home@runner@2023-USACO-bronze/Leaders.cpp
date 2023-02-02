#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll N; cin >> N;
    string str; cin >> str;
    int first_G = 0;
    int first_H = 0;
    int last_G = 0;
    int last_H = 0; 
    bool G_occur = false;
    bool H_occur = false;
    vector<pair<ll, ll>>ranges;
    for (int i = 0; i < N; i++){
        int a; cin >> a;
        if (G_occur == false && str[i] == 'G'){
            first_G = i;
            G_occur = true;
        } else if (H_occur == false && str[i] == 'H'){
            first_H = i;
            H_occur = true;
        }
        if (str[i] == 'G'){
            last_G = i;
        } else if (str[i] == 'H'){
            last_H = i;
        }
        ranges.push_back({i, a-1});
    }
    vector<ll>H_ps(N+1, 0);
    vector<ll>G_ps(N+1, 0);
    ll H_counter = 0;
    ll G_counter = 0;
    vector<bool>works(N+2, false);
    for (int i = 1; i <= N; i++){
        if (str[i-1] == 'G'){
            if (ranges[i-1].first <= first_G && ranges[i-1].second >= last_G){
                G_ps[i] = G_ps[i-1] + 1;
                works[i-1] = true;
            } else{
                G_ps[i] = G_ps[i-1];
            }
            H_ps[i] = H_ps[i-1];
        } else{
            if (ranges[i-1].first <= first_H && ranges[i-1].second >= last_H){
                H_ps[i] = H_ps[i-1] + 1;
                works[i-1] = true;
            } else{
                H_ps[i] = H_ps[i-1];
            }
            G_ps[i] = G_ps[i-1];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (works[i]) {
            if (str[i] == 'G'){
                ans += H_ps[N] - H_ps[i+1];
            } else{
                ans += G_ps[N] - G_ps[i+1];
            }
        } else{
            auto range = ranges[i];
            if (str[i] == 'G'){
                ans += H_ps[range.second +1] - H_ps[range.first];
            } else{
                ans += G_ps[range.second + 1] - G_ps[range.first];
            }
        }
    }
    
    // for (auto i : H_ps){
    //     cout << i << endl;
    // }

    cout << ans << endl;
    return 0;
}
