// 16/100 баллов

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
 
using namespace std;
 
typedef long long llong;
 
llong minBal = 0;
 
struct Node {
    set<llong> olinks;
    set<llong> ilinks;
    llong minBal;
    llong bal;
 
    Node(llong bal) : minBal(0), bal(bal) {}
};
 
void dfs(vector<Node*>& nodes, int from, int to) {
    if (from >= 0) {
        nodes[to]->ilinks.erase(from);
 
        nodes[to]->bal += nodes[from]->bal;
        nodes[to]->minBal += nodes[from]->minBal;
    }
    if (nodes[to]->ilinks.empty()) {
        nodes[to]->minBal = min(nodes[to]->minBal, nodes[to]->bal);
 
        for (const auto& x : nodes[to]->olinks)
            dfs(nodes, to, x);
             
        if (nodes[to]->olinks.empty()) {
            minBal += nodes[to]->minBal;
        }
    }
}
 
int main() {
    int n, m; cin >> n >> m;
    vector<llong> v(n);
    vector<bool> root(n, true);
    vector<Node*> nodes(n);
    for (auto& x : v) cin >> x;
    for (int i = 0; i < n; ++i) {
        nodes[i] = new Node(v[i]);
    }
 
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        nodes[a]->olinks.insert(b);
        nodes[b]->ilinks.insert(a);
        root[b] = false;
    }
 
    for (int i = 0; i < n; ++i) {
        if (root[i]) {
            dfs(nodes, -1, i);
        }
    }
 
    cout << -minBal;
    return 0;
}