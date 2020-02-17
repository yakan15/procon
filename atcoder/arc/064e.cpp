#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<tuple<double,double,double>> circles;
    rep(i,2){
        double tx,ty;cin>>tx>>ty;
        circles.push_back(make_tuple(tx,ty,0));
    }
    double n;cin>>n;
    rep(i,n){
        double tx,ty,tr;cin>>tx>>ty>>tr;
        circles.push_back(make_tuple(tx,ty,tr));
    }
    function<double(double,double,double,double)> distance = [=](double ax, double ay, double bx, double by){
        return sqrt(pow(ax-bx,2)+pow(ay-by,2));
    };
    vector<vector<double>> mat(n+2,vector<double>(n+2,0));
    rep(i,n+2){
        rep(j,n+2){
            double dist = max(0.0,(get<2>(circles[i])+get<2>(circles[j]))*(-1.0)+
            distance(get<0>(circles[i]), get<1>(circles[i]),
            get<0>(circles[j]), get<1>(circles[j])));
            mat[i][j] = mat[j][i] = dist;
        }
    }
    DEBUG{
        rep(i,n+2){
            rep(j,n+2){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    priority_queue<pair<double,double>, vector<pair<double,double>>,greater<pair<double,double>>> pq;
    vector<double> d(n+2,1e+14);
    vector<bool> check(n+2,false);
    pq.push(make_pair(0,0));
    d[0]=0;
    while(!pq.empty()){
        auto now = pq.top();
        DEBUG{
            cout << "now: " << now.second << endl;
        }
        pq.pop();
        if(check[now.second]){
            continue;
        }
        check[now.second]=true;
        rep(i,n+2){
            if(!check[i]){
                if(chmin(d[i],d[now.second]+mat[i][now.second])){
                    pq.push(make_pair(d[i],i));
                }
            }
        }
    }
    printf("%.10lf\n",d[1]);
    return 0;
}
