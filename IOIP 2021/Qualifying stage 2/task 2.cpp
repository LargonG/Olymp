// 31/100 балл

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long llong;
typedef long double ldouble;

// ��� �������������
int binLess(const vector<ldouble>& v, int sx) {
	int l = -1, r = v.size();
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (v[m] + sx >= 0) l = m;
		else r = m;
	}
	return l;
}

int binHigh(const vector<ldouble>& v, int sx) {
	int l = -1, r = v.size();
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (v[m] + sx <= 0) l = m;
		else r = m;
	}
	return l;
}

vector<llong> typo(int n, vector<llong> v, int k, const vector<llong>& x) {
	vector<llong> ans;
	for (int ik = 0; ik < k; ++ik) {
		llong res = 0;
		for (int i = 0; i < n; ++i) {
			res += abs(v[i] + x[ik]);
			v[i] += x[ik];
		}
		ans.push_back(res);
	}
	return ans;
}

vector<llong> solution(int n, const vector<llong>& v, int k, const vector<llong>& x) {
	vector<ldouble> vl, vh;
	vector<ldouble> pl, ph;
	for (int i = 0; i < n; ++i) {
		if (v[i] < 0) {
			vl.push_back(v[i]);
		}
		else {
			vh.push_back(v[i]);
		}
	}
	sort(vl.rbegin(), vl.rend());
	sort(vh.begin(), vh.end());

	pl.assign(vl.size(), 0);
	ph.assign(vh.size(), 0);

	for (int i = 0; i < vl.size(); ++i) {
		pl[i] = (i > 0 ? pl[i - 1] : 0) + vl[i];
	}

	for (int i = 0; i < vh.size(); ++i) {
		ph[i] = (i > 0 ? ph[i - 1] : 0) + vh[i];
	}

	llong sx = 0;
	vector<llong> ans;
	for (int ik = 0; ik < k; ++ik) {
		sx += x[ik];

		llong res = 0;

		if (sx >= 0) {
			int id = min(binLess(vl, sx), (int)vl.size());
			res += (ph.empty() ? 0 : ph.back()) + sx * ph.size()
				+ (id >= 0 ? pl[id] : 0) + sx * (id + 1)
				- ((pl.empty() ? 0 : pl.back()) - (id >= 0 ? pl[id] : 0)) - sx * (pl.size() - id - 1);
		}
		else {
			int id = min(binHigh(vh, sx), (int)vh.size());
			res += -(pl.empty() ? 0 : pl.back()) - sx * pl.size()
				- (id >= 0 ? ph[id] : 0) - sx * (id + 1)
				+ ((ph.empty() ? 0 : ph.back()) - (id >= 0 ? ph[id] : 0)) + sx * (ph.size() - id - 1);
		}
		ans.push_back(res);
	}
	return ans;
}

int main() {
	/*int n; cin >> n;
	vector<llong> v(n);
	for (auto& x : v) cin >> x;
	int k; cin >> k;
	vector<llong> h(k);
	for (auto& x : h) cin >> x;
	vector<llong> ans = solution(n, v, k, h);
	for (const auto& x : ans) cout << (long long)x << "\n";*/
	unsigned long long cnt = 0;
	while (true) {
		
		int n = abs(rand()) % 100;
		vector<llong> v(n);
		for (auto& x : v) x = rand() << 16 | rand();
		int k = abs(rand()) % 100;
		vector<llong> h(k);
		for (auto& x : h) x = abs(rand()) << 15 | abs(rand());
		vector<llong> r1 = typo(n, v, k, h);
		vector<llong> r2 = solution(n, v, k, h);
		if (r1 != r2) {
			cout << "Error!\n";
			cout << "v: ";
			for (auto& x : v) cout << x << " ";
			cout << "\nh: ";
			for (auto& x : h) cout << x << " ";
			cout << "\n\nr1: ";
			for (auto& x : r1) cout << x << " ";
			cout << "\nr2: ";
			for (auto& x : r2) cout << x << " ";
			system("pause");
		}
		else {
			cout << ++cnt << "\n";
		}
	}
	return 0;
}