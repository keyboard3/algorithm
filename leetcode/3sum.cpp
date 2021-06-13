#include "vector"
#include "map"
#include "climits"
#include "string"
using namespace std;
class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> result;
    if(nums.size()<3) return result;
    
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
      } else sameNum = 0;
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
      numMap.emplace(newNums[i],array);
    }

    map<string, bool> showedMap;
    for (int i = 0; i < newNums.size()-2; i++)
      for (int j = i + 1; j < newNums.size()-1; j++)
      {
        vector<int> third;
        if (numMap.find(-newNums[i] - newNums[j]) != numMap.end())
          third = numMap.at(-newNums[i] - newNums[j]);
        if(third.size()==0) continue;

        vector ele({newNums[i],
                    newNums[j],
                    -newNums[i] - newNums[j]});
        sort(ele.begin(), ele.end());
        string key = to_string(ele[0]) + "," + to_string(ele[1]) + "," + to_string(ele[2]);
        if (showedMap.find(key) != showedMap.end()) {
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
  }
};