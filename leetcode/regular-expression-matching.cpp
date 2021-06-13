#include "string"
#include "vector"
using namespace std;

class Solution
{
public:
  bool isMatch(string s, string p)
  {
    vector<vector<bool>> state(p.length() + 1, vector<bool>(s.length() + 1));
    state[0][0] = true;
    auto matchs = [&](int pi, int si)
    {
      if (si == 0) //为了特殊处理边界.* c*等
        return false;
      return p[pi - 1] == '.' || p[pi - 1] == s[si - 1];
    };
    for (int pi = 1; pi <= p.length(); pi++)
    {
      if (p[pi - 1] == '*')
      {
        state[pi] = state[pi - 1];
        continue;
      }
      for (int si = 0; si <= s.length(); si++) //为了特殊处理边界.* c*等
      {
        if (pi < p.length() && p[pi] == '*')
        {
          state[pi][si] = state[pi - 1][si];
          if (matchs(pi, si))
            state[pi][si] = state[pi][si] || state[pi][si - 1];
        }
        else if (matchs(pi, si))
          state[pi][si] = state[pi - 1][si - 1];
      }
    }
    return state[p.length()][s.length()];
  }
  bool isMatch2(string s, string p)
  {
    return dfs(s, 0, p, 0);
  }
  bool dfs(string &s, int si, string &p, int pi)
  {
    if (si >= s.length() && pi >= p.length())
      return true;

    int range[2] = {1, 1};
    char matchChr = p[pi];
    if (pi + 1 < p.length() && p[pi + 1] == '*')
      range[0] = 0, range[1] = s.length() - si, pi += 2;
    else
      pi++;

    int matchNum = 0;
    do
    {
      if (matchNum == 0 && range[0] == 0 && dfs(s, si, p, pi))
        return true;
      if (si >= s.length())
        return false;

      if (matchChr == '.' || matchChr == s[si])
      {
        matchNum++;
        if (dfs(s, ++si, p, pi))
          return true;
      }
      else
        break;
    } while (matchNum < range[1]);
    return false;
  }
};