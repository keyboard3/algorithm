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
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int item = nums[i];
            if (showed[target - item] != 0)
            {
                result.push_back(showed[target - item] - 1); //修正
                result.push_back(i);
                break;
            }
            showed[item] = i + 1; //为了规避默认值0
        }
        return result;
    }
};
