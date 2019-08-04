/*
S는 10억이니까 int 
이런 문제는 계산 과정에서 int를 넘어가서 stackoverflow가 나올 수도 있다. 
% 틀리는 이유를 모르겠는데 이상한 답이 나오면 변수 범위 확인

1) i,j 옮겨가며 하는 방법 쓰면 N으로 해결가능

2) 결정문제로 바꿔서 풀 수 있다. 한 구간 양쪽으로 o , x  갈리게.
구간길이가 k 일 때 만족하는 구간 찾을수 있다/없다
0 1	2 3 4 . . . 
x x o o o . . .-> binary로 첫 o를 찾는다. NlgN
*/
#include <iostream>
using namespace std;

int main() {
	int N, M;
	int arr[100000];
	cin >> N >> M;
	int sum[100000] = { 0 };
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}
	int i = 0, j = 1;
	int cnt=100;
	for (; j < N;) {
		if (sum[j] - sum[i] > M) i++;
		else if (sum[j] - sum[i] < M) j++;
		else {
			if (cnt > j - i)	cnt = j - i;
			j++;
		}
	}
	cout << cnt;
 
	return 0;
}