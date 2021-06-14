#include "vector"
#include "climits"
#include "cmath"
using namespace std;
class Solution
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    int minTarget = INT_MAX / 2;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int l = i + 1, r = nums.size() - 1;
      while (l < r)
      {
        int res = nums[i] + nums[l] + nums[r];
        if (abs(target - minTarget) > abs(target - res))
          minTarget = res;
        if (res - target > 0)
        {
          while (l < r && nums[r] == nums[r - 1])
            r--;
          r--;
        }
        else
        {
          while (l < r && nums[l] == nums[l + 1])
            l++;
          l++;
        }
      }
    }
    return minTarget;
  }
};