#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;



int main(void) {
    int n,c;
    cin >> n >> c;
    int imos[100005]={};
    vector<vector<pair<int, int>>> record(c,vector<pair<int,int>>());
    vector<vector<pair<int, int>>> record_2(c,vector<pair<int,int>>());
    rep(i,n){
        int ts,tt,tc;
        cin >> ts >> tt >> tc;
        record[tc-1].push_back(make_pair(ts,tt));
    }
    rep(i,c){
        sort(record[i].begin(),record[i].end());
        int cur=0;
        while(cur<record[i].size()){
            int from=record[i][cur].first;
            while(cur+1<record[i].size()&&record[i][cur].second==record[i][cur+1].first)cur++;
            record_2[i].push_back(make_pair(from,record[i][cur].second));
            cur++;
        }
    }
    rep(i,c)rep(j,record_2[i].size()){
        int from = record_2[i][j].first;
        int to = record_2[i][j].second;
        imos[from-1]++;
        imos[to]--;
    }
    int res=0,tmp=0;
    rep(i,100005){
        tmp+=imos[i];
        res=max(res,tmp);
    }
    cout << res << endl;
    return 0;
}
