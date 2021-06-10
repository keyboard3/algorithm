#include "climits"
using namespace std;
/* 
 * 123
 * 3->2->1
 * 3->(3)*10+2->((3*10+2)*10+1
 * 在拆解数字的过程中就可以递推出结果的部分
 * 只能在32位只能判断是否溢出
 * 2147483647
 * 214748364*10+7<214748364*10+9
 */
class Solution
{
public:
  int reverse(int x)
  {
    int intMax = INT_MAX / 10;
    int intMin = INT_MIN / 10;
    int digit = 0;
    int result = 0;
    while (x != 0)
    {
      digit = x % 10;
      if (result > intMax || result < intMin)
        return 0;
      //在溢出计算之前做判断
      result = result * 10 + digit;
      x = x / 10;
    }
    return result;
  }
};