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
class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *emptyHead = new ListNode(0, head);
    ListNode *node = emptyHead;
    vector<ListNode *> nodeList;
    while (node)
    {
      nodeList.push_back(node);
      node = node->next;
    }
    ListNode *cur = nodeList[nodeList.size() - n];
    ListNode *prev = nodeList[nodeList.size() - n - 1];
    prev->next = cur->next;
    return emptyHead->next;
  }
};