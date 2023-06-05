#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 1e18

vector<ll>dist;
vector<vector<pair<ll,ll>>>adj;
ll n, m;

void dijkstra() {
    dist[1] = 0;
    
    priority_queue<pair<ll,ll>, 
    vector<pair<ll, ll>>, 
    greater<pair<ll,ll>>>pq; // {dist, node} - use greater<> for min heap
    
    pq.push({0,1});
    while (!pq.empty()) {
        ll node = pq.top().second;
        ll currentDistance = pq.top().first;
        pq.pop();
        
        if (dist[node] < currentDistance) continue;
        for (auto edge: adj[node]) {
            ll neighborDistance = edge.first;
            ll neighborNode = edge.second;
            
            if (dist[neighborNode] <= neighborDistance+currentDistance) continue;
            else {
                dist[neighborNode] = neighborDistance+currentDistance;
                pq.push({dist[neighborNode], neighborNode});
            }
        }
        
    }
}

int main() {
    cin >> n >> m;
    dist.resize(n+1, INF);
    adj.resize(n+1);
    
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    
    dijkstra();
    for (int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    return 0;
}
