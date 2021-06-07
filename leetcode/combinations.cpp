#include "vector"
using namespace std;

class Solution
{
public:
    vector<vector<int>> array;
    int tNum;
    vector<vector<int>> combine(int n, int k)
    {
        tNum = k;
        array.empty();
        vector<int> init;
        handleArray(init, 1, n);
        return array;
    }
    void handleArray(vector<int> list, int start, int end)
    {
        if (list.size() == tNum)
        {
            array.push_back(list);
            return;
        }
        for (int i = start; i <= end; i++)
        {
            vector<int> tempList = vector(list);
            tempList.push_back(i);
            handleArray(tempList, i + 1, end);
        }
    }
};