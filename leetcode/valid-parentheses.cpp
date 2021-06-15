#include "string"
#include "vector"
#include "map"
#include "stack"
using namespace std;

const string pairs[] = {"{}", "[]", "()"};
map<char, char> leftMap, rightMap;
void initMap()
{
  for (string pair : pairs)
  {
    leftMap.emplace(pair[0], pair[1]);
    rightMap.emplace(pair[1], pair[0]);
  }
}

class Solution
{
public:
  bool isValid(string s)
  {
    if (s.length() % 2 == 1)
      return false;
    stack<char> leftStack;
    initMap();

    for (int i = 0; i < s.length(); i++)
    {
      char chr = s[i];
      if (leftStack.size() > s.length() - i)
        return false;
        
      if (leftMap.find(chr) != leftMap.end())
        leftStack.push(chr);
      else if (rightMap.find(chr) != rightMap.end())
      {
        if (leftStack.empty())
          return false;
        char leftChr = leftStack.top();
        leftStack.pop();
        if (leftMap.at(leftChr) != chr)
          return false;
      }
    }
    return leftStack.empty();
  }
};