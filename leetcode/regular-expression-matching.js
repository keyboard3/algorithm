//采用枚举出所有状态，从目标结果倒推出组合路径
var isMatch = function (s, p) {
  let state = [[]];

  state[0][0] = true;
  //枚举出所有路径i,j的匹配情况，第i个匹配可以根据前面的匹配状态，计算当前自己的能够匹配的情况
  for (let pi = 1; pi <= p.length; pi++) {
    state[pi] = [];
    if (p[pi - 1] == "*") {
      state[pi] = state[pi - 1];
      continue;
    }
    for (let si = 0; si <= s.length; si++) {
      state[pi][si] = false;
      if (p[pi] == "*") {
        state[pi][si] = state[pi - 1][si];
        if (matchChr(pi, si)) {//会尝试匹配个空
          state[pi][si] |= state[pi][si - 1];
        }
      } else {
        if (matchChr(pi, si)) {
          state[pi][si] = state[pi - 1][si - 1];
        }
      }
    }
  }
  return !!state[p.length][s.length];
  function matchChr(pi, si) {
    if (si == 0) return false;
    if (p[pi - 1] == "." || p[pi - 1] == s[si - 1]) return true;
    return false;
  }
}
//采用递归枚举组合出目标结果
var isMatch2 = function (s, p) {
  return dfs(0, 0, "");
  function dfs(si, pi) {
    if (si >= s.length && pi >= p.length) return true;

    let matchChr = p[pi];
    let range = [1, 1];
    if (p[pi + 1] == "*") {
      pi += 2, range = [0, s.length - si];
    }
    else pi++;

    let matchNum = 0;
    do {
      if (matchNum == 0 && range[0] == 0 && dfs(si, pi)) return true;

      if (!s[si]) return false;
      if (matchChr == "." || matchChr == s[si]) {
        matchNum++;
        if (dfs(++si, pi)) return true;
      } else break;
    } while (matchNum < range[1]);
    return false;
  }
};

let array = [
  [true, "a", "a"],//[a]a a
  [true, "aac", "a*c"],//[a]a a
  [true, "ab", ".*"], //[ab] .*
  [true, "aab", "c*a*b"],//[aa][b]
  [true, "aaa", "a*a"],//a[a]a
  [false, "mississippi", "mis*is*p*."],
  [false, "ippi", "p*."],
  [false, "ab", "a*"],
  [false, "a", ".*..a*"],
  [true, "aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s"],
]
for (let [result, ...params] of array) {
  let mr = isMatch(...params);
  console.log(mr == result, params);
}