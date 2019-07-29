// https://onecoke.tistory.com/entry/%EC%84%A0%EB%B6%84-%EA%B5%90%EC%B0%A8-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-CCW-%EC%9D%B4%EC%9A%A9
//  x1y2 + x2y3 + x3y1 - x1y3 - x2y1 - x3y2

int CCW(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3)
{
	int op = p1.first * p2.second + p2.first*p3.second + p3.first*p1.second;
	op -= (p1.first*p3.second + p2.first*p1.second + p3.first*p2.second);

	if (op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}

bool CheckIntersect(int line1, int line2)
{
	pair<int, int> p1 = v[line1].first;
	pair<int, int> p2 = v[line1].second;
	pair<int, int> p3 = v[line2].first;
	pair<int, int> p4 = v[line2].second;

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