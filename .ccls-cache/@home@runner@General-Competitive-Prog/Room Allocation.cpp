#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 2e5;

int ans[MAXN];
vector<pair<pair<ll,ll>, int>>vec(MAXN); // {{arrival, departure}, original index}

int n;

priority_queue<pair<ll, int>>min_pq; // {departure time, roomID}

int roomID = 0;
int k = 0;

int main() {
    cin >> n;
    vec.resize(n);
    
    for (int i=0; i<n; i++){
        ll a, b; cin >> a >> b;
        // Store the original index (for accessing ans) since we are going to sort by arrival time later
        vec[i] = {{a, b}, i};
    }
    
    // sort by arrival time
    sort(vec.begin(), vec.end());
    
    for (int i=0; i<n; i++){
        if (min_pq.empty()){
            roomID++;
            // negative departure time --> min priority queue
            min_pq.push({-vec[i].first.second, roomID}); 
             // store the room ID in the original index
            ans[vec[i].second] = roomID;
        } else {
            // convert the earliest departure time back to positive
            pair<ll, int>earliestDeparture = min_pq.top();
            if (-earliestDeparture.first < vec[i].first.first) {
                min_pq.pop();
                ans[vec[i].second] = earliestDeparture.second;
                min_pq.push({-vec[i].first.second, earliestDeparture.second});
            } else {
                roomID++;
                min_pq.push({-vec[i].first.second, roomID});
                ans[vec[i].second] = roomID;
            }
        }
        k = max(k, int(min_pq.size()));
    }
    cout << k << endl;
    for (int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
