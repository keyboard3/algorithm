
//通过去重之后，负数区枚举两个在正数区找第3个。正数区枚举两个，找负数区第3个。这种自然的处理就不会导致重复加入结果
var threeSum = function (nums) {
  let result = [];
  nums.sort((a, b) => a - b);
  const showNumMap = new Map();
  for (let i = 0; i < nums.length; i++) {
    let times = showNumMap.get(nums[i]) || 0;
    showNumMap.set(nums[i], times + 1);
  }
  const distNums = [...showNumMap.keys()]
  let first = 0;
  //枚举负数区
  for (first = 0; distNums[first] < 0; first++) {
    appendSame(distNums[first]);
    for (let second = first + 1; distNums[second] < 0; second++)
      append(distNums[first], distNums[second]);
  }
  //枚举正数区
  for (; first < distNums.length; first++) {
    appendSame(distNums[first]);
    for (let second = first + 1; second < distNums.length; second++)
      append(distNums[first], distNums[second]);
  }
  return result;
  function appendSame(firstVal) {
    let times = showNumMap.get(firstVal);
    if (times <= 1 || (firstVal == 0 && times < 3)) return;
    append(firstVal, firstVal);
  }
  function append(firstVal, secondVal) {
    let threeVal = -firstVal - secondVal;
    if (!showNumMap.get(threeVal)) return;
    result.push([firstVal, secondVal, threeVal]);
  }
}

//一个数通过Map映射查找，另外两个数通过枚举组合。并特殊处理高重复的元素情况
var threeSum2 = function (nums) {
  let result = [];
  const map = new Map();
  const inArrayMap = new Map();
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
      if (inArrayMap.get(ele.join(""))) continue;
      for (let three of third) {
        if (three <= j) continue;
        inArrayMap.set(ele.join(""), true);
        result.push(ele);
        break;
      }
    }
  }
  return result;
};