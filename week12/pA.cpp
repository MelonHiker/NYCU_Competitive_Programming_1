#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

pii operator-(pii a, pii b) {
    return {a.first - b.first, a.second - b.second};
}
int cross(pii a, pii b) {
    return a.first * b.second - a.second * b.first;
}

void solve(int n) {
    vector<pii> pnts(n);
    for (int i = 0; i < n; i++) {
        cin >> pnts[i].first >> pnts[i].second;
    }
    sort(pnts.begin(), pnts.end());
    pnts.resize(unique(pnts.begin(), pnts.end()) - pnts.begin());

    if (pnts.size() == 1) {
        cout << "1\n" << pnts[0].first << ' ' << pnts[0].second << '\n';
        return;
    }

    vector<pii> hull;
    for (int i = 0; i < 2; i++) {
        int t = hull.size();
        for (pii pnt: pnts) {
            while (hull.size() - t >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0) {
                hull.pop_back();
            }
            hull.push_back(pnt);
        }
        hull.pop_back();
        reverse(pnts.begin(), pnts.end());
    }
    cout << hull.size() << '\n';
    for (pii pnt: hull) {
        cout << pnt.first << ' ' << pnt.second << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        solve(n);
    }
}