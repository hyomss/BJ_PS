/*
선분교차, Union find
*/

#include <iostream>
using namespace std;

pair <pair <int, int>, pair <int, int>> p[3010];
int parent[3010], sz[3010];
int N;

int CCW(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3)
{
	int op = p1.first * p2.second + p2.first*p3.second + p3.first*p1.second;
	op -= (p1.first*p3.second + p2.first*p1.second + p3.first*p2.second);

	if (op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}

bool CheckIntersect(int line1, int line2)
{
	pair<int, int> p1 = p[line1].first;
	pair<int, int> p2 = p[line1].second;
	pair<int, int> p3 = p[line2].first;
	pair<int, int> p4 = p[line2].second;

	int line1_2 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
	int line2_1 = CCW(p3, p4, p1) * CCW(p3, p4, p2);

	if (line1_2 == 0 && line2_1 == 0)
	{
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);
		return p1 <= p4 && p3 <= p2;
	}
	return line1_2 <= 0 && line2_1 <= 0;
}

// union
void init() {
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int n) {
	if (n == parent[n]) return n;
	return parent[n] = find(parent[n]);
}

int merge(int a, int b) {
	int r1 = find(a);
	int r2 = find(b);

	if (r1 == r2) return 0;
	if (sz[r1] > sz[r2]) {
		parent[r2] = r1;
		sz[r1] += sz[r2];
	}
	else {
		parent[r1] = r2;
		sz[r2] += sz[r1];
	}
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> N;
	init();

	for (int i = 0; i < N; i++) {
		cin >> p[i].first.first >> p[i].first.second >> p[i].second.first >> p[i].second.second;
	}
	
	bool check;
	int group = N;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			check = CheckIntersect(i, j);
			if (check & 1) {
				if(merge(i, j) & 1) 		// 그룹으로 묶었으면 1, 이미 그룹이면 0
					group--;
			}
		}
	}
	int max = 0;
	for(int i = 0; i < N; i++) {
		if (max < sz[i]) max = sz[i];
	}

	cout << group << "\n" << max << "\n";

	return 0;
}