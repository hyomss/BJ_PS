/*
S�� 10���̴ϱ� int 
�̷� ������ ��� �������� int�� �Ѿ�� stackoverflow�� ���� ���� �ִ�. 
% Ʋ���� ������ �𸣰ڴµ� �̻��� ���� ������ ���� ���� Ȯ��

1) i,j �Űܰ��� �ϴ� ��� ���� N���� �ذᰡ��

2) ���������� �ٲ㼭 Ǯ �� �ִ�. �� ���� �������� o , x  ������.
�������̰� k �� �� �����ϴ� ���� ã���� �ִ�/����
0 1	2 3 4 . . . 
x x o o o . . .-> binary�� ù o�� ã�´�. NlgN
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