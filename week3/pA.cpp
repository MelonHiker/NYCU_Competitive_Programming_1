#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> tower(n);
    for (int &x: tower) {
        cin >> x;
    }
    sort(tower.begin(), tower.end());

    int ans = n;
    for (int i = 0; i < n; i++) {
        int cost = tower[i] + n - i - 1;
        ans = min(cost, ans);
    }
    cout << ans << '\n';
}