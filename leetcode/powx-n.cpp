#include "iostream"
using namespace std;

class Solution
{
public:
    double myPow(double x, long long n)
    {

        return n > 0 ? pow(x, n) : 1 / pow(x, -n);
    }
    double pow(double x, long long n)
    {
        double y = x, ans = 1;
        while (n > 0)
        {
            if (n % 2 == 1)
                ans *= y; //核心多余 1->2->4 = 2*4*16 = 2^7 = 128
            n = n / 2;
            y *= y;
        }
        return ans;
    }
};

int main()
{
    auto sol = new Solution();
    auto res = sol->myPow(2, 10);
    cout << res << endl;
}

//  7->3->1->0
//  1->1*[2]->(2*2)*[2]->(([2]*[2])*[2])*(([2]*[2])*[2])*[2]
//  查看规律发现奇数的多余计算是反向规律的
//  7->3->1->0
//  1->2->4 = 2*4*16 = 2^7 = 128