#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;

    auto ck = [&](int x, int y, int xy) -> bool {
        int used[10] = {};
        while (xy) {
            used[xy % 10]++;
            xy /= 10;
        }
        while (x) {
            if (used[x % 10]-- == 0) {
                return false;
            }
            x /= 10;
        }
        while (y) {
            if (used[y % 10]-- == 0) {
                return false;
            }
            y /= 10;
        }
        return true;
    };

    vector<pii> ans;
    auto fac = [&](int num) {
        for (int i = a; i * i <= num; i++) {
            if (num % i == 0 && ck(i, num / i, num)) {
                ans.push_back({i, num / i});
            }
        }
    };
    for (int k = a; k <= b; k++) {
        fac(k);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << " digit-preserving pair(s)\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << "x = " << ans[i].first << ", y = " << ans[i].second << ", xy = " << ans[i].first * ans[i].second << '\n';
    }
}