#include "string"
#include "iostream"
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int len = 0, maxLen = 0;
    auto check = [&len, &maxLen, &s](char chr, int end) -> void
    {
      for (int i = end - len; i < end; i++)
      {
        if (s[i] != chr)
          continue;
        if (len > maxLen)
          maxLen = len;
        len = end - i - 1;
      }
    };
    for (int i = 0; i < s.length(); i++)
    {
      check(s[i], i);
      len++;
    }
    if (len > maxLen)
      maxLen = len;
    return maxLen;
  }
};