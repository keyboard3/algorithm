#include "string"
using namespace std;
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        string res;
        if (numRows <= 1)
            return s;
        for (int i = 0; i < numRows; i++)
        {
            string init = i == 0 ? s.substr(0, 1) : "";
            res += dfs(s, 0, numRows, i, init);
        }
        return res;
    }
    string &dfs(string &s, int start, int len, int pos, string &line)
    {
        if (start + pos >= s.length())
            return line;
        if (pos != 0)
            line += s[start + pos];
        return dfs(s, start + len - 1, len, len - 1 - pos, line);
    }
};
// @lc code=end