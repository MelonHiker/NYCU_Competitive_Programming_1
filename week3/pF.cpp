#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    vector<pii> client(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> client[i].second >> client[i].first;
    }
    sort(client.begin(), client.end());

    int ans = 0;
    vector<int> dp(t + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = client[i].first + 1; j > 0; j--) {
            dp[j] = max(dp[j], dp[j - 1] + client[i].second);
            ans = max(dp[j], ans);
        }
    }
    cout << ans << '\n';
}