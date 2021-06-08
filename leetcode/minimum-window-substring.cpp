#include "string"
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int tArray[128] = {0};
        int sArray[128] = {0};
        for (char chr : t)
        {
            tArray[chr]++;
        }
        int l = -1, r = -1;
        int ml = 0, mr = s.length();
        int rEnd = s.length() - 1;
        while (r < rEnd)
        {
            r++;
            char chr = s[r];
            if (tArray[chr] == 0)
                continue;
            sArray[chr]++;
            if (!check(tArray, sArray))
                continue;

            int lEnd = r - t.length() + 1;
            while (l < lEnd)
            {
                l++;
                int chr = s[l];
                if (tArray[chr] == 0)
                    continue;
                sArray[chr]--;
                if (sArray[chr] < tArray[chr])
                {
                    if (r - l < mr - ml)
                    {
                        mr = r, ml = l;
                    }
                    break;
                }
            }
        }
        if (l == -1)
            return "";
        return s.substr(ml, mr - ml + 1);
    }
    bool check(int *tArray, int *sArray)
    {
        for (int i = 0; i < 128; i++)
            if (sArray[i] < tArray[i])
                return false;
        return true;
    }
};