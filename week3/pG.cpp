#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;
    vector<double> ft(n), bk(m);
    for (auto &x: ft) {
        cin >> x;
    }
    for (auto &x: bk) {
        cin >> x;
    }
    vector<double> ratio;
    for (auto a: ft) {
        for (auto b: bk) {
            ratio.push_back(a / b);
        }
    }
    sort(ratio.begin(), ratio.end());

    for (int i = 1; i < ratio.size(); i++) {
        if (ratio[i] / ratio[i - 1] - 1 > p / 100.00) {
            cout << "Time to change gears!\n";
            return 0;
        }
    }
    cout << "Ride on!\n";
}