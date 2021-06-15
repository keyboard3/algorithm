//枚举出左侧两个数，然后所有满足target的解呈现两端向内收缩的趋势
var fourSum = function (nums, target) {
  const length = nums.length;
  if (length < 4) return [];
  const result = [];
  nums.sort((a, b) => a - b);
  for (let i = 0; i < length - 3; i++) {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
      break;
    if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)
      continue;

    for (let j = i + 1; j < length - 2; j++) {
      if (j > i + 1 && nums[j] == nums[j - 1])
        continue;
      if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
        break;
      if (nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target)
        continue;

      let l = j + 1, r = length - 1;
      while (l < r) {
        let res = nums[i] + nums[j] + nums[l] + nums[r];
        if (res == target) {
          result.push([nums[i], nums[j], nums[l], nums[r]]);
          while (l < r && nums[l] == nums[l + 1]) l++;
          while (l < r && nums[r] == nums[r - 1]) r--;
          l++, r--;
        }
        else if (res > target) r--;
        else l++;
      }
    }
  }
  return result;
}