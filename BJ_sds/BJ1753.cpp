/*
음이 아닌 가중치가 있는 그래프 문제 -> 다익스트라 이용

w = 10 이하이므로 초기가중치 = V*10 + 1로 잡으면 된다
** 두 정점사이에 여러 개의 간선이 있을 경우 처음부터 문제에 따라 최소/최대 가중치만 저장한다.

adj[s] = (e,w)로 저장한다.
간선이 아미 있는지 확인할 떄는 hash, set 등등 이용가능. 
f=s*100+e 정도 함수로 찾아가서 해당위치에 bool로 유무 저장
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
const int MAX_N = 20010;

//vector <pair<int, int>> adj; // end, weight 저장하려고.  아래랑 같은 의미
struct Node {
	int idx, w;

	friend bool operator < (Node a, Node b){
		return a.w > b.w;
	}
};

int N, dist[MAX_N]; // 거리 저장
vector <Node> adj[MAX_N]; // 여기서 Node는 종료점과 그 점까지의 dist값이다
priority_queue<Node> pq;  // 여기서 Node는 각 지점까지의 거리

int dijkstra(int s, int e) {
	// init
	for (int i = 1; i <= N; ++i) dist[i] = INF;
	dist[s] = 0;
	pq.push({ s,0 });

	// 시작
	int here_idx, here_w, next_idx, next_w;
	while (!pq.empty()) {
		// 탐색할 노드 찾기
		here_idx = pq.top().idx;
		here_w = pq.top().w; // 큐에 들어간 시점의 w는 그 시점의 최소값. dist는 계속 갱신되는 값. 그러므로 비교해서 큐값 갱신할지 말지 결정
		pq.pop(); 

		// 종료조건. 만약 모든 점에 대해 해야되면 큐 소진시까지 해야하므로 이부분 삭제
		if (here_idx == e) return dist[e];

		if (here_w > dist[here_idx]) continue; // 튜닝 옵션
		
		// 현재 노드에서 이웃한 노드들의 최소거리 갱신
		for (int i = 0; i < (int)adj[here_idx].size(); ++i) {
			next_idx = adj[here_idx][i].idx;
			next_w = adj[here_idx][i].w;

			// 현재까지 거리 + 현재~다음 노드 거리 < 다음 노드에 기록된 최소거리 일때 갱신
			if (dist[here_idx] + next_w < dist[next_idx]) {
				dist[next_idx] = dist[here_idx] + next_w;
				pq.push({ next_idx, dist[next_idx] }); // 갱신
			}
		}
	}

	// 여기 오면 안되고 위에서 return 돼야함. 디버깅 용
	return -1;
}


int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int V, E;
	cin >> V >> E;
	int root, a, b, we;
	scanf("%d", &root);

	for (int i = 1; i <= E; ++i) {
		scanf("%d %d %d", &a, &b, &we);
		adj[a].push_back(Node{ b,we });
	}


	for (int e = 1; e <= V; ++e) {
		int ans = dijkstra(root, e);
		if ( ans != INF) cout << ans << endl; 
		else cout << INF << endl;
	}


	return 0;
}