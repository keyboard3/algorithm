#include "vector"
#include "map"
#include "iostream"
using namespace std;
/**
 * 尝试用map的原生方法比[]索引用法要快
 * 但是用索引语义更加清晰
 */
map<int, int> showed;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        showed.clear();
        for (int i = 0; i < nums.size(); i++)
        {
            int item = nums[i];
            if (showed[target - item] != 0)
                return vector({showed[target - item] - 1, i});
            showed[item] = i + 1; //为了规避默认值0
        }
        return nums; //随便返回啥，这题保证有
    }
};
