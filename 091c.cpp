
#include <bits/stdc++.h>
using namespace std;
struct vec2
{
    int x;
    int y;
    bool is_used;

    bool operator<(const vec2 &another) const
    {
        return x < another.x;
    }
};

int main(void) {
    int N;
    vector<struct vec2> va;
    int x;
    int y;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x >> y;
        vec2 a = {x, y, false};
        va.push_back(a);
    }
    vector<struct vec2> vb;
    for(int i=0;i<N;i++){
        cin >> x >> y;
        vec2 a = {x,y, false};
        vb.push_back(a);
    }
    sort(vb.begin(),vb.end());
    sort(va.begin(),va.end());
    int count=0;
    int max_y;
    for (vector<vec2>::iterator it = vb.begin(); it!=vb.end();it++) {
        max_y=-1;
        int a=-1;
        for (int i=0;i<N-count;i++) {
            if (va.at(i).x < it->x && va.at(i).y < it->y && max_y < va.at(i).y) {
                a=i;
                max_y = va.at(i).y;
            }else if(va.at(i).x > it->x){
                break;
            }
            
        }
        if (a!=-1){
            va.erase(va.begin()+a);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}