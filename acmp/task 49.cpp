#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Interval {
	int begin, end;

	Interval(char begin = 0, char end = 0) : begin(begin), end(end) {}
};

map<char, Interval> convert = {
	{'?', {0, 9}}
};

int get_intersection(const Interval& a, const Interval& b) {
	int max_begin = max(a.begin, b.begin);
	int min_end = min(a.end, b.end);
	return max(0, min_end - max_begin + 1);
}

int main() {
	for (char symb = 'a'; symb <= 'g'; ++symb)
		convert[symb] = { symb - 'a', symb - 'a' + 3};
	for (char symb = '0'; symb <= '9'; ++symb)
		convert[symb] = { symb - '0', symb - '0' };
	string p1, p2;
	cin >> p1 >> p2;
	vector<ll> dp(p1.size());
	for (int i = 0; i < p1.size(); ++i) {
		dp[i] = get_intersection(convert[p1[i]], convert[p2[i]]) * (i > 0 ? dp[i - 1] : 1LL);
	}
	cout << dp.back();
	return 0;
}