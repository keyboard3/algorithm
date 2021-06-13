/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  let result = [];
  const map = new Map();
  const arrayMap = new Map();
  nums.sort((a, b) => a - b);
  const newNums = [];
  let prev, sameNum = 0;
  for (let i = 0; i < nums.length; i++) {
    if (prev == nums[i]) {
      sameNum++;
      if (sameNum > 3) continue;
    } else sameNum = 0;
    prev = nums[i];
    newNums.push(nums[i]);
  }
  for (let i = 0; i < newNums.length; i++) {
    let array = map.get(newNums[i]) || [];
    array.push(i);
    map.set(newNums[i], array);
  }
  for (let i = 0; i < newNums.length; i++) {
    for (let j = i + 1; j < newNums.length; j++) {
      let third = map.get(-newNums[i] - newNums[j]);
      if (!third?.length) continue;
      let ele = [newNums[i], newNums[j], -newNums[i] - newNums[j]].sort((a, b) => a - b);
      if (arrayMap.get(ele.join(""))) continue;
      for (let three of third) {
        if (three <= j) continue;
        arrayMap.set(ele.join(""), true);
        result.push(ele);
        break;
      }
    }
  }
  return result;
};