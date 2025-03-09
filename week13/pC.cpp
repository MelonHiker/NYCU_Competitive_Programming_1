#include <bits/stdc++.h>
using namespace std;
const int INF = 500;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, tot_hotdog = 0;
    cin >> h;
    vector<int> hotdog(h);
    for (int &x: hotdog) {
        cin >> x;
        tot_hotdog += x;
    }
    int b, tot_bun = 0;
    cin >> b;
    vector<int> bun(b);
    for (int &x: bun) {
        cin >> x;
        tot_bun += x;
    }
    vector<int> dp1(tot_hotdog + 1, INF), dp2(tot_bun + 1, INF);
    dp1[0] = dp2[0] = 0;
    for (int i = 0; i < h; i++) {
        for (int j = tot_hotdog; j >= hotdog[i]; j--) {
            dp1[j] = min(dp1[j], dp1[j - hotdog[i]] + 1);
        }
    }
    for (int i = 0; i < b; i++) {
        for (int j = tot_bun; j >= bun[i]; j--) {
            dp2[j] = min(dp2[j], dp2[j - bun[i]] + 1);
        }
    }
    int ans = INF;
    for (int i = 1; i <= min(tot_bun, tot_hotdog); i++) {
        if (dp1[i] != INF && dp2[i] != INF) {
            ans = min(ans, dp1[i] + dp2[i]);
        }
    }
    if (ans == INF) {
        cout << "impossible\n";
    } else {
        cout << ans << '\n';
    }
}