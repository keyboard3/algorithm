/*
 * @lc app=leetcode.cn id=6 lang=javascript
 *
 * [6] 寻找两个正序数组的中位数
 */

// @lc code=start
var convert = function (s, numRows) {
  if (numRows <= 1) return s;
  let res = "";
  for (let i = 0; i < numRows; i++) {
    if (i == 0) res = s[i];
    let start = 0, pos = i;
    while (start + pos < s.length) {
      if (pos != 0) res += s[start + pos];
      start = start + numRows - 1;
      pos = numRows - 1 - pos;
    }
  }
  return res;
};
// @lc code=end
let line;
var convert2 = function (s, numRows) {
  let res = "";
  if (numRows <= 1) return s;
  line = numRows - 1;
  for (let i = 0; i < numRows; i++) {
    res += dfs(s, 0, numRows - 1, i, i == 0 ? s[i] : "");
  }
  return res;
};
function dfs(s, start, end, pos, str) {
  if (start + pos >= s.length) return str;
  if (pos != 0) {
    str += s[start + pos];
  }
  return dfs(s, end, end + line, line - pos, str);
}


let input = "PAYPALISHIRING";
console.log(input)
console.log(convert(input, 4));