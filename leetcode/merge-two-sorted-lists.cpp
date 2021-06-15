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
class Solution
{
public:
  //递归版本
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    if (!l1)
      return l2;
    if (!l2)
      return l1;
    ListNode *l3;
    if (l1->val < l2->val)
      l3 = l1, l1 = l1->next;
    else
      l3 = l2, l2 = l2->next;
    l3->next = mergeTwoLists(l1, l2);
    return l3;
  }
  //循环下一个
  ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2)
  {
    ListNode *empty = new ListNode(INT_MAX);
    ListNode *l3, *h3;
    h3 = l3 = new ListNode(0);
    while (l1 != nullptr || l2 != nullptr)
    {
      ListNode *temp;
      int v1 = l1 == nullptr ? INT_MAX : l1->val;
      int v2 = l2 == nullptr ? INT_MAX : l2->val;
      if (v1 < v2)
        temp = l1, l1 = l1->next;
      else
        temp = l2, l2 = l2->next;
      l3 = l3->next = temp;
    }
    return h3->next;
  }
};