#include "iostream"
#include "vector"
using namespace std;
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int total = nums1.size() + nums2.size();
    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    double result = 0;
    auto next = [&result](vector<int>::iterator& it) -> int
    {
      int res = *it;
      it++;
      return res;
    };
    for (int i = 0; i < total; i++)
    {
      int v;
      if (it1 != nums1.end() && it2 == nums2.end())
        v = next(it1);
      else if (it2 != nums2.end() && it1 == nums1.end())
        v = next(it2);
      else if (*it1 < *it2)
        v = next(it1);
      else
        v = next(it2);

      int com=isMiddle(i, total);
      if (com > 0)
        break;
      if (com == 0)
        result += v;
    }
    return result / (total % 2 == 1 ? 1 : 2);
  }
  int isMiddle(int index, int total)
  {
    if (total % 2 == 1)
      return index - (total / 2) ;
    else
    {
      int lm = total / 2 - 1;
      if (index < lm)
        return -1;
      if (index > lm + 1)
        return 1;
      return 0;
    }
  }
};
// @lc code=end