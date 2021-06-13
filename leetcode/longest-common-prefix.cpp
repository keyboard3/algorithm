#include "string"
using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    for (int i = 0; i < 200; i++)
    {
      if (i >= strs[0].size())
        return strs[0].substr(0, i);
      char chr = strs[0][i];
      for (int j = 1; j < strs.size(); j++)
        if (i >= strs[j].size() || chr != strs[j][i])
          return strs[0].substr(0, i);
    }
    return "";
  }
};