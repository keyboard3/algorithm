/**
 * 42. 接雨水
 * 每次只算出最外层的接水量，遇到更高的就减去，然后继续算里面的
 * 通过递归降低心智复杂度
 * @param {number[]} height
 * @return {number}
 */
 var trap = function (height) {
  return getArrayWater(height, 0, height.length - 1);
};
function getArrayWater(height, left, right) {
  if (left >= right) return 0;
  let area = 0;
  if (height[left] >= height[right]) {
      area = height[right] * (right - left - 1);
      for (let ri = right - 1; ri > left; ri--) {
          if (height[ri] >= height[right]) {
              area -= height[right] * (ri - left);
              return Math.max(0, area) + getArrayWater(height, left, ri);
          } else area -= height[ri];
      }
  } else {
      area = height[left] * (right - left - 1);
      for (let li = left+1; li < right; li++) {
          if (height[li] >= height[left]) {
              area -= height[left] * (right - li);
              return Math.max(0, area) + getArrayWater(height, li, right);
          } else area -= height[li];
      }
  }
  return Math.max(0, area);
}