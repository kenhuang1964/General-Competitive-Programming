#include <bits/stdc++.h>

using namespace std;

int n, k, d;

const int mxN = 3e5+10;
queue<int>q;
vector<int>adj[mxN];
bool visited[mxN];
vector<pair<int,int>>roads;
int dist[mxN];
map<pair<int,int>, bool>visitedRoad;
vector<int>unusedRoads;

int ans = 0;

int main() {
    cin >> n >> k >> d;
    for (int i = 0; i < k; i++){
        int a; cin >> a;
        q.push(a);
        visited[a] = true;
    }
    
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        roads.push_back({a, b});
    }
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u: adj[v]){
            if (!visited[u] && dist[v] + 1 <= d) {
                visited[u] = true;
                q.push(u);
                dist[u] = dist[v] + 1;
                visitedRoad[{v, u}] = true;
                visitedRoad[{u, v}] =true;
            }
        }
    }
    
    for (int i = 0; i < n-1; i++){
        int u = roads[i].first;
        int v = roads[i].second;
        if (!visitedRoad[{u, v}] && !visitedRoad[{v, u}]) {
            ans++;
            unusedRoads.push_back(i+1);
        }
    }
    cout << ans << endl;
    for (int i : unusedRoads){
        cout << i << " ";
    }
    return 0;
}