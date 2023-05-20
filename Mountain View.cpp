#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Mountain {
    ll x;
    ll y;
    ll rangeLeft;
    ll rangeRight;
    
    Mountain(ll x, ll y) {
        this->x = x;
        this->y = y;
        
        rangeLeft = x-y;
        rangeRight = x+y;
    }
};

bool cmp(Mountain m1, Mountain m2) {
    return m1.rangeLeft < m2.rangeLeft; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    
    int N; cin >> N;
    
    vector<Mountain>vec;
    int ans = 1;
    
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        vec.push_back(Mountain(x, y));
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    Mountain currentMountain = vec[0];
    for (int i = 1; i < N; i++){
        Mountain nextMountain = vec[i];
        
        // if (nextMountain.x >= currentMountain.x && nextMountain.x <= currentMountain.rangeRight) { // if the next mountain is within the current mountain's right range 
        if (nextMountain.rangeRight > currentMountain.rangeRight) {
            if (nextMountain.y > currentMountain.y - (nextMountain.x - currentMountain.x)) {
                ans++;
                currentMountain = nextMountain;
            }
        }
        else if (nextMountain.x > currentMountain.rangeRight) {
            ans++;
            currentMountain = nextMountain;
        }
    }
    
    cout << ans;
    return 0;
}