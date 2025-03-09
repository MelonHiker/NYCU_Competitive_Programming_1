#include <bits/stdc++.h>
using namespace std;

struct Comb {
    int v, cnt[3] = {};
    bool operator<(const Comb &other) {
        return v < other.v;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int b, n, e;
    cin >> b >> n >> e;
    vector<int> s(3);
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }

    vector<Comb> combs;
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            Comb comb;
            comb.cnt[i]++, comb.cnt[j]++;
            comb.v = s[i] + s[j];
            combs.push_back(comb);
        }
    }
    sort(combs.begin(), combs.end());

    int m = (b + n + e) / 2, l = 2e8, r = 2e8;
    vector<int> consts(m);
    for (int i = 0; i < m; i++) {
        cin >> consts[i];
        l = min(consts[i], l);
    }
    sort(consts.rbegin(), consts.rend());

    auto ck = [&](int k) {
        vector<int> arr(m);
        for (int i = 0; i < m; i++) {
            arr[i] = (k + consts[i] - 1) / consts[i];
        }
        int pt = 0;
        int cb = b, cn = n, ce = e;
        for (int i = 0; i < m; i++) {
            while (pt < combs.size() && combs[pt].v < arr[i]) {
                pt++;
            }
            while (pt < combs.size() && (cb - combs[pt].cnt[0] < 0 || cn - combs[pt].cnt[1] < 0 || ce - combs[pt].cnt[2] < 0)) {
                pt++;
            }
            if (pt >= combs.size()) {
                return false;
            }
            cb -= combs[pt].cnt[0];
            cn -= combs[pt].cnt[1];
            ce -= combs[pt].cnt[2];
        }
        return true;
    };

    while (l <= r) {
        int mid = (l + r) / 2;
        if (ck(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << '\n';
}