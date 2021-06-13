
#include "string"
using namespace std;

const pair<string, int> romanIntMap[] = {
    {"M", 1000},
    {"CM", 900},
    {"D", 500},
    {"CD", 400},
    {"C", 100},
    {"XC", 90},
    {"L", 50},
    {"XL", 40},
    {"X", 10},
    {"IX", 9},
    {"V", 5},
    {"IV", 4},
    {"I", 1},
};

class Solution
{
public:
  int romanToInt(string s)
  {
    int val = 0;
    for (const auto &[roman, intVal] : romanIntMap)
    {
      while (s.substr(0, roman.length()) == roman)
      {
        s = s.substr(roman.length(), s.length() - roman.length());
        val += intVal;
      }
      if (s.length() == 0)
        break;
    }
    return val;
  }
};