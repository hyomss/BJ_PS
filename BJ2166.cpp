/*
다각형 넓이 공식
https://darkpgmr.tistory.com/86
*/
#include <iostream>
#include <vector>
#include <math.h> // fabs 이용
using namespace std;

pair<long long, long long> p[10002];
int N;

double CCW(pair<long long, long long> &p1, pair<long long, long long> &p2, pair<long long, long long> &p3)
{
	double op = p1.first * p2.second + p2.first*p3.second + p3.first*p1.second;
	op -= (p1.first*p3.second + p2.first*p1.second + p3.first*p2.second);

	return op;
}

int main() {
	// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}


	double sum = 0;
	for (int i = 1; i < N - 1; i++) {
		sum += CCW(p[0], p[i], p[i + 1]);
	}

	sum = fabs(sum);

	printf("%.1lf", sum/2.0);


	return 0;
}