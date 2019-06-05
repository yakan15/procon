#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {

    vector<vector<int> > v;
    v.assign(3,vector<int>(3,0));
    rep(i,3){
        rep(j,3){
            int tmp;
            cin >> tmp;
            v[i][j]=tmp;
        }
    }
    int sub;
    rep(i,3){
        sub = min(v[i][0],min(v[i][1],v[i][2]));
        v[i][0] -=sub;
        v[i][1] -=sub;
        v[i][2] -=sub;
    }
    
    rep(i,3){
        sub = min(v[0][i],min(v[1][i],v[2][i]));
        v[0][i] -=sub;
        v[1][i] -=sub;
        v[2][i] -=sub;
    }
    rep(i,3){
        rep(j,3){
            if(v[i][j]!=0)
            {cout << "No" << endl;
            return 0;}
        }
    }
    cout << "Yes" << endl;
    return 0;
}