/*
�ð����⵵ : O(V+E)
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

	// �̰� ���ص� ���ư��⵵ �ϴ���..
	for (int i = 0; i < V; ++i) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(root);

	return 0;
}
