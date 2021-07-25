#include "vector"
#include "climits"
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  //堆排序查找
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    ListNode *newList = new ListNode();
    ListNode *curNewNode = newList;
    //为每个列表都加上一个空头
    for (int i = 0; i < lists.size(); i++)
    {
      ListNode *emptyHead = new ListNode();
      emptyHead->next = lists[i];
      lists[i] = emptyHead;
    }
    //原地建堆，数据从前到后，从下到上构建
    for (int i = 1; i < lists.size(); i++)
      adjustHeapTail(i + 1, lists);

    while (1)
    {
      //堆首取最小
      ListNode *smallList = lists[0];

      if (smallList == nullptr || smallList->next == nullptr)
        break;
      //将这个最小的头的第一个元素追加到新链表的末尾
      curNewNode->next = smallList->next;
      curNewNode = curNewNode->next;
      //然后从旧链表中删除它
      smallList->next = smallList->next->next;

      //堆排序调整
      adjustHeapRoot(lists);
    }
    return newList->next;
  }
  void adjustHeapTail(int len, vector<ListNode *> &lists)
  {
    if (len <= 1)
      return;
    //升序排列
    int pi = len / 2 - 1;
    if (isMatch(lists, pi, len - 1))
    {
      swapHeap(lists, pi, len - 1);
      adjustHeapTail(pi + 1, lists);
    }
  }
  void adjustHeapRoot(vector<ListNode *> &lists)
  {
    int pi = 0;
    while (pi < lists.size())
    {
      int lci = (pi + 1) * 2 - 1;
      int rci = (pi + 1) * 2;
      bool lAct = isMatch(lists, pi, lci);
      bool rAct = isMatch(lists, pi, rci);
      int ci = 0;
      if (lAct && rAct)
      {
        ci = lci;
        if (isMatch(lists, lci, rci))
          ci = rci;
      }
      else if (lAct)
        ci = lci;
      else if (rAct)
        ci = rci;
      if (ci <= 0)
        break;
      swapHeap(lists, pi, ci);
      pi = ci;
    }
  }
  bool isMatch(vector<ListNode *> &lists, int pi, int ci)
  {
    if (pi >= lists.size() || ci >= lists.size())
      return false;
    if (lists[ci]->next == nullptr)
      return false;
    return valByHead(lists[pi]) > valByHead(lists[ci]);
  }
  int valByHead(ListNode *head)
  {
    if (head->next == nullptr)
      return INT_MAX;
    return head->next->val;
  }
  void swapHeap(vector<ListNode *> &lists, int pi, int ci)
  {
    ListNode *temp = lists[pi];
    lists[pi] = lists[ci];
    lists[ci] = lists[pi];
  }
  //简单的遍历查找最小头
  ListNode *mergeKLists2(vector<ListNode *> &lists)
  {
    ListNode *newList = new ListNode();
    ListNode *curNewNode = newList;
    //为每个列表都加上一个空头
    for (int i = 0; i < lists.size(); i++)
    {
      ListNode *emptyHead = new ListNode();
      emptyHead->next = lists[i];
      lists[i] = emptyHead;
    }
    while (1)
    {
      ListNode *smallList = nullptr;
      //找到所有链表中最小的头
      for (auto list : lists)
      {
        if (smallList == nullptr && list->next != nullptr)
        {
          smallList = list;
          continue;
        }
        if (list->next == nullptr)
          continue;
        if (list->next->val > smallList->next->val)
          continue;
        smallList = list;
      }
      if (smallList == nullptr || smallList->next == nullptr)
        break;
      //将这个最小的头的第一个元素追加到新链表的末尾
      curNewNode->next = smallList->next;
      curNewNode = curNewNode->next;
      //然后从旧链表中删除它
      smallList->next = smallList->next->next;
    }
    return newList->next;
  }
};