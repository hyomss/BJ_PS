/*
DFS
*/

// 하는 중.............진짜 뭐가 문제지..

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

const int MAX_N = 20010;
int K, V, E;
vector <int> g[MAX_N];
int visit[MAX_N]; // 0,1,2

bool dfs(int root) {
	int nxt;
	for (int i = 0; i < (int)g[root].size(); i++) {
		nxt = g[root][i];

		if (visit[nxt] != 0) { // 이미 방문함. 
			if (visit[root] == visit[nxt]) return 0;
			continue;
		}

		if (visit[root] == 1) {
			visit[nxt] = 2;
		}
		else if (visit[root] == 2) {
			visit[nxt] = 1;
		}

		dfs(nxt);

	}
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> K;
	int e1, e2;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &V, &E);

		memset(visit, 0, sizeof(visit));
		memset(g, 0, sizeof(g));

		for (int j = 0; j < E; j++) {
			scanf("%d %d", &e1, &e2);
			g[e1].push_back(e2);
			g[e2].push_back(e1);
		}
		visit[e1] = 1;
		bool chk = dfs(e1);
		if (chk) cout << "YES" << endl;

		else cout << "NO" << endl;
	}

	return 0;
}