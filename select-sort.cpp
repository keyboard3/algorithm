#include "iostream"
using namespace std;
/**
 * 在数组的无序区域找到最小和最大的，然后和无序区域的第一个位置交换
 * 不断缩小遍历的无序数组，直到至空集
**/
void sort(int *array, int len, bool asc)
{
    for (int i = 0; i < len; i++)
    {
        int compIndex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (array[compIndex] > array[j] && asc)
                compIndex = j;
            if (array[compIndex] < array[j] && !asc)
                compIndex = j;
        }
        swap(array[i], array[compIndex]);
    }
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int len = 5;
    int array[5] = {3, 6, 9, 1, 4};
    sort(array, len, true);
    for (int i = 0; i < len; i++)
        cout << array[i] << endl;
}