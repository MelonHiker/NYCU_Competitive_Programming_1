#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void solve() {
    int price;
    cin >> price;
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> amt(price + 1, 1e6), cnt(price + 1, n + 1);
    amt[0] = cnt[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = price; j > 0; j--) {
            if (j >= coins[i] && make_pair(amt[j - coins[i]] + coins[i], cnt[j - coins[i]] + 1) < make_pair(amt[j], cnt[j])) {
                amt[j] = amt[j - coins[i]] + coins[i];
                cnt[j] = cnt[j - coins[i]] + 1;
            } else if (j < coins[i] && coins[i] <= amt[j]) {
                amt[j] = coins[i];
                cnt[j] = 1;
            }
        }
    }
    cout << amt[price] << ' ' << cnt[price] << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}