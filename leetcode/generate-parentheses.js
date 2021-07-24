/**
 * 在前面的有效状态中推断出当前有效状态
 */
 var generateParenthesis = function (n) {
  let states = [["()"]];
  for (let curN = 2; curN <= n; curN++) {
    let state = [];
    //在前一个state外面包括()
    for (let i = 0; i < states[curN - 2].length; i++) {
      state.push(`(${states[curN - 2][i]})`);
    }
    //由前面的状态组合而成
    for (let i = 1; i < curN; i++) {
      state.push(...add(states[i - 1], states[curN - i - 1]));
    }
    states.push([...(new Set(state))]);
  }
  return states[n - 1];
};
function add(leftArray, rightArray) {
  let array = [];
  for (var leftIt of leftArray)
    for (var rightIt of rightArray)
      array.push(leftIt + rightIt);
  return array;
}