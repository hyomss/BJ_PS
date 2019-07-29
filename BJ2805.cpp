/*
N = 100만. M은 int 범위
time = 1sec
그러므로 NlgN 즉 정렬을 이용해야 한다.
죄적화 -> 결정문제. 이분탐색 이용
*/

/*
1 1 1 2 3 3 3 5 6 7 8 9
x x x x o o o o o o o o  -> o인 첫번째를 찾는 결정문제
3 이상인 천번째 인덱스. 이런식으로 찾을수 있는 이분 탐색법
while(s,e){
mid = (s+e)/2;
if(arr[mid] > target){	//	>=에서 =를 뺀다
e = mid-1;
} else{  // mid 가 위든 아래든 한쪽에 들어가게 해야된다.
s = mid;
}
}
return e;

이분탐색 많이 연습!
upper/lower bound 라고 쓸수있는 매소드도 쓸 수 있다.
*/
#include <iostream>
using namespace std;

int tree[1000100];

int main() {
	int N, M;
	int max = -1;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		if (tree[i] > max)	max = tree[i];
	}
	int s = 0, e = max;
	while (s <= e) {
		long long sum = 0;
		int mid = (s + e +1 ) / 2;
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid)	sum += (tree[i] - mid);
		}
		if (s == e) {
			cout << mid; break;
		}
		if (sum > M) {
			s = mid; 
		}
		else if (sum == M) {
			cout << mid; break;
		}
		else {
			e = mid - 1; 
		}
	}

	return 0;
}
