class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int mArea = 0;
    for (int i = 0; i < height.size(); i++)
      for (int j = height.size() - 1; j > i; j--)
      {
        if (height[j] < height[i])
          continue;

        int area = height[i] * (j - i);
        if (area > mArea)
          mArea = area;
        break;
      }
    for (int i = height.size() - 1; i >= 0; i--)
      for (int j = 0; j < i; j++)
      {
        if (height[j] < height[i])
          continue;

        int area = height[i] * (i - j);
        if (area > mArea)
          mArea = area;
        break;
      }
    return mArea;
  }
};