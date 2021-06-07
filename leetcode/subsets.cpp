#include "vector";
using namespace std;

class Solution
{
public:
  vector<vector<int>> arrays;
  vector<int> subArray;
  vector<vector<int>> subsets(vector<int> &nums)
  {
    arrays.clear();
    subArray.clear();
    dfs(nums, 0, nums.size());
  }
  void dfs(vector<int> &nums, int start, int end)
  {
    arrays.push_back(subArray);
    for (int i = start; i < end; i++)
    {
      subArray.push_back(nums[i]);
      dfs(nums, i + 1, end);
      subArray.pop_back();
    }
  }
};