#include "vector"
#include "string"
#include "stack"
#include "set"
using namespace std;
class Solution
{
public:
  /**
 * 枚举出所有可能，然后判断将有效的统计进来
 */
  vector<string> generateParenthesis(int n)
  {
    vector<string> result;
    dfs(0, n, "", result);
    return result;
  }
  void dfs(int times, int limit, string parenthes, vector<string> &result)
  {
    if (times >= limit)
    {
      if (isParenthesis(parenthes))
        result.push_back(parenthes);
      return;
    }
    dfs(times + 1, limit, parenthes + "()", result);
    dfs(times + 1, limit, parenthes + "((", result);
    dfs(times + 1, limit, parenthes + ")(", result);
    dfs(times + 1, limit, parenthes + "))", result);
  }
  bool isParenthesis(string parenthes)
  {
    stack<char> leftStack;
    if (parenthes[0] == ')' || parenthes[parenthes.length() - 1] == '(')
      return false;
    for (auto item : parenthes)
    {
      if (item == '(')
        leftStack.push(item);
      else if (item == ')' && leftStack.size() > 0)
        leftStack.pop();
      else
        return false;
    }
    return leftStack.size() == 0;
  }
  /**
 * 在前面的有效状态中推断出当前有效状态
 */
  vector<string> generateParenthesis2(int n)
  {
    vector<string> zero;
    zero.push_back("()");
    vector<vector<string>> states;
    states.push_back(zero);
    for (int curN = 2; curN <= n; curN++)
    {
      set<string> state;
      //加外部()
      for (int i = 0; i < states[curN - 2].size(); i++)
        state.emplace("(" + states[curN - 2][i] + ")");
      //组合之前状态
      for (int i = 1; i <= curN; i++)
        add(state, states[i - 1], states[curN - i - 1]);
      states.push_back(vector(state.begin(), state.end()));
    }
    return states[n - 1];
  }
  void add(set<string> result, vector<string> leftArray, vector<string> rightArray)
  {
    for (auto lit : leftArray)
      for (auto rit : rightArray)
        result.emplace(lit + rit);
  }
};