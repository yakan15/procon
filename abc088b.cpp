#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> cards;
  int input;
  for (int i=0;i<N;i++) {
      cin >> input;
      cards.push_back(input);
  }
  sort(cards.begin(), cards.end(), greater<int>());
  int diff = 0;
  for (int i=0; 2*i+1 < cards.size();i++) {
   diff += cards.at(2*i)-cards.at(2*i+1);
  }
  if (cards.size() % 2 == 1){
      diff += cards.at(N-1);
  }
  cout << diff << endl;
  return 0;
}