#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll x, n;
    cin >> x >> n;
    
    multiset<ll> positions;
    multiset<ll> differences;
    
    positions.insert(0);
    positions.insert(x);
    
    differences.insert(x);
    
    for (int i = 0; i < n; i++) {
        ll p;
        cin >> p;
        positions.insert(p);
        
        auto it = positions.find(p);
        
        ll strictlyLess, strictlyGreater = 0;
        
        if (it != positions.begin()) {
            --it;
            strictlyLess = *it;
            ++it;
        } else {
            strictlyLess = *it;
        }
        
        ++it;
        
        if (it != --positions.end()) {
            strictlyGreater = *it;
        } else {
            strictlyGreater = *it;
        }
        
        differences.erase(differences.find(strictlyGreater - strictlyLess));
        differences.insert(p - strictlyLess);
        differences.insert(strictlyGreater - p);
        
        auto lastIter = differences.rbegin();
        ll greatestDifference = *lastIter;
        // differences.erase(next(lastIter).base());
        cout << greatestDifference << " ";
    }
    
    return 0;
}