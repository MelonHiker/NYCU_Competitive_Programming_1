#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> plot(n), circle(m), square(k);
    for (int i = 0; i < n; i++) {
        cin >> plot[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> circle[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> square[i];
    }

    sort(plot.begin(), plot.end());
    sort(circle.begin(), circle.end());
    sort(square.begin(), square.end());
    int ci = 0, si = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (ci < m && plot[i] > circle[ci]) {
            ci++;
            ans++;
        } else if (si < k && 2 * plot[i] * plot[i] > square[si] * square[si]) {
            si++;
            ans++;
        }
    }
    cout << ans << '\n';
}