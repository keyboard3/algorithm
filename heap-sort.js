//堆 完全二叉树用数组存储，节省内存空间。i的节点 i*2,i*2+1
var sortArray = function (nums, isDesc) {
  let heap = nums.slice();
  //原地建堆
  for (let i = 1; i < heap.length; i++) {
    //从下到上
    downToUp(heap, i, isDesc);
    //从上到下
  }
  //取堆跟排序
  for (let i = heap.length - 1; i >= 0; i--) {
    //取堆的根节点覆盖原数组
    nums[nums.length - 1 - i] = heap[0];
    //调整堆序。为了保证完全二叉树，将末尾的放到刚删除的堆顶，然后从堆顶从上到对比调换
    heap[0] = heap[i];
    upToDown(heap, i - 1, 0, isDesc);
  }
  console.log(nums);
};

sortArray([3, 4, 5, 1, 8], false);

//从下往上堆化
function downToUp(nums, childIndex, isDesc) {
  if (childIndex <= 0) return;
  //根据索引位置i+1,判断奇数是左节点，偶数是右节点
  //左节点找父节点 n n*2=i+1 => (i+1)/2
  //右节点找父节点 n n*2+1=i+1 => i/2
  const nodeIndex = childIndex + 1;
  let parentIndex = 0;
  if (nodeIndex % 2 == 0) parentIndex = nodeIndex / 2;
  else parentIndex = (nodeIndex - 1) / 2;
  //恢复实际索引
  parentIndex--;
  if (isDesc && nums[parentIndex] > nums[childIndex]
    || !isDesc && nums[parentIndex] < nums[childIndex])
    [nums[parentIndex], nums[childIndex]] = [nums[childIndex], nums[parentIndex]];
  downToUp(nums, parentIndex, isDesc);
}
//从上往下堆化
function upToDown(nums, limitIndex, parentIndex, isDesc) {
  compare((parentIndex + 1) * 2 - 1);
  compare((parentIndex + 1) * 2);
  function compare(childIndex) {
    if (childIndex > limitIndex) return;
    if (isDesc && nums[parentIndex] > nums[childIndex]
      || !isDesc && nums[parentIndex] < nums[childIndex]) {
      //左节点调整了，就继续向下
      [nums[parentIndex], nums[childIndex]] = [nums[childIndex], nums[parentIndex]];
      upToDown(nums, limitIndex, childIndex, isDesc);
    }
  }
}