#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

using namespace std;

int main(void) {
    int n;
    cin >> n;
    unsigned long long res=0;
    vector<unsigned long long> v={0,0,0,0,0};
    string tmp;
    rep(i,n){
        cin >> tmp;
        char f = tmp[0];
        if(f=='M'){v[0]++;}
        else if(f=='A'){v[1]++;}
        else if(f=='R'){v[2]++;}
        else if(f=='C'){v[3]++;}
        else if(f=='H'){v[4]++;}
    }
    rep(i,5){
        rep(j,5){
            // if(i>=j)continue;
            rep(k,5){
                
                // if(j>=k)continue;
                if(i<j&&j<k){
                    // cout << i << j << k << endl;
                    res += v[i]*v[j]*v[k];
                    
                    }
            }
        }
    }
    cout << res << endl;
    return 0;
}