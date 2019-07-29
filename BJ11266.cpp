/*
단절점
시간복잡도 = DFS랑 같다. O(N+E)

< 위에서 아래로 트리처럼 배치해보면 나중에 방문한 노드가 아래로 간다는 것을 이용 >
노드 A아래에서 위로 연결되는 선이 있다면 그 정보를 A에게 전달 -> 이런 간선이 있으면 A가 없어도 그래프 끊기지 X
이제 A의 자식이 인접한 가장 높은 노드 (작은 수부터 방문을 시작할테니까 즉 가장 작은 node num)를 전달
교재에 나온 low를 전달한다는게 가장 작은 노드 num을 전달한다는 뜻임

이렇게 low값을 갱신할때 자식에게서 전달받은 값 >= 나자신 이면 단절점
다만 루트인 경우 전달값 == 루트 여도 자식이 둘 이상일 때만 단절점
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V = 10010;
vector <int> adj[MAX_V];

int found[MAX_V]; // 방문한 순서
int found_num = 0;
bool cut[MAX_V]; // 단절점인지 저장

// here : 현재 탐색중인 위치
// return : 현재 탐색중인 노드를 루트로 하는 sub graph가 방문할 수 있는 최상위 위치(low)
int dfs(int here, bool is_root) {
	found[here] = ++found_num;	//	1부터 저장

	int low = found[here]; // low의 초기값은 방문시점이랑 같다

	int next, child = 0;
	for (int i = 0; i < (int)adj[here].size(); ++i) {
		next = adj[here][i];

		if (found[next] == 0) { // 미방문 노드. dfs 탐색
			++child;
			int sub = dfs(next, false); // sub Node의 가장 최상위노드번호
			if (!is_root && sub >= found[here]) { // 하위노드가 나보다 하위만 바라보면
				//단절점
				cut[here] = true;
			}
			if (sub < low) low = sub; // low 갱신
		}

		else { // 이미 방문한 노드. 당연히 현재보다 상위.
			if (low > found[next]) low = found[next];
		}
	}
	if (is_root && child >= 2) cut[here] = true;
	return low;
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//memset(found, 0, sizeof(found)); 
	int V, E;
	scanf("%d %d", &V, &E);

	int a, b, root;
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//// 이건 안해도 돌아가기도 하던데.. 이게 필요가 없는 게 여기서 어차피 방문 시점을 기준으로 돌리니까.
	//for (int i = 1; i <= V; ++i) {
	//	sort(adj[i].begin(), adj[i].end());
	//}

	// 이건 그래프가 연결이 안돼있을때 필요함. 
	for(int i=1; i<=V;i++)
		if(!found[i])
			dfs(i, true);

	
	int ans = 0;
	for (int i = 1; i <= V ; ++i) {
		if (cut[i]) ans++;
	}
	cout << ans << endl;

	for (int i = 1; i <= V; ++i) {
		if (cut[i]) cout << i << " " ;
	}
	

	return 0;
}
