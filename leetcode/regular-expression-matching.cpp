#include "string"
using namespace std;

class Solution
{
public:
  bool isMatch(string s, string p)
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