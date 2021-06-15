#include "string"
#include "map"
#include "vector"
using namespace std;

const map<char, string> numMap({
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
});
class Solution
{
public:
  //广度优先组合
  vector<string> letterCombinations(string digits)
  {
    vector<string> prevList;
    if (digits.length() == 0)
      return prevList;
    prevList.push_back("");
    for (auto num : digits)
    {
      vector<string> list;
      for (auto prev : prevList)
        for (auto chr : numMap.at(num))
          list.push_back(prev + chr);
      prevList = list;
    }
    return prevList;
  }
  //深度优先组合
  vector<string> result;
  vector<string> letterCombinations2(string digits)
  {
    result.clear();
    if (digits.length() == 0)
      return result;
    dfs(digits, "", 0);
    return result;
  }
  void dfs(string &digits, string res, int index)
  {
    if (index >= digits.length())
    {
      result.push_back(res);
      return;
    }
    for (auto chr : numMap.at(digits[index]))
      dfs(digits, res + chr, index + 1);
  }
};