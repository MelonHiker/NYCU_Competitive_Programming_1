#include <bits/stdc++.h>
using namespace std;

vector<int> bit;
int get_sum(int pos) {
    int sum = 0;
    for (; pos > 0; pos -= pos&-pos) {
        sum += bit[pos];
    }
    return sum;
}
void update(int pos, int delta) {
    for (; pos < bit.size(); pos += pos&-pos) {
        bit[pos] += delta;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> memory(n + 1);
    bit.resize(n + 1);
    while (q--) {
        char c;
        cin >> c;
        if (c == 'F') {
            int i;
            cin >> i;
            if (memory[i]) {
                update(i, -1);
                memory[i] = 0;
            } else {
                update(i, 1);
                memory[i] = 1;
            }
        } else if (c == 'C') {
            int l, r;
            cin >> l >> r;
            cout << get_sum(r) - get_sum(l - 1) << '\n';
        }
    }    
}