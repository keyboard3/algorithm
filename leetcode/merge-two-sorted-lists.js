//递归实现
var mergeTwoLists = function (l1, l2) {
  if (!l1) return l2;
  else if (!l2) return l1;
  let l3;
  if (l1.val < l2.val) l3 = l1, l1 = l1.next;
  else l3 = l2, l2 = l2.next;
  l3.next = mergeTwoLists(l1, l2);
  return l3;
};
//循环取第一个
var mergeTwoLists = function (l1, l2) {
  const empty = new ListNode(Number.MAX_VALUE);
  let l3, h3;
  h3 = l3 = new ListNode(0);
  while (l1 || l2) {
    let temp;
    if ((l2 || empty).val < (l1 || empty).val) temp = l2, l2 = l2.next;
    else temp = l1, l1 = l1.next;
    l3 = l3.next = temp;
  }
  return h3.next;
};
//循环取取一个（工程）
var mergeTwoLists = function (l1, l2) {
  const emptyNode = new ListNode(Number.MAX_VALUE);
  const h3 = new ListNode(0);
  h1 = new ListNode(0, l1);
  h2 = new ListNode(0, l2);
  l3 = h3;
  while (h1.next || h2.next) {
    const minHeadNode = getMinNode(h1, h2);
    l3 = l3.next = minHeadNode.next;
    minHeadNode.next = minHeadNode.next.next;
  }
  return h3.next;
  function getMinNode(h1, h2) {
    const node1 = h1.next || emptyNode;
    const node2 = h2.next || emptyNode;
    if (node1.val > node2.val) return h2;
    return h1;
  }
};