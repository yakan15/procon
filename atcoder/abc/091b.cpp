#include <bits/stdc++.h>
using namespace std;

int main(void) {
 int nn;
 cin >> nn;
 string str;
 map<string, int> mp;
 for (int i=0;i<nn;i++){
   cin >> str;
   if (mp.count(str)!=0) {
     mp[str] += 1;
   } else {
     mp[str] = 1;
   }
 }
 int mn;
 cin >> mn;
 for (int i=0;i<mn;i++){
   cin >> str;
   if (int(mp.count(str))!=0) {
     mp[str] -= 1;
   } else {
     mp[str] = -1;
   }
 }
 map<string, int>::iterator mpitr = mp.begin();
 int _max = 0;
 while(mpitr != mp.end()){
   if (mpitr->second>=_max) {
     _max = mpitr->second;
   }
   mpitr++;
 }
 cout << _max << endl;
 return 0;
}