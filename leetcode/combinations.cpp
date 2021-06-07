#include "vector"
using namespace std;

class Solution
{
public:
    vector<vector<int>> array;
    vector<int> list;
    int tNum;
    vector<vector<int>> combine(int n, int k)
    {
        tNum = k;
        array.empty();
        list.empty();
        handleArray(1, n);
        return array;
    }
    void handleArray(int start, int end)
    {
        if (list.size() == tNum)
        {
            array.push_back(list);
            return;
        }
        if (list.size() + end - start + 1 < tNum)
            return;
        for (int i = start; i <= end; i++)
        {
            list.push_back(i);
            handleArray(i + 1, end);
            list.pop_back();
        }
    }
};