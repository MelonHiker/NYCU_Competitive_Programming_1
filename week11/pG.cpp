#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> seq(n);
    for (int &x: seq) {
        cin >> x;
    }
    seq.erase(unique(seq.begin(), seq.end()), seq.end());
    n = seq.size();

    map<int, int> cmp;
    for (int &x: seq) {
        cmp[x];
    }
    int idx = 0;
    for (auto &pr: cmp) {
        pr.second = idx++;
    }
    for (int &x: seq) {
        x = cmp[x];
    }

    vector<vector<int>> pos(idx);
    for (int i = 0; i < n; i++){
        pos[seq[i]].push_back(i);
    }

    pii best1 = {0, n};
    pii best2 = {0, n};

    for (int h = 0; h < idx - 1; h++) {
        pii new_best1 = best1;
        pii new_best2 = best2;
        for (int posIndex : pos[h]){
            if (posIndex == n - 1)
                continue;
            if (seq[posIndex + 1] != h + 1)
                continue;
            pii candidate;
            if (posIndex != best1.second) {
                candidate = best1;
            } else {
                candidate = best2;
            }
            
            candidate.first++;
            candidate.second = posIndex + 1;

            if (pos[h + 1].size() == 1)
                candidate.second = n;
            
            if (candidate > new_best1) {
                new_best2 = new_best1;
                new_best1 = candidate;
            } else if (candidate > new_best2) {
                new_best2 = candidate;
            }
        }
        best1 = new_best1;
        best2 = new_best2;
    }

    cout << (n - 1 - best1.first) << "\n";
}
