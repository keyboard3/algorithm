//1232321
//1->2->3->2->3->2->1
//1*10*10+2*10+3 1232
//123 1232 => 123 1232 => hadX x
class Solution
{
public:
  bool isPalindrome(int x)
  {
    if (x < 0)
      return false;
    if (x <= 9)
      return true;

    int hadX = 0;
    while (x != 0)
    {
      int num = x % 10;
      x = x / 10;
      hadX = hadX * 10 + num;

      if (hadX == 0 || hadX > x)
        return false;
      if (hadX == x || hadX == x / 10)
        return true;
    }
    return false;
  }
};