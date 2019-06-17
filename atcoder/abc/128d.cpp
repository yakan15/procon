#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n,k;
    cin >> n >> k;
    vector<int> q;
    priority_queue<int, vector<int>, greater<int> > pq; 
    rep(i,n){
        int tmp;
        cin >> tmp;
        q.push_back(tmp);
    }
    int res=INT_MIN;
    rep(i,k+1){
        for(int j=0;i+j<=k;j++){
            for(int l=0;i+j+l<=k;l++){
                int tmp=0;
                rep(ii,i){
                    if(ii>=n)break;
                    tmp += q[ii];
                    pq.push(q[ii]);
                }
                rep(ii,j){
                    if(n-1-ii>=n)continue;
                    if(n-1-ii<i)break;
                    tmp += q[n-1-ii];
                    pq.push(q[n-1-ii]);
                }
                rep(ii,l){
                    if(pq.empty()||pq.top()>=0)break;
                    tmp -= pq.top();
                    pq.pop();
                }
                if(tmp>res){
                DEBUG{printf("%d %d %d %d\n", i, j, l, tmp);}
                    res=tmp;
                }
                while (!pq.empty())pq.pop();
            }
        }
    }
    cout << res << endl;
    return 0;
}
