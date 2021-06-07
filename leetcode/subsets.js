/**
 * @param {number[]} nums
 * @return {number[][]}
 */
let arrays = [];
let subArray = [];
let target = [];
var subsets = function (nums) {
  arrays = [];
  subArray = [];
  target = nums;
  dfs(0, nums.length)
  return arrays;
};
function dfs(start, end) {
  arrays.push(subArray.slice());
  for (let i = start; i < end; i++) {
    subArray.push(target[i]);
    dfs(i + 1, end);
    subArray.pop();
  }
}

console.log(subsets([1, 2, 3]))