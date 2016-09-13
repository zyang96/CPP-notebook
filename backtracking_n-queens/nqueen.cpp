#include <iostream>
#include <vector>
using namespace std;
//=========================================
// start from 0,0 to n-1, n-1
bool attacking(vector<int> pt1, vector<int> pt2) {
	if (pt1[0] == pt2[0] || pt1[1] == pt2[1]) {
		return true;
	}
	if (abs(pt1[0] - pt2[0]) == abs(pt1[1] - pt2[1])) {
		return true;
	}
	return false;
}

bool isValid(vector<int> p, vector<vector<int>> &points) {
	if (points.size() == 0) {
		return true;
	}
	int j;
	for (j = 0; j < points.size(); j++) {
		if (attacking(p, points[j])) {
			return false;
		}
	}
	return true;
}
void printGraph(vector<vector <int>> points) {
	for (int i = 0; i < points.size(); i++) {
		cout << points[i][0] << " " << points[i][1] << ", ";
	}
	cout << endl;
}
bool nqueen (int n, int level, vector<vector <int>> &points) {
	vector<int> p(2,level);
	for (int i = 0; i < n; i++) {
		p[1] = i;
		if (isValid(p, points)) {
			points.push_back(p);
			if (level == n-1 && points.size() == n) {
				printGraph(points);
				points.erase(points.end() - 1);
				continue;
			}
			if (level < n-1 && nqueen(n, level + 1, points)) {
				points.erase(points.end() - 1);
			}
		}
	}
	return true;
}
int main() {
	int n = 5;
	vector<vector<int>> points;
	bool finished;
	finished = nqueen(n, 0, points);
	return 0;
}