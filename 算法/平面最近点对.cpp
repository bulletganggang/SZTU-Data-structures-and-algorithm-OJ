#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int Inf = 0x7f7f7f;

struct Point {
	double x;
	double y;
	int id;
};

Point point[200005];
int temp[300005];
int a = Inf, b = Inf, ans = Inf;

double distance(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool compareX(Point a, Point b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

bool compareY(int a, int b) {
	return point[a].y < point[b].y;
}

void update(int new_a, int new_b, int new_ans) {
	if (new_a > new_b) {
		swap(new_a, new_b);
	}
	if (new_ans == ans) {
		if (a > new_a || (a == new_a && b > new_b)) {
			a = new_a;
			b = new_b;
		}
	} else {
		a = new_a;
		b = new_b;
		ans = new_ans;
	}
}

void minimumDistance(int left, int right) {
	if (left == right) {
		return;
	}
	if (left + 1 == right) {
		int cur = distance(point[left], point[right]);
		if (ans >= cur) {
			update(point[left].id, point[right].id, cur);
		}
		return;
	}
	int mid = (left + right) >> 1;
	minimumDistance(mid, right);
	minimumDistance(left, mid - 1);
	int k = 0;
	for (int i = left; i <= right; i++) {
		if (fabs(point[mid].x - point[i].x) <= ans) {
			temp[++k] = i;
		}
	}
	sort(temp + 1, temp + k + 1, compareY);
	for (int i = 1; i <= k; i++) {
		for (int j = i + 1; j <= k && point[temp[j]].y - point[temp[i]].y <= ans; j++) {
			if (ans >= distance(point[temp[i]], point[temp[j]])) {
				int new_distance = distance(point[temp[i]], point[temp[j]]);
				update(point[temp[i]].id, point[temp[j]].id, new_distance);
			}
		}
	}
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> point[i].x >> point[i].y;
		point[i].id = i - 1;
	}
	sort(point + 1, point + n + 1, compareX);
	minimumDistance(1, n);
	cout << a << " " << b;
	return 0;
}
