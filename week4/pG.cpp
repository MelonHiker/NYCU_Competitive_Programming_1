#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    while (cin >> x) {
        if (x == 0) {
            break;
        }
        string s, p, c;
        cin >> s >> p >> c;
        int n = c.size();
        int d = int(pow((long double)n, 1.5) + x) % n;

        map<char, int> sp;
        for (int i = 0; i < s.size(); i++) {
            sp[s[i]] = i;
        }

        string m(n, '\0');
        m[d] = p[sp[c[d]]];
        for (int j = (d - 1 + n) % n; j != d; j = (j - 1 + n) % n) {
            int pos = sp[c[j]] ^ sp[m[(j + 1) % n]];
            m[j] = p[pos];
        }
        cout << m << '\n';
    }
}