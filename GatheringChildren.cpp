/*
Idea:
We can have two for loops=> one checks for R and one checks for L
For R, we can loop from the right to the left. Keep track of the index of the last L. If we see a R, we consider R. If we see a L , then we update L index.
For L, we can loop from the left to the right. Keep track of the index of the last R. If we see a L, we consider L. If we see a R, then we update R index.
Consider R:
If the current R is an even number away from the next L, then next L counter ++.  If it is an odd integer away from the next L, then the R before the L counter++.
Consider L:
If the current L is an odd number away from the last R, then the L after the R counter++. If it is an even integer away from the next R, then R counter++.
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string str;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> str;
    
    vector<ll>counter(str.length(), 0);
    ll L_index = str.length()-1;
    //Consider R
    for (ll i = str.length()-1; i >= 0; i--){
        if (str[i] == 'R'){
            if (abs(i - L_index) % 2 == 0) counter[L_index]++;
            else counter[L_index-1]++;
        } else L_index = i;
    }
    ll R_index = 0;
    //Consider L
    for (ll i = 0; i < str.length(); i++){
        if (str[i] == 'L'){
            if (abs(i - R_index) % 2 == 0) counter[R_index]++;
            else counter[R_index+1]++;
        } else R_index = i;
    }
    for (auto i : counter){
        cout << i << " ";
    }
    return 0;
}