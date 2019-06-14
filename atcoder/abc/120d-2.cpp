#include <bits/stdc++.h>
#define rep(i,n) for(ull (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull root(vector<ull> &p, ull i){
    // DEBUG{cout << "i : " << i << "p[i-1] : " << p[i-1] << endl;}
    if(p[i]==i)return i;
    p[i]=root(p,p[i]);
    return p[i];
}

int main(void) {
    ull n,m,e1,e2;
    cin >> n >> m;
    vector<pair<ull, ull> > e;
    vector<ull> cnt(n,1);
    vector<ull> res(m,0);
    vector<ull> parents;
    rep(i,m){
        // pair<ull, ull> tmp;
        // tmp = pair<ull, ull>();
        cin >> e1 >> e2;
        // DEBUG{printf("(%llu %llu)",e1,e2);}
        // scanf("%d %d\n", &e[i].first, &e[i].second);
        // cin >> e[i].first >> e[i].second;
        e.push_back(make_pair(e1,e2));
    }
    DEBUG{
        rep(i,m){
            printf("(%llu %llu)\n",e.at(i).first, e[i].second);
        }
    }
    rep(i,n){
        parents.push_back(i);
    }
    // DEBUG {printf("test\n");}
    ull mm = (n*(n-1))/2;
    DEBUG {cout << "mm=" << mm << endl;}
    rep(i,m){
        pair<ull, ull> tmp; 
        // ull tmp_first = e[m-i-2].first, tmp_second=e[m-i-2].second;
        // DEBUG {printf("tmp : (%llu, %llu)\n",tmp.first,tmp.second);}
        // DEBUG {printf("e : (%d, %d)\n",e[i].first,e[i].second);}

        if(i==0){
            DEBUG{cout << "i=0" << endl;}
            // colors[tmp.first]=cnt;
            // colors[tmp.second]=cnt;
            res[i]=mm;
            continue;
        }
        tmp = e[m-i];
        ull pf=root(parents,tmp.first-1),ps=root(parents,tmp.second-1);
        if(pf!=ps){
            // DEBUG{printf("union : %llu %llu",tmp.first, tmp.second);}
            

            ull a = cnt[pf]*cnt[ps];
            parents[pf]=ps;
            cnt[ps]+=cnt[pf];
            res[i]=res[i-1]-a;
            // change_parent(parents, children, tmp.first, tmp.second);
        }else{
            res[i]=res[i-1];
        }
        // cnt++;
    }
    DEBUG{cout << "roop out" << endl;}
    rep(i,m){
        cout << res[m-i-1] << endl;
    }
    return 0;
}