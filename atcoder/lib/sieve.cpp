#include <bits/stdc++.h>

// verified by : abc152e
// O(qsrt(N))
// エラトステネスの篩
vector<long long> sieve(long long n) {
    vector<long long> ret;
    vector<bool> check(n+1,false);
    if (n<2) {
        return ret;
    }
    long long idx = 2;
    while(idx*idx<=n) {
        if (!check[idx]) {
            ret.push_back(idx);
            for (int i=idx*idx; i<=n; i+=idx) {
                check[i] = true;
            }
        }
        idx++;
    }
    for(int i=idx;i<=n;i++) {
        if (!check[i]) {
            ret.push_back(i);
        }
    }
    return ret;
}

// 素因数分解
// O(qsrt(N))
// abc 161f
map<ll,ll> prime_fact(ll num) {
    ll now = 2;
    map<ll,ll> divisors; 
    while(now*now<=num) {
        while(num%now==0) {
            divisors[now]++;
            num /= now;
        }
        now++;
    }
    if (num != 1) {
        divisors[num]++;
    }
    return divisors;
}

// 約数
// O(qsrt(N))
vector<ll> divisors(ll num) {
    ll now = 1;
    vector<ll> divs;
    while(now*now<=num) {
        if (num % now==0) {
            divs.push_back(now);
            if (now*now!=num){
                divs.push_back(num/now);
            }
        }
        now++;
    }
    return divs;
}