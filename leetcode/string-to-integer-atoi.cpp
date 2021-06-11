#include "string"
#include "climits"
#include "iostream"
using namespace std;

class Solution
{
public:
  int myAtoi(string s)
  {
    int intMax = INT_MAX / 10, maxDigit = INT_MAX % 10;
    int intMin = INT_MIN / 10, minDigit = INT_MIN % 10;
    int result = 0, opt = 1;
    bool hadInit = false;
    for (int i = 0; i < s.length(); i++)
    {
      char chr = s[i];
      if (!(chr >= '0' && chr <= '9'))
      {
        if (!hadInit && (chr == '+' || chr == '-'))
        {
          opt = chr == '-' ? -1 : 1;
          hadInit = true;
          continue;
        }
        else if (!hadInit && chr == ' ')
          continue;
        break;
      }
      hadInit = true;
      //检查边界
      int tempResult = result * opt;
      if (tempResult > intMax) 
        return INT_MAX;
      else if (tempResult < intMin)
        return INT_MIN;
      if (tempResult == intMax || tempResult == intMin)
      {
        int nextNum = (chr - '0') * opt;
        if (nextNum >= maxDigit)
          return INT_MAX;
        if (nextNum <= minDigit)
          return INT_MIN;
      }

      result = result * 10 + (chr - '0');
    }
    if (!hadInit)
      return 0;
    return result * opt;
  }
};