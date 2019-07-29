/*
시간복잡도 : O(VE)
음수 가중치가 있는 경우.
*/
#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_N = 20010;

struct Node {
	int idx, w;

	friend bool operator < (Node a, Node b) {
		return a.w > b.w;
	}
};

int N, dist[MAX_N]; // 거리 저장
vector <Node> adj[MAX_N]; // 여기서 Node는 종료점과 그 점까지의 dist값이다


int bellman(int s) {
	for (int i = 1; i <= N; ++i) dist[i] = INF;
	dist[s] = 0;


	bool updated; // 튜닝옵션
	for (int re = 1; re <= N - 1; ++re) {
		updated = false; 
		for (int here = 1; here <= N; ++here) {	//	 모든 노드 탐색
			for (int i = 0; i< (int)adj[here].size(); ++here) {
				int next = adj[here][i].idx;
				
				// 현재노드까지 최단거리 + 현재~다음 이동거리 < 다음노드까지 최단거리
				if (dist[here] != INF && dist[here] + adj[here][i].w < dist[next]) {	// 앞에 INF조건은 INF노드에서 INF노드로 w=-10으로 가는 경우 dest의 weight값이 INF-10으로 업데이트가 되어버린다. 그래서 원래는 못간걸로 INF가 떠야하는데 업뎃된 INF-10으로 답이 나와버린다. 
					dist[next] = dist[here] + adj[here][i].w;
					updated = true; // 업데이트 됐는지 확인
				}
			}
		}
		// 업뎃 됐으면 또 다음 해야되고 아니면 break;
		if (!updated) break; 
	}
	
	if(update == true) return -1; // 음수 사이클 
	return 1;
}
