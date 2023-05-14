#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, m, r;

struct Sell {
    ll price;
    ll gallons;
    
    Sell(ll gallons, ll price) {
        this->gallons = gallons;
        this->price = price;
    }
};
bool cmpSell(Sell p, Sell q) {
    if (p.price == q.price) {
        return p.gallons > q.gallons;
    }
    return p.price > q.price;
}

bool cmp(ll p, ll q) {
    return p > q;
}

vector<ll>rent;
vector<ll>cows;
vector<Sell>sellMilk;

map<ll, ll>cowSellValue;

ll ans = 0;

int main() {
    cin >> n >> m >> r;
    
    for (int i = 0; i < n; i++){
        ll produce; cin >> produce;
        cows.push_back(produce);
    }
    
    for (int i = 0; i < m; i++){
        ll gallons, price; cin >> gallons >> price;
        sellMilk.push_back(Sell(gallons, price));
    }
    
    for (int i = 0; i < r; i++){
        ll rentPrice; cin >> rentPrice;
        rent.push_back(rentPrice);
    }
    
    sort(rent.begin(), rent.end(), cmp);
    sort(cows.begin(), cows.end(), cmp);
    sort(sellMilk.begin(), sellMilk.end(), cmpSell);
    
    ll currentSell = 0;
    ll currentCow = 0;
    
    while (currentCow < n && currentSell < m) {
        while (cows[currentCow] > 0){
            if (cows[currentCow] <= sellMilk[currentSell].gallons) {
                // if the current cow's milk production is less than the number of gallons the farmer is willing to buy, then we sell all and subtract from the farmer's gallons.
                cowSellValue[currentCow] += cows[currentCow] * sellMilk[currentSell].price;
                
                // the farmer bought the milk so the amount of milk he can buy has decreased by the amount of milk he bought
                sellMilk[currentSell].gallons -= cows[currentCow];
                
                // sold all the cow's milk
                cows[currentCow] = 0;
            } else {
                // else, we keep going until the currentCow's milk production is all used up.
                
                // Cow's milk production must be greater, which means we must use up all of the current farmer's milk buying.
                cowSellValue[currentCow] += sellMilk[currentSell].gallons * sellMilk[currentSell].price;
                
                // sell all the milk and keep track of what is left
                cows[currentCow] -= sellMilk[currentSell].gallons; 
                // bought all the milk
                sellMilk[currentSell].gallons = 0; 
                // move to the next farmer since the current farmer bought all he could.
                currentSell++;
            }
            if (currentSell >= m) {
                break;
            }
        }
        currentCow++;
    }
        
    // for (int i = 0; i < n; i++) {
    //     cout << "Cow " << i << ": " << cowSellValue[i] << endl;
    // }

    
    currentCow =n-1;
    ll currentRent = 0;
    while (currentCow >= 0) {
        if (currentRent < r) {
            if (cowSellValue[currentCow] < rent[currentRent]) { 
                ans+=rent[currentRent];
                currentRent++;
            }  else {
                ans += cowSellValue[currentCow];
            }
        }
        else {
            ans += cowSellValue[currentCow];
        }
        currentCow--;
    }
    cout << ans;
    return 0;
}
