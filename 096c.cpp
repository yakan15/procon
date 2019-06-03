#include <bits/stdc++.h>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

bool is_black(char s){
    bool a = (s=='#');
    return a;
}

int main(void){
    int H,W;
    cin >> H >> W;
    vector<vector<char>>v(H,vector<char>(W));
    rep(i,H){
        rep(j,W){
            cin >> v[i][j];
        }
    }
    rep(i,H){
        rep(j,W){
            if (v[i][j]!='#')continue;
            bool flg=false;
            if(i!=0&&v[i-1][j]=='#')flg=true;
            if(j!=0&&v[i][j-1]=='#')flg=true;
            if(i!=H-1&&v[i+1][j]=='#')flg=true;
            if(j!=W-1&&v[i][j+1]=='#')flg=true;
            if (!flg){
                // cout << i  << " " << j << endl;
                cout << "No" << endl;
                return 0;
            }
            // cout << "i: " << i << "j: " << j << endl;
        }
        // printf("test\n");
    }
    // printf("test\n");

    cout << "Yes" << endl;
    return 0;
}
