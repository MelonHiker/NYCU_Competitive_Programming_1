#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

vector<ll> fib;
char dfs(ll n, ll k) {
    if (n == 1) {
        return 'N';
    }
    if (n == 2) {
        return 'A';
    }
    if (k <= fib[n - 3]) {
        return dfs(n - 2, k);
    }
    return dfs(n - 1, k - fib[n - 3]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    fib.resize(n, INF);
    fib[0] = fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] > INF) {
            fib[i] = INF;
            break;
        }
    }
    cout << dfs(n, k) << '\n';
}