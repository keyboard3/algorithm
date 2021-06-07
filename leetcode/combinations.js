/**
 * 77. 组合
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
let arrays = [];
let tNum = 0;
let subArray = [];
var combine = function (n, k) {
    arrays = [];
    subArray=[];
    tNum = k;
    handleArray(1, n);
    return arrays;
};
function handleArray(start, end) {
    if (subArray.length == tNum) {
        arrays.push(subArray.slice());
        return;
    }
    if (subArray.length + end - start + 1 < tNum) return;
    for (let i = start; i <= end; i++) {
        subArray.push(i);
        handleArray(i + 1, end);
        subArray.pop();
    }
}

console.log(combine(4, 2));