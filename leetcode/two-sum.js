/**
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
let map = new Map();
var twoSum = function (nums, target) {
    map.clear();
    let item = 0, i = 0;
    for (i = 0; i < nums.length; i++) {
        item = nums[i];
        if (map.has(target - item)) return [map.get(target - item), i];
        map.set(target - item, i);
    }
    return [0, 0];
};

console.log(twoSum([-1, -2, -3, -4, -5], -8))