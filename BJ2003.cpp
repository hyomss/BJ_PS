/*
N = 10,000까지.0.5초이므로 1차 배열에서 NlgN, N이하로 낮춰야 한다. 
M은 3억이므로 -21~21억인 int를 쓰면 된다.

부분합 개념 이용
sn = a1~an
an = sn-s(n-1)
sum(ai~aj) = sj-s(i-1)
i,j  고르는 건 N*N 
sum 연산은 처음에 쭉 계산해둔다 치면 N
partial sum은 그냥 빼기니까 시간 1 

여기서 i,j를 모두 보는게 아니라 합이 M이 되는 걸 골라야 N*N피할 수 있다.
둘다 0에 두고 시작 -> 각각 움직이며 M보다 작으면 j++, 크면 i++하며 뒤로 이동한다.
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