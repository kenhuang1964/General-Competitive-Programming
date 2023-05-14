#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAX_M = 1e5;
ll N, M;

vector<ll>adj[MAX_M+2];
vector<vector<ll>>hole_sizes;
vector<ll>current_list;
vector<ll>sorted_list;

ll ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    hole_sizes.resize(N+2, vector<ll>(N+2));
    current_list.resize(N);
    
    for (ll&i : current_list) cin >> i;
    sorted_list = current_list;
    sort(sorted_list.begin(), sorted_list.end());
    
    for (int i = 0; i < M; i++){
        ll a, b, s; cin >> a >> b >> s;
        adj[a].push_back(b);
        adj[b].push_back(a);
        hole_sizes[a][b] = s;
        hole_sizes[b][a] = s;
    }

    ll lo = 0, hi = 1e9;
    while (lo <= hi){
        ll mid = lo + (hi-lo)/2;
        for (int i = 0; i < N; i++){
            
        }
    }
}