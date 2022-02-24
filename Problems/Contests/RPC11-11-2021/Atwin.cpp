#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi; // int vec
typedef vector<vi> vvi; // int vec vec
typedef vector<pii> vpi; // int int pair vec

const double pi = 3.1415926535897932384626433832795;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i=0; i< (int)n; ++i) 
#define forab(i, a, b) for (int i=a; i< (int)b; ++i) 
#define foreach(a, b) for (auto&(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type> 
#define pqd(type) priority_queue<type,vector<type>,greater<type> >
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define mp make_pair
#define fi first 
#define se second 
#define nl "\n"
#define in(t) while (t--)

vector<int> primes(){
    vector<int> twinP;
    vector<int> primes;
    bool pass;
    primes.push_back(2);
    primes.push_back(3);
    twinP.push_back(3);
    for(int i = 5; i <= 1e6; ++i){
        pass = true;
        for(int j = 2; j <= sqrt(i); ++j){
            if(i % j == 0){
                pass = false;
                break;
            }
        }
        if(pass){
            if(primes[primes.size() - 1] == i - 2){
                if(twinP[twinP.size() - 1] != primes[primes.size() - 1]){
                    twinP.push_back(primes[primes.size() - 1]);
                }
                twinP.push_back(i);
            }
            primes.push_back(i);
        }
    }
    return twinP;
}

int main(){
    int t, n;
    cin >> t;
    vector<int> twinP = primes();

    in(t){
        cin >> n;
        int l = 0;
        int r = twinP.size() - 1;
        int m;
        while(l + 1 < r){
            m = (l + r) / 2;
            if(n < twinP[m])r = m;
            else l = m;
        }
        int dl = abs(twinP[l] - n);
        int dr = abs(twinP[r] - n);
        if(dl == dr || dr < dl) cout << twinP[r] << nl;
        else cout << twinP[l] << nl;
    }
    
}

