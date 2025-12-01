#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    // 1.Max/Min in all k-length subarrays using multiset
    /*
    int k;
    cin >> k;
    multiset<ll> se;

    for (int i = 0; i < k; i++) {
        se.insert(a[i]);
    }

    for (int i = 0; i <= n - k; i++) {
        ll mn = *se.begin();
        ll mx = *se.rbegin();
        cout << "Min: " << mn << ", Max: " << mx << "\n";

        se.erase(se.find(a[i]));
        if (i + k < n) {
            se.insert(a[i + k]);
        }
    }
    */

    // 2️.Maximum length subarray of unique elements using deque
    /*
    map<ll, ll> mp;
    deque<ll> dq;
    ll max_len = 0;

    for (int i = 0; i < n; i++) {
        if (mp[a[i]] == 1) {
            while (1) {
                ll v = dq.front();
                dq.pop_front();
                mp[v] = 0;
                if (v == a[i]) break;
            }
        }
        dq.push_back(a[i]);
        mp[a[i]] = 1;
        max_len = max(max_len, (ll)dq.size());
    }

    cout << "Max unique length: " << max_len << "\n";
    */

    // 3️.Minimum length substring with 3 distinct characters using deque
    /*
    string s;
    cin >> s;
    int len = s.size();
    map<char, int> mp;
    deque<char> dq;
    int min_len = INT_MAX;

    for (int i = 0; i < len; i++) {
        dq.push_back(s[i]);
        mp[s[i]]++;

        while (mp.size() == 3) {
            min_len = min(min_len, (int)dq.size());
            char v = dq.front();
            dq.pop_front();
            mp[v]--;
            if (mp[v] == 0) mp.erase(v);
        }
    }

    if (min_len == INT_MAX) cout << "No valid substring\n";
    else cout << "Min length with 3 distinct: " << min_len << "\n";
    */

    return 0;
}
