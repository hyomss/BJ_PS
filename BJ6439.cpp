/*
틀림. 풀이 확인
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair <pair <double, double>, pair <double, double>> line;
pair<int, int> sq[4];

int x_left, y_top, x_right, y_bot;
void make_sq() {
	if (x_left < x_right) {
		if (y_top < y_bot)
			swap(y_top, y_bot);
	}
	else {
		swap(x_left, x_right);
		if (y_top < y_bot)
			swap(y_top, y_bot);
	}
	sq[0] = make_pair(x_left, y_bot);
	sq[1] = make_pair(x_right, y_bot);
	sq[2] = make_pair(x_right, y_top);
	sq[3] = make_pair(x_left, y_top);
}


int CCW(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3)
{
	int op = p1.first * p2.second + p2.first*p3.second + p3.first*p1.second;
	op -= (p1.first*p3.second + p2.first*p1.second + p3.first*p2.second);

	if (op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}

bool CheckIntersect(int a, int b)
{
	pair<int, int> p1 = line.first;
	pair<int, int> p2 = line.second;
	pair<int, int> p3 = sq[a];
	pair<int, int> p4 = sq[b];
/*
	cout << "점들" << endl;
	cout << p1.first << p1.second << " "<< p2.first << p2.second << endl;
	cout << p3.first << p3.second << " " << p4.first << p4.second << endl;
*/
	int line1_2 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
	int line2_1 = CCW(p3, p4, p1) * CCW(p3, p4, p2);

	if (line1_2 == 0 && line2_1 == 0)
	{
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);

		return p1 <= p4 && p3 <= p2;
	}
	return line1_2 <= 0 && line2_1 <= 0;
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> line.first.first >> line.first.second >> line.second.first >> line.second.second;
		cin >> x_left >> y_top >> x_right >> y_bot;

		make_sq();

		sq[4] = sq[0];
		for (int i = 0; i < 4; i++) {
			if (CheckIntersect(i, i + 1)) {
				cout << "T" << endl;
				return 0;
			}
		}

		// 스왑한채로 진행 한되게 맨 아래에 둠
		if (line.first.first > line.second.first) swap(line.first.first, line.second.first);
		if (line.first.second > line.second.second) swap(line.first.second, line.second.second);
		if (x_left <= line.first.first && line.second.first <= x_right && y_bot <= line.first.second && line.second.second <= y_top) {
			cout << "T" << endl;
			return 0;
		}
		cout << "F" << endl;
	}
 
	return 0;
}