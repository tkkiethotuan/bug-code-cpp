#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const ll N = 15 + 10;

ll n, min_homeless_cow;
ll cow_list[N];

void solve(ll cow_villa_1, ll cow_villa_2, ll homeless_cow) {
    if (cow_villa_1 == cow_villa_2) 
        if (homeless_cow <= min_homeless_cow) min_homeless_cow = homeless_cow;
    // if (cow_villa_1 == cow_villa_2) min_homeless_cow = homeless_cow;
    // else min_homeless_cow = a[n];
}

void backtrack(ll pos, ll cow_villa_1, ll cow_villa_2, ll homeless_cow) {
    for (long long i = 1; i <= 3; i ++) {
        if (i == 1) cow_villa_1 += cow_list[pos];
        if (i == 2) cow_villa_2 += cow_list[pos];
        if (i == 3) homeless_cow += cow_list[pos];

        if (pos == n) solve(cow_villa_1, cow_villa_2, homeless_cow);
        else backtrack(pos + 1, cow_villa_1, cow_villa_2, homeless_cow);

        if (i == 1) cow_villa_1 -= cow_list[pos];
        if (i == 2) cow_villa_2 -= cow_list[pos];
        if (i == 3) homeless_cow -= cow_list[pos];
    }
}

int main() {
    cin >> n;
    for (long long i = 1; i <= n; i ++) {
        cin >> cow_list[i];
    }
    sort(cow_list + 1, cow_list + 1 + n);
    min_homeless_cow = cow_list[n];
    backtrack(1, 0, 0, 0);
}