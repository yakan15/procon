#include <bits/stdc++.h>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
int dfs(string n,int N){
    int res=0;
    if (stoll(n)>N)return 0;
    bool flg=true;
    for (auto &&it : {'3','5','7'}){
        if(n.find(it)==string::npos)flg=false;
    }
    res = flg;

    for(auto &&it : {'3','5','7'}){
        res +=dfs(n+it,N);
    }
    return res;
}

int main(void){
    int n;
    cin >> n;
    int res;
    res=dfs("0",n);
    cout << res << endl;
    return 0;

}