#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p; cin >> n >> p;
    string s; cin >> s;

    // p == 2, 5
    if (10%p == 0) {
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            if ((s[r]-'0')%p == 0) {
                ans += r+1;
            }
        }
        cout << ans << endl;
        return 0;
    }

    vector<int> d(n+1);
    int ten = 1;
    for (int i = n-1; 0 <= i; i--) {
        int a = (s[i]-'0') * ten % p;
        d[i] = (d[i+1] + a)%p;
        ten *= 10; ten %= p;
    }
    vector<int> cnt(p);
    long long ans = 0;
    for (int i = n; 0 <= i; i--) {
        ans += cnt[d[i]];
        cnt[d[i]]++;
    }
    cout << ans << endl;
    return 0;
}