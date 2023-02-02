#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, C;
ll ans = INT32_MAX;
vector<ll>vec;
bool works(ll K){
    /*
    Simulate if our conditions are met assuming that K is the max difference between time

    - We know that once the difference between the start and end of an interval of cows is greater than K or if the number of cows in the group is greater than C, then we can create a new group of cows, so num_bus++
    - We need the first cow of any interval because that's our starting point
    */
    //initialize with 1 bus filled with 1 cow which is the first cow
    ll num_bus = 1;
    ll num_cows_on_bus = 0;
    ll first_interval_time = vec[0];
    for (auto cow_time : vec){ //cow_time is the arrival time for each cow
        num_cows_on_bus++; //now we have some cows 
        if (cow_time - first_interval_time > K || num_cows_on_bus > C){
            //create a new bus
            num_bus++;
            num_cows_on_bus=1; //restart to 1 cow on bus
            first_interval_time = cow_time; //now the first_interval_cow is cow_time because it is starting the new bus
        }
        if (num_bus > M) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie();
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> N >> M >> C;
    vec.resize(N);
    for (ll&i : vec) cin >> i;
    sort(vec.begin(), vec.end());

    ll lo = 0;
    ll hi = vec[N-1] - vec[0]; //the max search range is the max difference between the elements
    while (lo <= hi){
        /*
        We are binary searching for the optimal time difference that works with the number of bus we have
        */
        ll mid = lo + (hi - lo)/2;
        //we need to check if mid works
        if (works(mid)){ //see if mid works as K
            //if the number of cows alone + number of intervals that have differences less than mid is less than or equal to M (number of buses)
            hi = mid-1;
            ans = mid;
        } else{
            lo = mid+1;
        }
    }
    cout << ans;
    return 0;
}