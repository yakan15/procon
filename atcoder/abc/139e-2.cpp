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

string make_key(int a, int b){
    return to_string(min(a,b)) + "-" + to_string(max(a,b));
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<set<int> > edges(n*n/2);
    vector<int> max_length[n*n/2]; 
    int idx[n][n]={};
    int a=1;
    rep(i,n){
        rep(j,n){
            if(i<j){idx[i][j]=a++;}
        }
    }
    int prev;
    rep(i,n){
        rep(j,n-1){
            int tmp;
            cin>>tmp;
            int s=min(i,tmp),t=max(i,tmp);
            if(j==0){
                edges[0].insert(idx[s][t]);
            }
            int ss=min(i,prev), tt=max(i,prev);
            edges[idx[ss][tt]].insert(idx[s][t]);
        }
    }



    unordered_map<string, set<string> > hash;
    int prev;
    rep(i,n){
        rep(j,n-1){
            int tmp;
            cin>>tmp;
            tmp--;
            if(j==0){
                hash["0"].insert(make_key(i,tmp));
            }else{
                hash[make_key(i,prev)].insert(make_key(i,tmp));
            }
            prev = tmp;
        }
    }
    DEBUG{
        for(auto x:hash["0"]){
            cout << x << endl;
        }
    }
    unordered_map<string, int> cnt;
    unordered_map<string, bool> visited;
    function<int(string)> solve = [&](string key){
        int res = 0;
        if(cnt.count(key)!=0){
            return cnt.at(key);
        }
        visited[key] = true;
        if(hash.count(key)==0){
            return cnt[key] = 1;
        }
        for(auto x:hash[key]){
            if(visited.count(x)!=0&&cnt.count(x)==0){
                DEBUG{cout << "out " << x << endl;}
                return -1;
            }
            int tmp = solve(x); 
            if(tmp==-1){
                DEBUG{cout << "out " << x << endl;}
                return -1;
            }

            res = max(res,tmp);
        }
        return cnt[key] = res+1;
    };
    int res = solve("0");
    cout << (res == -1 ? res : res-1) << endl;
    return 0;
}
