#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s;
    cin >> s;
    vector<int> value, cost;
    int tot = 0;
    for (int i = 0; i < s; i++) {
        int d, c, f, u;
        cin >> d >> c >> f >> u;
        tot += d;
        int x = max((f + u + c) / 2 - c + 1, 0);
        if (x > u) {
            continue;
        }
        value.push_back(d);
        cost.push_back(x);
    }

    tot = tot / 2 + 1;
    vector<int> dp(tot + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < value.size(); i++) {
        for (int j = tot; j >= 0; j--) {
            if (j >= value[i]) {
                dp[j] = min(dp[j], dp[j - value[i]] + cost[i]);
            } else {
                dp[j] = min(dp[j], cost[i]);
            }
        }
    }
    if (dp[tot] != INF) {
        cout << dp[tot] << '\n';
    } else {
        cout << "impossible\n";
    }
}