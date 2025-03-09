#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod_pow(ll x, ll y, ll mod) {
    ll ans = 1;
    while (y) {
        if (y & 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (a & 1) {
        cout << "0\n";
    } else if (a / 2 & 1) {
        cout << a / 2 << '\n';
    } else {
        cout << (a / 2) * (b == 1) << '\n';
    }
}