/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
//二分查找
var mergeKLists = function (lists) {
  const newList = new ListNode();
  let curNewNode = newList;
  //为所有链表加一个空的头结点
  for (let i = 0; i < lists.length; i++) {
    let emptyHead = new ListNode(Number.MAX_VALUE, lists[i]);
    lists[i] = emptyHead;
  }
  //快排
  lists.sort(compare)
  while (1) {
    let smallList = lists[0];
    //将这个链表头加入到新的链表上
    if (!smallList || !smallList.next) break;
    curNewNode.next = smallList.next;
    curNewNode = curNewNode.next;
    //并删除旧的
    smallList.next = smallList.next.next;
    lists.shift();
    //二分查找
    let index = binary(smallList, 0, lists.length - 1);
    lists.splice(index, 0, smallList);
  }
  return newList.next;
  function binary(keyNode, l, r) {
    if (l > r) return l;
    if (l == r) {
      if (compare(keyNode, lists[l]) <= 0) return l;
      return l + 1;
    }
    let mid = Math.ceil((l + r) / 2) - 1;
    if (compare(keyNode, lists[mid]) <= 0) return binary(keyNode, l, mid);
    return binary(keyNode, mid + 1, r);
  }
  function compare(a, b) {
    let aVal = (a.next || a).val;
    let bVal = (b.next || b).val;
    return aVal - bVal;
  }
};
//普通遍历取最小
var mergeKLists2 = function (lists) {
  const newList = new ListNode();
  let curNewNode = newList;
  //为所有链表加一个空的头结点
  for (let i = 0; i < lists.length; i++) {
    let emptyHead = new ListNode(Number.MAX_VALUE, lists[i]);
    lists[i] = emptyHead;
  }
  while (1) {
    //找到最小的链表头
    let smallList = null;
    for (var list of lists) {
      if (!smallList && list.next) {
        smallList = list;
        continue;
      }
      if (!list.next) continue;
      if (list.next.val > smallList.next.val) continue;
      smallList = list;
    }
    //将这个链表头加入到新的链表上
    if (!smallList || !smallList.next) break;
    curNewNode.next = smallList.next;
    curNewNode = curNewNode.next;
    //并删除旧的
    smallList.next = smallList.next.next;
  }
  return newList.next;
};