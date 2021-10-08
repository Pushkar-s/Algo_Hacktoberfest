#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int mod = 1000000007;
struct UFDS {
	vector<int> parent, rankof;
	UFDS(int N) {
		for (int i = 0; i < N; ++i) parent.push_back(i), rankof.push_back(0);
	}
	int find_parent(int i) {
		if (parent[i] == i) return i;
		return parent[i] = find_parent(parent[i]);
	}
	bool union_set(int p, int q) {
		p = find_parent(p), q = find_parent(q);
		if (p == q) return false;
		if (rankof[p] == rankof[q]) ++rankof[p];
		if (rankof[p] > rankof[q]) parent[q] = p;
		else parent[p] = q;
		return true;
	}
};
