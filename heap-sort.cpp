#include "iostream"
using namespace std;
//堆排序 数组方式记录完全二叉树的父子节点之间的关系
void sortArray(int len, int *array, bool isAsc);
void adjustHeapTail(int len, int *heap, bool isAsc);
void adjustHeapRoot(int len, int *heap, bool isAsc);
void printArray(int len, int *array)
{
  for (int i = 0; i < len; i++)
    cout << array[i] << ",";
  cout << endl;
}
int main()
{
  const int arraySize = 5;
  int array[arraySize] = {3, 4, 5, 1, 8};
  sortArray(arraySize, array, false);
  printArray(arraySize, array);
}
void sortArray(int len, int *array, bool isAsc)
{
  int heap[len];
  memcpy(&heap[0], &array[0], sizeof(int) * len);
  //原地建堆1：初始假设为空集的堆结构，然后不断从前向后引入数据,相当于底层招进的人然后通过申请到合适位置
  // for (int i = 1; i < len; i++)
  //   adjustHeapTail(i + 1, heap, isAsc);
  //原地建堆2：从下到上的逐步构建堆结构，假设是子节点符合堆结构，那么调整根节点就行
  for (int i = len - 1; i >= 0; i--)
  {
    //跳过子节点
    if (((i + 1) * 2) - 1 >= len)
      continue;
    adjustHeapRoot(len - i, &heap[0] + i, isAsc);
  }
  //排序
  for (int i = len - 1; i >= 0; i--)
  {
    //不断获取堆顶元素
    array[len - 1 - i] = heap[0];
    //将末尾的元素调至堆顶
    heap[0] = heap[i];
    //然后将堆顶数据逐步向下调整到合适位置
    adjustHeapRoot(i, heap, isAsc);
  }
}
void swapHeap(int *heap, int parentIndex, int childIndex)
{
  int temp = heap[parentIndex];
  heap[parentIndex] = heap[childIndex];
  heap[childIndex] = temp;
}
bool isMatch(int len, int *heap, bool isAsc, int parentIndex, int childIndex)
{
  if (parentIndex >= len || childIndex >= len)
    return false;
  return isAsc && heap[parentIndex] > heap[childIndex] || !isAsc && heap[parentIndex] < heap[childIndex];
}
//将末尾元素逐级调整
void adjustHeapTail(int len, int *heap, bool isAsc)
{
  if (len <= 1)
    return;
  int parentIndex = len / 2 - 1;
  if (isMatch(len, heap, isAsc, parentIndex, len - 1))
  {
    swapHeap(heap, parentIndex, len - 1);
    adjustHeapTail(parentIndex + 1, heap, isAsc);
  }
}
//将顶级元素逐级和子元素对比调整
void adjustHeapRoot(int len, int *heap, bool isAsc)
{
  int parentIndex = 0;
  while (parentIndex < len)
  {
    int lci = (parentIndex + 1) * 2 - 1;
    int rci = (parentIndex + 1) * 2;
    int lAct = isMatch(len, heap, isAsc, parentIndex, lci);
    int rAct = isMatch(len, heap, isAsc, parentIndex, rci);
    int childIndex = 0;
    if (lAct && rAct)
    {
      childIndex = lci;
      if (isMatch(len, heap, isAsc, lci, rci))
        childIndex = rci;
    }
    else if (lAct)
      childIndex = lci;
    else if (rAct)
      childIndex = rci;

    if (childIndex <= 0)
      break;
    swapHeap(heap, parentIndex, childIndex);
    parentIndex = childIndex;
  }
}