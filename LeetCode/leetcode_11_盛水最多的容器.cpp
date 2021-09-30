#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

int maxArea(vector<int> &height)
{
    int length = height.size();
    if (length <= 1) {
        return 0;
    }

    int left = 0;
    int right = length-1;
    int ans = 0;
    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        ans = max(ans, area);
        if (height[left] <= height[right]) {
            ++ left;
        } else {
            --right;
        }
    }
    return ans;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int res = maxArea(height);
    printf("%d\n", res);
    return 0;
}
