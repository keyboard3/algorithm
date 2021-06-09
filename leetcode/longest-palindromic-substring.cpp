#include "string"
using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    int ms = 0, me = 0;
    for (int i = 0; i < s.length(); i++)
    {
      int start = i - 1, end = i + 1;
      auto expand = [&]()
      {
        while (start >= 0 && end < s.length())
        {
          if (s[start] != s[end])
            break;
          if (end - start > me - ms)
          {
            ms = start;
            me = end;
          }
          start--;
          end++;
        };
      };
      expand();
      start = i, end = i + 1;
      expand();
    }
    return s.substr(ms, me - ms + 1);
  }
};