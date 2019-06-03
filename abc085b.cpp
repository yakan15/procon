#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  int n;
  set<int> number;
  for (int i=0;i<N;i++) {
      cin >> n;
      number.insert(n);
  }
  cout << number.size() << endl;
  return 0;
}