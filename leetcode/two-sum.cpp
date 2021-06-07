#include "vector"
#include "map"
using namespace std;

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
            if (showed.find(target - item) != showed.end())
            {
                result.push_back(showed.at(target - item));
                result.push_back(i);
                break;
            }
            showed.emplace(item, i);
        }
        return result;
    }
};