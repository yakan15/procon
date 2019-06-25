#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int N;
    string S;
    cin >> S;
    N=S.size();
    vector<int> sa,sb;
    rep(i,N){
        sa.push_back(int(S[i]=='1'));
        sb.push_back(int(S[i]=='1'));
    }
    DEBUG{
        rep(i,N){
            cout << sa[i] << endl;
        }
    }
    int cnta=0,cntb=1; 
    sb[0]=1-sb[0];
    for(int i=1;i<N;i++){
        if(sa[i]==sa[i-1]){
            sa[i]=1-sa[i];
            cnta++;
        }
        if(sb[i]==sb[i-1]){
            sb[i]=1-sb[i];
            cntb++;
        }
    }
    cout << min(cnta,cntb) << endl;
    return 0;
}
