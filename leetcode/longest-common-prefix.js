//竖着比
var longestCommonPrefix = function (strs) {
  for (let i = 0; i < 200; i++) {
    let chr = strs[0][i];
    if (!chr) return strs[0].slice(0, i);
    for (let j = 1; j < strs.length; j++) {
      if (chr != strs[j][i]) return strs[0].slice(0, i);
    }
  }
  return "";
};