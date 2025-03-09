#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<pii> bit;
vector<int> arr;
void update(int pos, pii val) {
    for (; pos < bit.size(); pos+=pos&-pos) {
        bit[pos] = max(bit[pos], val);
    }
}
pii get_max(int pos) {
    pii ans = {0, -1};
    for (; pos > 0; pos-=pos&-pos) {
        if (ans.first == bit[pos].first) {
            if (ans.second != -1 && arr[ans.second] > arr[bit[pos].second]) {
                ans = bit[pos];
            }
        } else {
            ans = max(ans, bit[pos]);
        }
    }
    return ans;
}

void solve(int n) {
    map<int, int> cpr;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cpr[arr[i]];
    }
    int cnt = 0;
    for (auto &pr: cpr) {
        pr.second = ++cnt;
    }
    bit.assign(cnt + 1, {0, -1});
    int lis = 0;
    vector<int> dp(n), pre(n, -1);
    for (int i = 0; i < n; i++) {
        pii res = get_max(cpr[arr[i]] - 1);
        dp[i] = res.first + 1;
        pre[i] = res.second;
        update(cpr[arr[i]], {dp[i], i});
        lis = max(lis, dp[i]);
    }
    
    vector<int> ans(lis, 1e9);
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] == lis) {
            vector<int> tmp(lis);
            int pt = i, k = lis - 1;
            while (pt != -1) {
                tmp[k] = arr[pt];
                pt = pre[pt];
                if (tmp[k] > ans[k]) {
                    break;
                }
                k--;
            }
            if (k < 0) {
                ans = tmp;
            }
        }
    }
    cout << lis << ' ';
    for (int i = 0; i < lis; i++) {
        cout << ans[i] << " \n"[i == lis - 1];
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