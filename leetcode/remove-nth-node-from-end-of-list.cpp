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
  //用双指针，保持前后指针是n个长度。当后面的指针移动到末尾时，后面的指针自然指向了倒数节点
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    int distance = 0;
    ListNode *emptyHead = new ListNode(0, head);
    ListNode *tailNode = emptyHead, *prevNode = emptyHead;
    while (tailNode->next)
    {
      distance++;
      tailNode = tailNode->next;
      if (distance >= n + 1) //跟上第n+1步
        prevNode = prevNode->next;
    }
    prevNode->next = prevNode->next->next;
    return emptyHead->next;
  }
  //遍历按序存下索引，然后直接访问倒数n个元素做删除节点就行
  ListNode *removeNthFromEnd2(ListNode *head, int n)
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