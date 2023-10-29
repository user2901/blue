#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};

bool cmp(Point A, Point B) {
    if (A.x == B.x && A.y < B.y || A.x < B.x) return true;
    return false;
}

int main() {
    vector<Point> a(8);
    for (int i = 0; i < 8; i++) cin >> a[i].x >> a[i].y;
    
    sort(a.begin(), a.end(), cmp);
    if (a[0].x == a[1].x && a[1].x == a[2].x && a[2].x != a[3].x && a[3].x == a[4].x && a[4].x != a[5].x && a[5].x == a[6].x && a[6].x == a[7].x && a[0].y == a[3].y && a[3].y == a[5].y && a[5].y != a[1].y && a[1].y == a[6].y && a[6].y != a[2].y && a[2].y == a[4].y && a[4].y == a[7].y)
        cout << "respectable";
    else cout << "ugly";
    return 0;
}