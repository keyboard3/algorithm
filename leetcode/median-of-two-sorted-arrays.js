/*
 * @lc app=leetcode.cn id=4 lang=javascript
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
 var findMedianSortedArrays = (nums1, nums2) => {
    let result = 0;
    let total = nums1.length + nums2.length;
    for (let i = 0; i < total; i++) {
        let v1 = nums1.shift();
        let v2 = nums2.shift();
        let v = 0;
        if (v1 != undefined && v2 == undefined) v = v1;
        else if (v2 != undefined && v1 == undefined) v = v2;
        else if (v1 < v2) {
            v = v1;
            nums2.unshift(v2);
        } else {
            v = v2;
            nums1.unshift(v1);
        }
        if (isMiddle(i, total) > 0) break;
        else if (isMiddle(i, total) == 0) result += v;
    }
    return result / (total % 2 == 1 ? 1 : 2);
}
function isMiddle(index, total) {
    if (total % 2 == 1) {
        return index - parseInt(total / 2);
    } else {
        let left = total / 2 - 1;
        if (index < left) return -1;
        if (index > left + 1) return 1;
        return 0;
    }
}
// @lc code=end

