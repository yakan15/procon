#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> slime(1<<n);rep(i,1<<n){cin>>slime.at(i);}
    sort(slime.begin(),slime.end());
    int cur=1;
    vector<int> created;
    created.push_back(slime.at(0));
    slime.pop_back();
    rep(i,n){
        sort(created.begin(),created.end(),greater<int>());
        rep(j,1<<i){
            auto it = lower_bound(slime.begin(), slime.end(), created.at(j));
            it--;
            if(it==slime.begin()){
                cout << "No" << endl;
                return 0;
            }
            created.push_back(*it);
            slime.erase(it);
            cur++; 
        }
    }
    cout << "Yes" << endl;
    return 0;
}
