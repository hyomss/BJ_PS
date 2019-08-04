/*
N = 10,000����.0.5���̹Ƿ� 1�� �迭���� NlgN, N���Ϸ� ����� �Ѵ�. 
M�� 3���̹Ƿ� -21~21���� int�� ���� �ȴ�.

�κ��� ���� �̿�
sn = a1~an
an = sn-s(n-1)
sum(ai~aj) = sj-s(i-1)
i,j  ���� �� N*N 
sum ������ ó���� �� ����صд� ġ�� N
partial sum�� �׳� ����ϱ� �ð� 1 

���⼭ i,j�� ��� ���°� �ƴ϶� ���� M�� �Ǵ� �� ���� N*N���� �� �ִ�.
�Ѵ� 0�� �ΰ� ���� -> ���� �����̸� M���� ������ j++, ũ�� i++�ϸ� �ڷ� �̵��Ѵ�.
*/

#include <iostream>
#include<numeric>
using namespace std;

int main() {
	int arr[10001];
	int N;
	long M;
	int cnt = 0;
	int i, j=0,sum=0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	i = 0;
	for (; i < N;) {
			if (sum > M) {
				sum -= arr[i]; i++;
			}
			else if (sum < M) {
				sum += arr[j]; j++;
			}
			else {
				cnt++; sum -= arr[i]; i++;
			}
	}
	
	cout << cnt;


	return 0;
}