#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M;
vector<ll>a;
vector<ll>b;
map<pair<ll,ll>,bool>m; //to check if a given range exists
ll ans = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
    cin >> N >> M;
    for (ll i = 0; i < M; i++){
        ll first, second; cin >> first >> second;
        m[{first, second}] = true;
        a.push_back(first);
        b.push_back(second);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    //now we can search for the optimal D
    ll lo = 1;
    ll hi = 1e18;
    while (lo <= hi){
        ll mid = lo + (hi-lo)/2;
        ll cow_counter = 1; //count the number of cows we placed
        ll current_position = *lower_bound(a.begin(), a.end(), 0); //the first position with grass
        while (true){
            //we run this while loop until we are at the end
            current_position += mid; //next pos at least mid away from current pos
            //check if we are within a range of grass
            ll lower_interval = *(upper_bound(a.begin(), a.end(), current_position) -1);
            ll upper_interval = *lower_bound(b.begin(), b.end(), current_position);
            if (m[{lower_interval, upper_interval}]){
                //we are within the range of grass
                cow_counter++;
            } else{
                auto next_position = upper_bound(a.begin(), a.end(), current_position);
                if (next_position == a.end()) break; //doesn't exist
                current_position = *next_position; //we update our position to the next a
                cow_counter++;
            }
        }
        if (cow_counter >= N){
            //this D works
            ans = max(ans, mid);
            lo = mid+1;
        } else{
            //this mid doesnt work
            hi = mid-1;
        }
        //cout << "current mid: " << mid << " current cow_counter: " << cow_counter << endl;
    }
    cout << ans;
    return 0;
}
