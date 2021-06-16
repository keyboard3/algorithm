//dp优化空间 反向. 实际空间优化有，单不明显
var isMatch3 = function (s, p) {
  let state = dfs(s, p.split("").reverse().join(""));
  return !!state[s.length];
  function dfs(s, p) {
    if (!p.length) return [true];
    let len = 1, state = [];
    let mchr = p[0];
    if (p[0] == "*") len = 2, mchr = p[1];
    const preState = dfs(s, p.slice(len));

    for (let i = 0; i <= s.length; i++) {
      if (len == 2) {
        state[i] = preState[i];
        if (matchChr(s, mchr, i))
          state[i] |= state[i - 1];
      } else if (matchChr(s, mchr, i))
        state[i] = preState[i - 1];
    }
    return state;
  }
  function matchChr(s, mchr, i) {
    if (i == 0) return false;
    if (mchr == "." || mchr == s[i - 1]) return true;
    return false;
  }
}
//dp优化空间 正向。  实际空间优化有，单不明显
var isMatch = function (s, p) {
  let state = dfs(s, p, [true]);
  return !!state[s.length];
  function dfs(s, p, preState) {
    if (!p.length) return preState;
    let len = 1;
    let state = [];
    if (p[1] == "*") len = 2;
    for (let i = 0; i <= s.length; i++) {
      if (len == 2) {
        state[i] = preState[i];
        if (matchChr(s, p, i))
          state[i] |= state[i - 1];
      } else if (matchChr(s, p, i))
        state[i] = preState[i - 1];
    }
    return dfs(s, p.slice(len), state);
  }
  function matchChr(s, p, i) {
    if (i == 0) return false;
    if (p[0] == "." || p[0] == s[i - 1]) return true;
    return false;
  }
}
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
  [false, "ab", "a*"],
  [true, "a", "a"],//[a]a a
  [true, "aac", "a*c"],//[a]a a
  [true, "ab", ".*"], //[ab] .*
  [true, "aab", "c*a*b"],//[aa][b]
  [true, "aaa", "a*a"],//a[a]a
  [false, "mississippi", "mis*is*p*."],
  [false, "ippi", "p*."],
  [false, "a", ".*..a*"],
  [true, "aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s"],
]
for (let [result, ...params] of array) {
  let mr = isMatch3(...params);
  console.log(mr == result, params);
}