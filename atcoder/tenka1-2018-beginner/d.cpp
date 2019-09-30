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
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    int cnt=1;
    while((cnt-1)*cnt/2<n){cnt++;}
    if(cnt*(cnt-1)!=2*n){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << cnt << endl;
    vector<vector<int>> S(cnt,vector<int>());
    int num=1;
    rep(i,cnt){
        repr(j,i+1,cnt){
            S[i].push_back(num);
            S[j].push_back(num);
            num++;
        }
    }
    rep(i,cnt){
        cout << cnt-1 << " ";
        rep(j,cnt-1){
            cout << S[i][j];
            if(j!=cnt-2){
                cout << " ";
            }else{
                cout << endl;
            }
        }
    }
    return 0;
}
