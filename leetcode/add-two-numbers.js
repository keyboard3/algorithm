/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
  let prev = null, head = null;
  let up = 0;
  while (l1 || l2) {
    let num = up + (l1?.val || 0) + (l2?.val || 0);
    up = num >= 10 ? 1 : 0;
    num = num % 10;
    let node = new ListNode(num);
    if (!prev) head = prev = node;
    else prev.next = node;
    prev = node;
    l1 = l1?.next;
    l2 = l2?.next;
  }
  if (up > 0) prev.next = new ListNode(up);
  return head;
};