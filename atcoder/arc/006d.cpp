#include <bits/stdc++.h>
#include <unistd.h>
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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;cin>>h>>w;
    vector<string> c(h);
    int res[3]={};
    vector<vector<int>> field(h,vector<int>(w,0));
    const string abc[2][4][3] = {
        {
            {"010","101","000"},
            {"011","001","001"},
            {"010","011","010"},
            {"011","101","001"}
        },
        {
            {"011","010","011"},
            {"011","100","011"},
            {"010","101","101"},
            {"011","010","010"}
        }
    }; 

    rep(i,h){
        cin>>c[i];
    }
    rep(i,h){
        rep(j,w){
            field.at(i).at(j) = int(c.at(i).at(j) == 'o');
        }
    }
    function<int(int,int)> check_dot = [&](int i, int j){
        int count = 1;
        while(i+count<h&&j+count<w&&
        field[i+count][j]&&field[i][j+count]&&field[i+count][j+count]){
            count++;
        }
        return count;
    };
    function<void(int,int,int)> reset = [&](int row, int col, int size){
        rep(i,size){
            rep(j,size){
                assert(row+i>=0&&col+j>=0);
                field.at(row+i).at(col+j)=0;
            }
        }
    };
    function<int(int,int,int)> check_abc = [&](int row, int col, int size){
        DEBUG{printf("check abc in\n");}
        DEBUG{printf("row : %d, col : %d, size : %d\n",row,col,size);}
        int cur = 2;
        DEBUG{
            rep(j,3){
                rep(k,3){
                    cout << field.at(row+j*size).at(col+(k-1)*size) << " ";
                }
                cout << endl;
            }
        }
        rep(i,2){
            bool flg;
            rep(l,4){
                flg=true;
                rep(j,3){
                    rep(k,3){
                        assert(row+j*size>=0&&col+(k-1)*size>=0);
                        flg = flg && field.at(row+j*size).at(col+(k-1)*size)==abc[i][l][j][k]-'0';
                    }
                }
                if(flg){cur=i;break;}
            }
            if(flg){break;}
        }
        queue<pair<int,int>> que;
        que.push(make_pair(row,col));
        reset(row,col,size);
        while(!que.empty()){
            row = que.front().first;col = que.front().second;
            que.pop();
            repr(i,-1,2){
                repr(j,-1,2){
                    assert(row+i*size>=0&&col+j*size>=0);
                    if(field.at(row+i*size).at(col+j*size)){
                        que.push(make_pair(row+i*size,col+j*size));
                        reset(row+i*size, col+j*size, size);
                    }
                }
            }
        }
        return cur;
    };
    rep(i,h){
        rep(j,w){
            if(field[i][j]){
                int dot = check_dot(i,j);
                res[check_abc(i,j,dot)]++;
            } 
        }
    }
    printf("%d %d %d\n",res[0],res[1],res[2]);
    return 0;
}
