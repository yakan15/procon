#include <bits/stdc++.h>
using namespace std;

struct res {
    int i;
    string s;
    int p;
    bool operator<(const res &another) const {
        if (s==another.s){
            return p > another.p; 
        }
        return s < another.s;
    }
};

int main(void) {
    int N;
    cin >> N;
    vector<struct res> A;
    for (int i=0;i<N;i++){
        struct res a;
        a.i = i+1;
        cin >> a.s >> a.p;
        A.push_back(a);
    }
    sort(A.begin(),A.end());

    for(vector<struct res>::iterator itr=A.begin();itr!=A.end();itr++){
        cout << itr->i <<endl;
    }

    return 0;
}
