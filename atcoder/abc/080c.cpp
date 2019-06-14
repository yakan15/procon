#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void dfs(vector<int> &v,int a){
    int tmp;
    for(int i=1;i<=4;i++){
        tmp=a;
        tmp *= 10;
        tmp += i;
        if(tmp>11111){
            v.push_back(tmp);
        }else if(tmp!=11111){
            dfs(v, tmp);
        }
    }

}

int main(void) {
    int n;
    cin >> n;
    vector<vector<int> > v(n,vector<int>(10,0)),p(n,vector<int>(11,0));
    int tmp;
    rep(i,n){
        rep(j,10){
            cin >> tmp;
            v[i][j]=tmp;
        }
    }
    rep(i,n){
        rep(j,11){
            cin >> tmp;
            p[i][j]=tmp;
        }
    }
    bool flg;
    int res=INT_MIN,value;
    vector<int> lst;
    vector<int> ncnt(n,0);
    dfs(lst,0);
    // cout << lst.size() << endl;
    // rep(i,lst.size()){
    //     cout << lst[i] << endl;
    // }
    int e;
    int amari;
    rep(i,lst.size()){
        e=lst[i];
        value=0;
        rep(j,5){
            amari = e % 10;
            e = e / 10;
            rep(k,n){
                if(amari==4)ncnt[k] +=v[k][2*j]+v[k][2*j+1];
                else if(amari==3) ncnt[k] += v[k][2*j];
                else if(amari==2) ncnt[k] += v[k][2*j+1];
            }
        }

        rep(j,n){
            // cout << ncnt[j] << endl;
            value += p[j][ncnt[j]];
        }
        if(value>=res)res=value;
        ncnt.clear();
        ncnt= vector<int>(n,0);
    }
    cout << res << endl;
    return 0;
}