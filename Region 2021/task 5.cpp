#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

int main() {
    llong d, m, w; cin >> d >> m >> w;
    llong i, j, k; cin >> i >> j >> k;
    --i; --j; --k;
    llong dayId = i + j * d + k * m * d;
    char ans = dayId % w + 'a';
    cout << ans;
    return 0;
}