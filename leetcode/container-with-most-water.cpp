#include "vector"
#include "cmath"
using namespace std;

class Solution
{
public:
  //优化方案，设定找到两端短边和长边，计算完面积之后，再以原来的长边作为短边继续向内找它的长边。
  int maxArea(vector<int> &height)
  {
    int minI = 0, maxI = height.size() - 1;
    int mArea = 0, direction = -1;
    int temp;
    auto swapI = [&]()
    {
      temp = minI;
      minI = maxI, maxI = temp;
      direction = -direction;
    };
    if (height[minI] > height[maxI])
      swapI();
    while (minI != maxI)
    {
      mArea = max(mArea, min(height[minI], height[maxI]) * abs(maxI - minI));
      if (height[maxI] >= height[minI])
        swapI();
      maxI += direction;
    }
    return mArea;
  }
  //不断枚举左边的为短边，从右边依次找到长边。在找长边的过程中同时可以间接计算面积更新。缺点是每次左边枚举值，右边就得从头匹配
  int maxArea2(vector<int> &height)
  {
    int mArea = 0;
    for (int i = 0; i < height.size(); i++)
      for (int j = height.size() - 1; j > i; j--)
      {
        if (height[j] < height[i])
        {
          mArea = max(height[j] * (j - i), mArea);
          continue;
        }
        mArea = max(height[i] * (j - i), mArea);
        break;
      }
    return mArea;
  }
};