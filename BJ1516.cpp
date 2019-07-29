/*
DFS

위상정렬 풀이
건물A짓는 시간 = max(선행 건물들 짓는 시간) + A 짓는 시간 : 왜냐면 앞에거 다 지어야 뒤에 지을 수 있으니까 

DFS + Memiozation 풀이
child의 짓는 시간을 return 받고 저장해가면서 재귀적으로 루트까지 더하면서 올라간다. 이해하기에는 위상정렬이 나을듯... ?
*/

#include <iostream>
#include<vector>
using namespace std;

const int MAX_N = 510;	// 1~500
vector <int> adj[MAX_N];

int main() {
	freopen("Input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {

	}


	return 0;
}