/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
  let mArea = 0;
  for (let i = 0; i < height.length; i++) {
    for (let j = height.length - 1; j > i; j--) {
      if (height[j] < height[i]) continue;

      let area = height[i] * (j - i);
      if (area > mArea) mArea = area;
      break;
    }
  }
  for (let i = height.length - 1; i >= 0; i--) {
    for (let j = 0; j < i; j++) {
      if (height[j] < height[i]) continue;

      let area = height[i] * (i - j);
      if (area > mArea) mArea = area;
      break;
    }
  }
  return mArea;
};

console.log(maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]))