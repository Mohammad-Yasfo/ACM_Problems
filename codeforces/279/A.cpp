/*
A. Point on Spiral
time limit per test
2 seconds
memory limit per test
256 megabytes
input
standard input
output
standard output

Valera the horse lives on a plane. The Cartesian coordinate system is defined on this plane. Also an infinite spiral is painted on the plane. The spiral consists of segments: [(0, 0), (1, 0)], [(1, 0), (1, 1)], [(1, 1), ( - 1, 1)], [( - 1, 1), ( - 1,  - 1)], [( - 1,  - 1), (2,  - 1)], [(2,  - 1), (2, 2)] and so on. Thus, this infinite spiral passes through each integer point of the plane.

Valera the horse lives on the plane at coordinates (0, 0). He wants to walk along the spiral to point (x, y). Valera the horse has four legs, so he finds turning very difficult. Count how many times he will have to turn if he goes along a spiral from point (0, 0) to point (x, y).
Input

The first line contains two space-separated integers x and y (|x|, |y| ≤ 100).
Output

Print a single integer, showing how many times Valera has to turn.
Sample test(s)
Input

0 0

Output

0

Input

1 0

Output

0

Input

0 1

Output

2

Input

-1 -1

Output

3
*/
include <iostream>
using namespace std;
struct point
{
    int x;
    int y;
    void operator=(point l2)
    {
        x = l2.x;
        y = l2.y;
    }
};
bool is_on_line(point p, point l1, point l2)
{
    if (l1.x == l2.x&&l1.x==p.x
        && (l1.y <= p.y && p.y <= l2.y || l2.y <= p.y && p.y <= l1.y))
        return true;
    if (l1.y == l2.y&&l1.y==p.y
        && (l1.x <= p.x && p.x <= l2.x || l2.x <= p.x && p.x <= l1.x))
        return true;
    return false;
}

int main()
{
    int sum = 0, increase = 0;
    bool is_vertical = false;
    point p;
    point l1, l2;
    l1.x = l1.y = l2.y = 0;
    l2.x = 1;
    cin >> p.x >> p.y;
    if (is_on_line(p, l1, l2))
    {
        cout << 0 << endl;
        return 0;
    }
    l1 = l2;
    l2.y = 1;
    ++sum;
    while (!is_on_line(p, l1, l2))
    {
        l1 = l2;
        if (l2.x == l2.y && l2.x < 0)
            increase = 1;
        if (!is_vertical)
        {
            l2.x *= -1;
            if (increase > 0)
            {
                l2.x++;
                increase++;
            }
        }
        else
        {
            l2.y *= -1;
            if (increase > 0)
            {
                l2.y++;
                increase++;
            }
        }
        is_vertical=!is_vertical;
        increase %= 3;
        ++sum;
    }
    cout<<sum<<endl;
    return 0;
}