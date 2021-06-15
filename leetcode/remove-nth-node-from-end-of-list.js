/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
  let array = [];
  let emptyHead = new ListNode(null, head);
  let node = emptyHead;
  while (node) {
    array.push(node);
    node = node.next;
  }
  let cur = array[array.length - n];
  let prev = array[array.length - n - 1];
  prev.next = cur.next;
  return emptyHead.next;
};