#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define f first
#define s second
int N;
int ans = INT32_MAX;
vector<pair<int,int>>coords;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    cin >> N;

    for (int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        coords.pb({x, y});
    }
    
    //sweep line algorithm
    sort(coords.begin(), coords.end());
    for (int i = 0; i < N-1; i++){
        int x = coords[0].f; 
        int y = coords[i].s; 
        int lower_left = 0, lower_right = 0, upper_left = 0, upper_right = 0;
        for (pair<int,int>coord : coords){
            if (coord.s > y){
                if (coord.f > x) upper_right++;
                else upper_left++;
            } else{
                if (coord.f > x) lower_right++;
                else lower_left++;
            }
        }
        ans = min(ans, max({lower_left, upper_left, lower_right, upper_right}));
        for (int j = 1; j < N-1; j++){
            if (coords[j].s > y){
                upper_left++;
                upper_right--;
            } else{
                lower_left++;
                lower_right--;
            }
            ans = min(ans, max({lower_left, upper_left, lower_right, upper_right}));
        }
    }
    cout << ans;
    return 0;
}
