#include "vector"
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