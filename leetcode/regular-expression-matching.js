/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function (s, p) {
  return dfs(0, 0, "");
  function dfs(si, pi, tab) {
    // console.log(tab + "dfs:", si, pi, s.slice(0, si + 1), p.slice(0, pi + 1))
    if (si >= s.length && pi >= p.length) {
      // console.log("找到");
      return true;
    }

    let matchChr = p[pi];
    let range = [1, 1];
    if (p[pi + 1] == "*") {
      pi += 2, range = [0, s.length - si];
    }
    else pi++;

    let matchNum = 0;
    do {
      // console.log(tab + "while", s[si], matchChr)
      if (matchNum == 0 && range[0] == 0 && dfs(si, pi, tab + "\t")) return true;

      if (!s[si]) return false;
      if (matchChr == "." || matchChr == s[si]) {
        matchNum++;
        if (dfs(++si, pi, tab + "\t")) return true;
      } else break;
    } while (matchNum < range[1]);
    // console.log(tab + "失败");
    return false;
  }
};

let array = [
  [true, "a", "ab*"],//[a]a a
  [false, "aa", "a"],//[a]a a
  [true, "ab", ".*"], //[ab] .*
  [true, "aab", "c*a*b"],//[aa][b]
  [true, "aaa", "a*a"],//a[a]a
  [false, "mississippi", "mis*is*p*."],
  [false, "ippi", "p*."],
  [false, "ab", "a*"],
  [false, "a", ".*..a*"]
]
for (let [result, ...params] of array) {
  let mr = isMatch(...params);
  console.log(mr == result, params);
}