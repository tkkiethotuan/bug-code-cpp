#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const ll N = 38 + 10;

ll n, minn;
ll a[N];

void cal(ll n1, ll n2) {
    if (n1 > n2) {
        if (n1 - n2 <= minn) minn = n1 - n2;
    }

    if (n2 > n1) {
        if (n2 - n1 <= minn) minn = n2 - n1;
    }

    if (n1 == n2) minn = n1 - n2;
}

void backtrack(ll pos, ll n1, ll n2) {
    for (ll i = 1; i <= 2; i ++) {
        if (i == 1) n1 += a[pos];
        if (i == 2) n2 += a[pos];

        if (pos == n) cal(n1, n2);
        else backtrack(pos + 1, n1, n2);

        if (i == 1) n1 -= a[pos];
        if (i == 2) n2 -= a[pos]; 
    }
}

int main() {
    cin >> n;
    for (ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    minn = a[n];

    backtrack(1, 0, 0);

    cout << minn << '\n';
}
