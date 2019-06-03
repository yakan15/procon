#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,K;
    cin >> N >> K;
    vector<int> V;
    int tmp;
    for (int i=0;i<N;i++){
        cin >> tmp;
        V.push_back(tmp);
    }
    int m = 0;
    vector<int> hand;
    for (int i=0;i<=K&&i<=N;i++){
        for (int j=0;i+j<=K&&j<=N;j++){
            for (int k=0;i+j+k<=K;k++){
                if(!hand.empty()){hand.clear();}
                for(int count=0;count<i;count++){
                    hand.push_back(V.at(count));
                }
                for(int count=0;count<j;count++){
                    hand.push_back(V.at(N-1-count));
                }
                sort(hand.begin(), hand.end());
                for(int count=0;count<k&&!hand.empty();count++){
                    hand.erase(hand.begin());
                }
                int s = 0;
                for(int count=0;count<hand.size();count++){ s += hand.at(count);}
                if (m < s){ m=s;}
            }
        }
    }
    cout << m << endl;
    return 0;
}