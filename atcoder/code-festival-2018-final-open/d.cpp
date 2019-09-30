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

inline int char_to_idx(char c){
    return (c < 'a' ? c-'A' : c-'a'+26);
}

inline char itoc(int i){
    return char(i<26 ? i+'A' : i-26+'a');
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<string> a(n);rep(i,n){cin>>a.at(i);}
    vector<vector<int>> input(n,vector<int>());
    rep(i,n){
        rep(j,a[i].size()){
            input[i].push_back(char_to_idx(a[i][j]));
        }
    }
    DEBUG{
        rep(i,n){
            rep(j,a[i].size()){
                cout << itoc(input[i][j]);
            }
            cout << endl;
        }
    }
    int cnt[52][52][52]={};
    rep(i,n){
        int back[52]={},front[52]={};
        bool in[52][52][52]={};
        int sz = a[i].size();
        repr(j,1,sz){
            back[input[i][j]]++;
        }
        repr(j,1,sz-1){
            front[input[i][j-1]]++; 
            back[input[i][j]]--;
            rep(x,52){
                rep(y,52){
                    if(front[x]==0||back[y]==0||in[x][input[i][j]][y]){continue;}
                    in[x][input[i][j]][y]=true;
                    cnt[x][input[i][j]][y]++;
                }
            }
        }
    } 
    int mx = 0;
    string res;
    rep(i,52){
        rep(j,52){
            rep(k,52){
                if(mx<cnt[i][j][k]){
                    res = {itoc(i), itoc(j), itoc(k)};
                    mx=cnt[i][j][k];
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
