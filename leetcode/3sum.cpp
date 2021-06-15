#include "vector"
#include "map"
#include "climits"
#include "string"
using namespace std;
class Solution
{
public:
  //枚举出左侧的负数之后，然后所有满足0的解呈现两端向内收缩的趋势
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> result;
    if (nums.size() < 3)
      return result;
    sort(nums.begin(), nums.end());
    int target = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > target)
        return result;
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int l = i + 1, r = nums.size() - 1;
      while (l < r)
      {
        int res = nums[i] + nums[l] + nums[r];
        if (res == target)
        {
          result.push_back(vector({nums[i], nums[l], nums[r]}));
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
    return result;
  };
  //通过去重之后，负数区枚举两个在正数区找第3个。正数区枚举两个，找负数区第3个。这种自然的处理就不会导致重复加入结果
  vector<vector<int>> threeSum1(vector<int> &nums)
  {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    map<int, int> showNumMap;
    vector<int> distNums;
    for (int i = 0; i < nums.size(); i++)
    {
      int times = 0;
      if (showNumMap.find(nums[i]) != showNumMap.end())
        times = showNumMap.at(nums[i]);
      showNumMap.erase(nums[i]);
      showNumMap.emplace(nums[i], times + 1);
      if (times == 0)
        distNums.push_back(nums[i]);
    }
    auto append = [&](int &firstVal, int &secondVal)
    {
      int threeVal = -firstVal - secondVal;
      if (showNumMap.find(threeVal) == showNumMap.end())
        return;
      result.push_back(vector({firstVal, secondVal, threeVal}));
    };
    auto appendSame = [&](int &firstVal)
    {
      int times = showNumMap.at(firstVal);
      if (times <= 1 || (firstVal == 0 && times < 3))
        return;
      append(firstVal, firstVal);
    };
    //正数区枚举
    int first = 0;
    for (; first < distNums.size() && distNums[first] < 0; first++)
    {
      appendSame(distNums[first]);
      for (int second = first + 1; second < distNums.size() && distNums[second] < 0; second++)
        append(distNums[first], distNums[second]);
    }

    //负数区枚举
    for (; first < distNums.size(); first++)
    {
      appendSame(distNums[first]);
      for (int second = first + 1; second < distNums.size(); second++)
        append(distNums[first], distNums[second]);
    }
    return result;
  };
  //一个数通过Map映射查找，另外两个数通过枚举组合。并特殊处理高重复的元素情况
  vector<vector<int>> threeSum2(vector<int> &nums)
  {
    vector<vector<int>> result;
    if (nums.size() < 3)
      return result;

    sort(nums.begin(), nums.end());
    vector<int> newNums;

    int prev = INT_MAX, sameNum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (prev == nums[i])
      {
        sameNum++;
        if (sameNum > 3)
          continue;
      }
      else
        sameNum = 0;
      prev = nums[i];
      newNums.push_back(nums[i]);
    }
    map<int, vector<int>> numMap;
    for (int i = 0; i < newNums.size(); i++)
    {
      vector<int> array;
      if (numMap.find(newNums[i]) != numMap.end())
        array = numMap.at(newNums[i]);
      array.push_back(i);
      numMap.erase(newNums[i]);
      numMap.emplace(newNums[i], array);
    }

    map<string, bool> showedMap;
    for (int i = 0; i < newNums.size() - 2; i++)
      for (int j = i + 1; j < newNums.size() - 1; j++)
      {
        vector<int> third;
        if (numMap.find(-newNums[i] - newNums[j]) != numMap.end())
          third = numMap.at(-newNums[i] - newNums[j]);
        if (third.size() == 0)
          continue;

        vector ele({newNums[i],
                    newNums[j],
                    -newNums[i] - newNums[j]});
        sort(ele.begin(), ele.end());
        string key = to_string(ele[0]) + "," + to_string(ele[1]) + "," + to_string(ele[2]);
        if (showedMap.find(key) != showedMap.end())
        {
          continue;
        }

        for (int t = 0; t < third.size(); t++)
        {
          if (third[t] <= j)
            continue;
          showedMap.emplace(key, true);
          result.push_back(ele);
          break;
        }
      }
    return result;
  };
};