/**
 * https://leetcode-cn.com/problems/minimum-window-substring/
 * 116 ms	39.6 MB
 * 76. 最小覆盖子串
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 解法：滑动窗口
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
let tArray = new Uint16Array(128);
let sArray = new Uint16Array(128);
var minWindow = function (s, t) {
  tArray.fill(0);
  sArray.fill(0);
  for (let chr of t) {
    tArray[chr.charCodeAt()]++;
  }
  let [l, r] = [-1, -1];
  let [mL, mR] = [0, s.length];
  let rEnd = s.length - 1;
  let chrCode;
  while (r < rEnd) {
    r++;
    chrCode = s[r].charCodeAt();
    if (!tArray[chrCode]) continue;
    sArray[chrCode]++;
    if (!check()) continue;
    
    let lEnd = r - t.length + 1;
    while (l < lEnd) {
      l++;
      chrCode = s[l].charCodeAt();
      if (!tArray[chrCode]) continue;
      sArray[chrCode]--;
      if (sArray[chrCode] < tArray[chrCode]) {
        if (r - l < mR - mL) {
          mR = r;
          mL = l;
        }
        break;
      }
    }
  }
  if (l == -1) return "";
  return s.slice(mL, mR + 1);
};
function check() {
  for (let i = 0; i < tArray.length; i++) {
    if (sArray[i] < tArray[i]) return false;
  }
  return true;
}

console.log(minWindow("ab", "a"));