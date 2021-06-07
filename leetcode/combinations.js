/**
 * 77. 组合
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
let arrays = [];
let tNum = 0;
var combine = function (n, k) {
    arrays = [];
    tNum = k;
    handleArray([], 1, n);
    return arrays;
};
function handleArray(subs, start, end) {
    if (subs.length == tNum) {
        arrays.push(subs);
        return subs;
    }
    for (let i = start; i <= end; i++) {
        handleArray([...subs, i], i + 1, end);
    }
}

console.log(combine(4, 2));