/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function (nums, target) {
  let minTarget = Number.MAX_VALUE;
  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;

    let l = i + 1, r = nums.length - 1;
    while (l < r) {
      let res = nums[i] + nums[l] + nums[r];
      if (Math.abs(target - minTarget) > Math.abs(target - res)) minTarget = res;
      if (res - target > 0) {
        while (l < r && nums[r] == nums[r - 1]) r--;
        r--;
      } else {
        while (l < r && nums[l] == nums[l + 1]) l++;
        l++;
      }
    }
  }
  return minTarget;
};