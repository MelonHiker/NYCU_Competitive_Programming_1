#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int m;
            cin >> m;
            arr[i] |= m;
        }
    }
    
    for (int x: arr) {
        cout << x << ' ';
    }
    cout << '\n';
}