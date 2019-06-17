#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> a;
    a.insert(3);a.insert(4);a.insert(1);
    for(auto x:a)printf("%d ",x);
    printf("hello world!\n");
    return 0;
}
