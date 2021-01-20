#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

int main() {
    llong k; cin >> k;
    llong a, x; cin >> a >> x;
    llong b, y; cin >> b >> y;
    llong ans = 0;
    if (a == 0 && b == 0) {
        ans = k * (x + y);
    } else if (a == 0) {
        ans = k * x + max(0LL, k - b) * y;
    } else if (b == 0) {
        ans = k * y + max(0LL, k - a) * x;
    } else if (max(0LL, k - a) * x > max(0LL, k - b) * y) {
        ans = max(0LL, k - a) * x + max(0LL, k - a - b) * y;
    } else {
        ans = max(0LL, k - b) * y + max(0LL, k - a - b) * x;
    }
    cout << ans;
    return 0;
}