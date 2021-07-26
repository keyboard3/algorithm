//堆 完全二叉树用数组存储，节省内存空间。i的节点 i*2,i*2+1
var sortArray = function (nums, isAsc) {
  let heap = nums.slice();
  //原地建堆1：从前到后处理数据，从下到上堆化。（类似于底层招聘人员，然后通过内部向上申请到合适位置）
  for (let i = 1; i < heap.length; i++) {
    adjustHeapTail(heap, i, isAsc);
  }
  //原地建堆2：从后往前处理数据，从上到下堆化。(因为下面结构稳定，只要调整根节点就成)
  for (let i = heap.length - 1; i >= 0; i--) {
    //叶子节点跳过
    if (((i + 1) * 2) - 1 >= heap.length) continue;
    let partialHeap = heap.slice(i);
    adjustHeapRoot(partialHeap, isAsc);
    heap = [...heap.slice(0, i), ...partialHeap];
  }

  //取堆跟排序
  for (let i = heap.length - 1; i >= 0; i--) {
    //取堆的根节点覆盖原数组
    nums[nums.length - 1 - i] = heap[0];
    //调整堆序。为了保证完全二叉树，将末尾的放到刚删除的堆顶，然后从堆顶从上到对比调换
    heap[0] = heap[i];
    heap.length = i;
    adjustHeapRoot(heap, isAsc);
  }
  return nums;
};

console.log(sortArray([3, 4, 5, 1, 8], true));

//从下往上堆化（类似于从下面招聘上来的，经过评审调整位置）
function adjustHeapTail(nums, childIndex, isAsc) {
  if (childIndex <= 0) return;
  let parentIndex = Math.ceil((childIndex + 1) / 2) - 1;
  if (isMatch(nums, isAsc, parentIndex, childIndex)) {
    [nums[parentIndex], nums[childIndex]] = [nums[childIndex], nums[parentIndex]];
    adjustHeapTail(nums, parentIndex, isAsc);
  }
}
//调整根节点在堆中的位置
function adjustHeapRoot(nums, isAsc) {
  let parentIndex = 0;
  while (parentIndex < nums.length) {
    //左节点
    let lci = (parentIndex + 1) * 2 - 1;
    let rci = (parentIndex + 1) * 2;
    let lAct = isMatch(nums, isAsc, parentIndex, lci);
    let rAct = isMatch(nums, isAsc, parentIndex, rci);
    let childIndex = 0;
    if (lAct && rAct) {
      childIndex = lci;
      if (isMatch(nums, isAsc, lci, rci)) childIndex = rci;
    }
    else if (lAct) childIndex = lci
    else if (rAct) childIndex = rci;
    if (childIndex <= 0) break;
    [nums[parentIndex], nums[childIndex]] = [nums[childIndex], nums[parentIndex]];
    parentIndex = childIndex;
  }
}
function isMatch(nums, isAsc, parentIndex, childIndex) {
  if (childIndex >= nums.length) return false;
  return isAsc && nums[parentIndex] > nums[childIndex]
    || !isAsc && nums[parentIndex] < nums[childIndex];
}