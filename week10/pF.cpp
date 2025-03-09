#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
#define int long long
const double PI = acos(-1);

void fft(vector<cd> &A, bool invert) {
    int n = A.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) {
            swap(A[i], A[j]);
        }
    }
 
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wn(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = A[i + j], v = A[i + j + len / 2] * w;
                A[i + j] = u + v;
                A[i + j + len / 2] = u - v;
                w *= wn;
            }
        }
    }
 
    if (invert) {
        for (cd &x: A) {
            x /= n;
        }
    }
}
vector<int> mul(vector<int> const&A, vector<int> const&B) {
    vector<cd> fa(A.begin(), A.end()), fb(B.begin(), B.end());
    int n = 1;
    while (n < A.size() + B.size()) {
        n <<= 1;
    }
    fa.resize(n), fb.resize(n);
 
    fft(fa, false), fft(fb, false);
    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, true);
 
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = round(fa[i].real());
    }
    return res;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> A(n), B(n), res;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            A[i] = 1;
        } else {
            B[n - i - 1] = 1;
        }
    }
    res = mul(A, B);
    for (int i = 1; i < n; i++) {
        cout << res[i + n - 1] << '\n';
    }
}