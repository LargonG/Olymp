// 100/100 баллов

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long llong;

int main() {
	llong n, m; cin >> n >> m;
	
	while (n % 2 == 0) {
		n /= 2;
		m *= 2;
	}

	llong p = 2 * (n + m);
	while (m % 2 == 0) {
		n *= 2;
		m /= 2;
		p = max(p, 2 * (n + m));
	}

	cout << p;
	return 0;
}