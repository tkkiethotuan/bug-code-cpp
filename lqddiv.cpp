#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const long long N = 32 + 10;

ll a[N];
ll n, minn, dem;

void solve(ll n1, ll n2) {
    if (n1 > n2) {
        if (n1 - n2 <= minn) {
            minn = n1 - n2;
            dem = 0;
        }
    }
    
    if (n2 > n1) {
        if (n2 - n1 <= minn) {
            minn = n2 - n1;
            dem = 0;
        }
    }
    
    if (n1 - n2 == minn || n2 - n1 == minn) {
        dem ++;
    }
}

void backtrack(ll pos, ll n1, ll n2) {
    for (long long i = 1; i <= 2; i ++) {
        if (i == 1) n1 += a[pos];
        if (i == 2) n2 += a[pos];
        
        if (pos == n) solve(n1, n2);
        else backtrack(pos + 1, n1, n2);
    }
}

int main() {
    cin >> n;
    for (long long i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    minn = a[n];
    backtrack(1, 0, 0);
    
    cout << minn << " " << dem << '\n';
}
