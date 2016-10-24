#include <iostream>
#include <queue>
#include <time.h>
#include <vector>
#include <math.h>
struct Points{
    int x;
    int y;
    Points() {}; //need a default constructor if another constructor has it has the member variable.
    Points(int x, int y) {
        this->x = x;
        this->y = y;
    }
};
struct comparator {
    comparator(Points pt) {
        origin = pt;
    }
    bool operator() (const Points &pt1, const Points &pt2) const {
        int length1 = pow(pt1.x - origin.x, 2) + pow(pt1.y - origin.y, 2);
        int length2 = pow(pt2.x - origin.x, 2) + pow(pt2.y - origin.y, 2);
        return length1 > length2;
    }
    Points origin;
};
std::vector<Points> kNearestPoints(std::vector<Points> input, Points origin, int k) {
    comparator comp(origin);
    std::priority_queue<Points, std::vector<Points>, comparator> pq(comp);
    for (int i = 0; i < input.size(); i++) {
        pq.push(input[i]);
    }
    std::vector<Points> ret;
    for (int i = 0; i < k; i++) {
        ret.push_back(pq.top());
        pq.pop();
    }
    return ret;
}
int main() {
    int size = 10;
    srand((uint16_t)time(NULL));
    std::vector<Points> input;
    for (int i = 0; i < size; i++) {
        input.push_back(Points(rand() % 10, 0));
        std::cout << input.back().x << " " << input.back().y << "\n";
    }
    Points origin(0, 0);
    std::cout << "Results are: \n";
    std::vector<Points> result = kNearestPoints(input, origin, 5);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i].x << " " << result[i].y << "\n";
    }
    return 0;
}