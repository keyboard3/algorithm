//堆 完全二叉树用数组存储，节省内存空间。i的节点 i*2,i*2+1
var sortArray = function (nums) {
  for (let i = 1; i < nums.length; i++) {
    upToDown(nums, i);
    console.log(nums);
  }
};

sortArray([3, 4, 5, 1, 8]);

//从下往上堆化
function downToUp(nums, i) {
  if (i <= 0) return;
  //根据索引位置i+1,判断奇数是左节点，偶数是右节点
  //左节点找父节点 n n*2=i+1 => (i+1)/2
  //右节点找父节点 n n*2+1=i+1 => i/2
  const nodeIndex = i + 1;
  let parentIndex = 0;
  if (nodeIndex % 2 == 0) parentIndex = nodeIndex / 2;
  else parentIndex = (nodeIndex - 1) / 2;
  compSmallSwap(nums, parentIndex - 1, i);
  downToUp(nums, parentIndex - 1);
}
//从上往下堆化
function upToDown(nums, i) {
  if (i <= 0) return;
  //根据索引位置i+1,判断奇数是左节点，偶数是右节点
  //左节点找父节点 n n*2=i+1 => (i+1)/2
  //右节点找父节点 n n*2+1=i+1 => i/2
  const nodeIndex = i + 1;
  let parentIndex = 0;
  if (nodeIndex % 2 == 0) parentIndex = nodeIndex / 2;
  else parentIndex = (nodeIndex - 1) / 2;
  compBigSwap(nums, parentIndex - 1, i);
  upToDown(nums, parentIndex - 1);
}
//小的放前面
function compSmallSwap(nums, prev, last) {
  if (nums[prev] > nums[last]) {
    let temp = nums[last];
    nums[last] = nums[prev];
    nums[prev] = temp;
  }
}
//大的放前面
function compBigSwap(nums, prev, last) {
  if (nums[prev] < nums[last]) {
    let temp = nums[last];
    nums[last] = nums[prev];
    nums[prev] = temp;
  }
}