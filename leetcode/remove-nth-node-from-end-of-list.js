/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
function ListNode(val, next) {
  this.val = (val === undefined ? 0 : val)
  this.next = (next === undefined ? null : next)
}
//用双指针，保持前后指针是n个长度。当后面的指针移动到末尾时，后面的指针自然指向了倒数节点
var removeNthFromEnd = function (head, n) {
  let emptyHead = new ListNode(null, head);
  let tailNode = emptyHead, prevNode = emptyHead;
  let distance = 0;
  while (tailNode.next) {
    distance++;
    tailNode = tailNode.next;
    if (distance >= n + 1) prevNode = prevNode.next;
  }
  prevNode.next = prevNode.next.next;
  return emptyHead.next;
};
//遍历按序存下索引，然后直接访问倒数n个元素做删除节点就行
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