#include <bits/stdc++.h>
#define rep(i,n) for(ull (i)=0;(i)<(n);(i)++)
const bool debug=true;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull parent(vector<ull> &p, ull i){
    DEBUG{cout << "i : " << i << "p[i-1] : " << p[i-1] << endl;}
    if(p[i-1]==i-1)return i;
    p[i-1]=parent(p,p[i-1])-1;
    return p[i-1];
}

void change_parent(vector<ull> &parents, vector<set<ull> > &children, ull from, ull to){
    DEBUG{printf("union %llu %llu\n",from, to);}
    for(auto x : children[from-1]){
        // parents[x-1]=to;
        children[to-1].insert(x);
    }
    children[to-1].insert(from);
    parents[from-1]=to-1;
    children[from-1].clear();  
    return; 
}

int main(void) {
    ull n,m,e1,e2;
    cin >> n >> m;
    vector<pair<ull, ull> > e;
    vector<set<ull> > children(n,set<ull>());
    vector<ull> res(m,0);
    vector<ull> parents;
    rep(i,m){
        // pair<ull, ull> tmp;
        // tmp = pair<ull, ull>();
        cin >> e1 >> e2;
        DEBUG{printf("(%llu %llu)",e1,e2);}
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
    ull cnt=n;
    rep(i,m){
        // DEBUG{printf("roop in\n");}
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
        if(parents[tmp.first-1]!=parents[tmp.second-1]){
            // DEBUG{printf("union : %llu %llu",tmp.first, tmp.second);}
            ull a = (ull(children[parent(parents, tmp.first)].size())+1)*(1+ull(children[parent(parents, tmp.second)].size()));
            DEBUG{
                cout << "parent of first " << tmp.first << endl;
                cout << parent(parents, tmp.first) << endl;
                cout << "parent of second " << tmp.second << endl;
                cout << parent(parents, tmp.second) << endl;

                // for(auto x :]){
                //     cout << x << endl;
                // }
                // cout << "children " << tmp.second << endl;
                // for(auto x :children[parent(parents, tmp.second)]){
                //     cout << x << endl;
                // }
            }
            res[i]=res[i-1]-a;
            change_parent(parents, children, tmp.first, tmp.second);
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