#include "string"
using namespace std;

const pair<int, string> intRomanMap[] = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"},
};

class Solution
{
public:
  string intToRoman(int num)
  {
    string romanStr = "";
    for (const auto &[value, roman] : intRomanMap)
    {
      while (num >= value)
      {
        num -= value;
        romanStr += roman;
      }
      if (num == 0)
        break;
    }
    return romanStr;
  }
};