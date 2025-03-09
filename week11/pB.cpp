#include <bits/stdc++.h>
using namespace std;

struct Event {
    int s, f;
    bool operator<(const Event &other) {
        return f < other.f;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<Event> events(n);
    for (auto &event: events) {
        cin >> event.s >> event.f;
    }
    sort(events.begin(), events.end());

    int ans = 0;
    multiset<int> st;
    for (auto event: events) {
        auto it = st.lower_bound(event.s);
        if (it != st.begin()) {
            st.erase(--it);
            st.insert(event.f);
            ans++;
        } else if (st.size() < k) {
            st.insert(event.f);
            ans++;
        }
    }
    cout << ans << '\n';
}