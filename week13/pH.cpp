#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int logn = __lg(n);
    vector<int> val(n + 1), len(n + 1);
    vector<vector<int>> nxt(n + 1, vector<int>(logn + 1));
    for (int i = 1; i <= n; i++) {
        char type;
        int v;
        cin >> type >> v;
        if (type == 'a') {
            val[i] = i;
            len[i] = len[v] + 1;
            nxt[i][0] = v;
            for (int j = 1; j <= logn; j++) {
                nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
            }
        } else if (type == 'b') {
            cout << val[v] << '\n';
            val[i] = val[nxt[v][0]];
            len[i] = len[nxt[v][0]];
            nxt[i] = nxt[nxt[v][0]];
        } else {
            int w;
            cin >> w;
            val[i] = val[v];
            len[i] = len[v];
            nxt[i] = nxt[v];
            if (len[v] < len[w]) {
                swap(v, w);
            }
            int diff = len[v] - len[w];
            for (int j = 0; diff; j++) {
                if (diff & 1) {
                    v = nxt[v][j];
                }
                diff >>= 1;
            }
            if (val[v] == val[w]) {
                cout << len[v] << '\n';
                continue;
            }
            for (int j = logn; j >= 0; j--) {
                if (val[nxt[v][j]] == val[nxt[w][j]]) {
                    continue;
                }
                v = nxt[v][j];
                w = nxt[w][j];
            }
            v = nxt[v][0];
            cout << len[v] << '\n';
        }
    }
}