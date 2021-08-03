#include "iostream"
using namespace std;
/**
 * 通过遍历无序数组，对比交换将最大/最小移动到最后面
 * 不断缩小遍历的无序数组，直到至空集
**/
void sort(int *array, int len, bool asc)
{
    for (int i = 0; i < len; i++)
        for (int j = 1; j < len - i; j++)
        {
            if (array[j - 1] > array[j] && asc)
                swap(array[j - 1], array[j]);
            if (array[j - 1] < array[j] && !asc)
                swap(array[j - 1], array[j]);
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
    sort(array, len, false);
    for (int i = 0; i < len; i++)
        cout << array[i] << endl;
}