/*
lower bound = 찾고자 하는 값 이상인 첫 idx
upper bound = 찾고자 하는 값을 초과하는 첫 idx

1 1 1 2 2 2 2 3 5 에서 2
lower = 3
upper = 7

4 6 9 10 15 15 15 18 20  에서 12
low = 4
up = 4

15면 
low = 4
up = 7
-> insert를 할떄 넣을 수 있는 가장 앞과 가장 뒤의 개념

(N*N)lgN나와야 N=1000에서 2초안에 해결 가능
A,B로 각각 부분합을 만들고(N) 그걸 이용해서 나올수 있는 모든 구간의 합을 list로 낸다 -> N*N
경우의 수를 세야 하므로 중복 따로 생각 안해도 된다

부분합 {for i=1~N {for j=i+1~N}}

7453과 비슷
*/

#include<iostream>
using namespace std;

int main() {



	return 0;
}