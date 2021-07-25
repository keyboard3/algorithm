//堆 完全二叉树用数组存储，节省内存空间。i的节点 i*2,i*2+1
var sortArray = function (nums, isDesc) {
  let heap = nums.slice();
  //原地建堆1：从前到后处理数据，从下到上堆化。（类似于在原组织架构上逐步招聘外部人员）
  for (let i = 1; i < heap.length; i++) {
    downToUp(heap, i, isDesc);
  }
  //原地建堆2：从后往前处理数据，从上到下堆化。（类似于逐级向上选举组成结构）
  let parentIndex = heap.length - 1;
  while (parentIndex >= 0) {
    compParentChild(heap, parentIndex, (parentIndex + 1) * 2 - 1, isDesc);
    compParentChild(heap, parentIndex, (parentIndex + 1) * 2, isDesc);
    parentIndex = getParentNodeIndex(parentIndex);
  }

  //取堆跟排序
  for (let i = heap.length - 1; i >= 0; i--) {
    //取堆的根节点覆盖原数组
    nums[nums.length - 1 - i] = heap[0];
    //调整堆序。为了保证完全二叉树，将末尾的放到刚删除的堆顶，然后从堆顶从上到对比调换
    heap[0] = heap[i];
    adjustHeapRoot(heap, i - 1, 0, isDesc);
  }
  return nums;
};

console.log(sortArray([3, 4, 5, 1, 8], false));

//从下往上堆化
function downToUp(nums, childIndex, isDesc) {
  let parentIndex = getParentNodeIndex(childIndex);
  if (parentIndex < 0) return;
  compParentChild(nums, parentIndex, childIndex, isDesc);
  downToUp(nums, parentIndex, isDesc);
}
//比较并交换父节点和子节点
function compParentChild(nums, parentIndex, childIndex, isDesc) {
  if (parentIndex >= nums.length || childIndex >= nums.length) return;

  if (isDesc && nums[parentIndex] > nums[childIndex]
    || !isDesc && nums[parentIndex] < nums[childIndex])
    [nums[parentIndex], nums[childIndex]] = [nums[childIndex], nums[parentIndex]];
}
//根据二叉树子节点在数组中的索引算出父节点的位置
function getParentNodeIndex(childIndex) {
  if (childIndex <= 0) return -1;
  //根据索引位置i+1,判断奇数是左节点，偶数是右节点
  //左节点找父节点 n n*2=i+1 => (i+1)/2
  //右节点找父节点 n n*2+1=i+1 => i/2
  let nodeIndex = childIndex + 1;
  let parentIndex = 0;
  if (nodeIndex % 2 == 0) parentIndex = nodeIndex / 2;
  else parentIndex = (nodeIndex - 1) / 2;
  return parentIndex - 1;
}
//调整堆上指定节点与其子节点的位置
function adjustHeapRoot(nums, limitIndex, parentIndex, isDesc) {
  compare((parentIndex + 1) * 2 - 1);
  compare((parentIndex + 1) * 2);
  function compare(childIndex) {
    if (childIndex > limitIndex) return;
    if (isDesc && nums[parentIndex] > nums[childIndex]
      || !isDesc && nums[parentIndex] < nums[childIndex]) {
      //左节点调整了，就继续向下
      [nums[parentIndex], nums[childIndex]] = [nums[childIndex], nums[parentIndex]];
      adjustHeapRoot(nums, limitIndex, childIndex, isDesc);
    }
  }
}