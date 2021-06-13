

//优化方案，设定找到两端短边和长边，计算完面积之后，再以原来的长边作为短边继续向内找它的长边。
var maxArea = function (height) {
  let mArea = 0;
  let minI = 0, maxI = height.length - 1;
  let direction = -1;

  if (height[minI] > height[maxI]) {
    [maxI, minI] = [minI, maxI];
    direction = -direction;
  }
  while (minI != maxI) {
    mArea = Math.max(mArea, Math.min(height[minI], height[maxI]) * Math.abs(maxI - minI));
    if (height[maxI] >= height[minI]) {
      direction = -direction;
      [maxI, minI] = [minI, maxI];
    }
    maxI += direction;
  }
  return mArea;
};
//不断枚举左边的为短边，从右边依次找到长边。在找长边的过程中同时可以间接计算面积更新。缺点是每次左边枚举值，右边就得从头匹配
var maxArea2 = function (height) {
  let mArea = 0;
  for (let i = 0; i < height.length; i++) {
    for (let j = height.length - 1; j > i; j--) {
      if (height[j] < height[i]) {
        mArea = Math.max(height[j] * (j - i), mArea);
        continue;
      }
      mArea = Math.max(height[i] * (j - i), mArea);
      break;
    }
  }
  return mArea;
};

console.log(maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]))