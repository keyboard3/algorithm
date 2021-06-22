#include "vector"
using namespace std;

class Solution
{
public:
  //枚举出左侧两个数，然后所有满足0的解呈现两端向内收缩的趋势
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    vector<vector<int>> result;
    if (nums.size() < 4)
      return result;
    const int length = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < length - 3; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
        break;
      if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)
        continue;

      for (int j = i + 1; j < length - 2; j++)
      {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
          break;
        if (nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target)
          continue;

        int l = j + 1, r = length - 1;
        while (l < r)
        {
          int res = nums[i] + nums[j] + nums[l] + nums[r];
          if (res == target)
          {
            result.push_back(vector({nums[i], nums[j], nums[l], nums[r]}));
            while (l < r && nums[l] == nums[l + 1])
              l++;
            while (l < r && nums[r] == nums[r - 1])
              r--;
            l++, r--;
          }
          else if (res > target)
            r--;
          else
            l++;
        }
      }
    }
    return result;
  }
};