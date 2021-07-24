#include "vector"
#include "string"
#include "set"
using namespace std;
/**
 * 在前面的有效状态中推断出当前有效状态
 */
class Solution
{
public:
  vector<string> generateParenthesis(int n)
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
    return states[n-1];
  }
  void add(set<string> result, vector<string> leftArray, vector<string> rightArray)
  {
    for (auto lit : leftArray)
      for (auto rit : rightArray)
        result.emplace(lit + rit);
  }
};