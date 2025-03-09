#include <bits/stdc++.h>
using namespace std;

bool valid[10][10] = {
    {1, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

bool ck(int num) {
    if (num < 0) {
        return false;
    }
    int pre = num % 10;
    num /= 10;
    while (num) {
        if (!valid[pre][num % 10]) {
            return false;
        }
        pre = num % 10;
        num /= 10;
    }
    return true;
}
void solve() {
    int k;
    cin >> k;
    for (int d = 0; d <= 100; d++) {
        if (ck(k - d)) {
            cout << k - d << '\n';
            break;
        }
        if (ck(k + d)) {
            cout << k + d << '\n';
            break;
        }
    }
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