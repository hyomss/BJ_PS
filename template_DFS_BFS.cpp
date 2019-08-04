/*
시간복잡도 : O(V+E)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V = 10010;
vector <int> adj[MAX_V];
int visit[MAX_V];

void dfs(int n) {
	visit[n] = 1;
	int next;
	for (int i = 0; i < (int)adj[n].size(); ++i) {
		next = adj[n][i];
		if (visit[next]) continue;
		dfs(next);
	}
}

void bfs(int start) {
	int visit[MAX_N] = { 0 }; // 초기화

	queue <int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty()) {
		int node = q.front();
		cout << node << " ";

		q.pop();
		int nxt;
		for (int i = 0; i < adj[node].size(); i++) {
			nxt = adj[node][i];
			if (visit[nxt] == 0) {
				q.push(nxt);
				visit[nxt] = 1;
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	memset(visit, 0, sizeof(visit));
	int V, E;
	scanf("%d %d", &V, &E);

	int a, b, root;
	for (int i = 0; i < V; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		if (i == 0) root = a;
	}

	// 이건 안해도 돌아가기도 하던데..
	for (int i = 0; i < V; ++i) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(root);

	return 0;
}
