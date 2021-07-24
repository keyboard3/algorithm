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
 var mergeKLists = function (lists) {
  const newList = new ListNode();
  let curNewNode = newList;
  //为所有链表加一个空的头结点
  for (let i = 0; i < lists.length; i++) {
      let emptyHead = new ListNode();
      emptyHead.next = lists[i];
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