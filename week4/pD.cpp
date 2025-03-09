#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> height(n);
    for (auto &h: height) {
        cin >> h;
    }
    vector<int> pre(n), suf(n);
    for (int i = 1; i < n; i++) {
        pre[i] = max(pre[i - 1], height[i - 1]);
        suf[n - i - 1] = max(suf[n - i], height[n - i]);
    }

    auto ck = [&](int dis) {
        for (int i = 1; i < n - 1; i++) {
            if (pre[i] >= height[i] + dis && suf[i] >= height[i] + dis) {
                return true;
            }
        }
        return false;
    };

    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ck(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << max(r, 0) << '\n';
}