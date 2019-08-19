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
    int n,x;
    cin>>n>>x;
    if(n==2){
        if(x==2){
            printf("Yes\n1\n2\n3\n");
        }else{
            printf("No\n");
        }
        return 0;
    }
    if(x==1||x==2*n-1){
        printf("No\n");
    }else{
        printf("Yes\n");
        int out[2*n]={};
        set<int> st;
        st.insert(x);
        out[n] = x;
        if(x==2){
            out[n-1]=x-1;
            st.insert(x-1);
        }else{
            out[n-1]=x+1;
            st.insert(x+1);
            out[n-2]=x-1;
            st.insert(x-1);
            out[n+1]=x-2;
            st.insert(x-2);
        }
        int cnt = 1;
        int val = 1;
        while(cnt<=2*n-1){
            while(st.find(val)!=st.end()){
                val++;
            }
            while(cnt<2*n&&out[cnt]!=0){
                cnt++;
            }
            if(cnt==2*n){break;}
            out[cnt]=val;
            st.insert(val);
            val++;
            cnt++;
        }
        for(int i=1;i<=2*n-1;i++){
            printf("%d\n",out[i]);
        }
    }
    return 0;
}
