#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000; // MAXN > sqrt(a)
vector <int> primes, sieve(MAXN + 5);

vector<long long> factorization(long long a){
    // Se asume que se tiene y se llama con la funcion build_sieve()
    vector <long long> ans;
    long long b = a;
    for (int i = 0; 1LL * primes[i] * primes[i] <= a; ++i){
        int p = primes[i];
        while (b % p == 0){
            ans.push_back(p);
            b /= p;
        }
    }
    if (b != 1) ans.push_back(b);
    return ans;
}