/*DFSÀÀ¿ë*/
#include <iostream>
#include <cstring> //memset
using namespace std;
int N, T;
int g[100010];
int visit[100010];
int done[100010];
int ans;

void dfs(int node) {
	visit[node] = 1;
	int nxt = g[node];
	if (!visit[nxt]) {
		dfs(nxt);
	}
	else if (!done[nxt]) {
		for (int i = nxt; i != node; i = g[i]) {
			ans++;
		}
		ans++;
	}
	done[node] = 1;
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	int a;
	for (int j = 0; j < T; j++) {
		memset(visit, 0, sizeof(visit));
		memset(done, 0, sizeof(done));

		scanf("%d", &N);
		ans = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &a);
			g[i] = a;
		}

		for (int i = 1; i <= N; i++) {
			if(!visit[i])
				dfs(i);
		}
		printf("%d\n", N - ans);
	}

	return 0;
}