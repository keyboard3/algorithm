/**
 * @param {string} digits
 * @return {string[]}
 */
 const numMap = new Map([
  ['2', "abc"],
  ['3', "def"],
  ['4', "ghi"],
  ['5', "jkl"],
  ['6', "mno"],
  ['7', "pqrs"],
  ['8', "tuv"],
  ['9', "wxyz"]
]);
var letterCombinations = function (digits) {
  if(!digits.length) return [];
  return [...dfs(digits, 0, "")]
};
function* dfs(digits, index, str) {
  if (index >= digits.length) {
      yield str;
      return;
  }
  for (let chr of numMap.get(digits[index])) {
      yield* dfs(digits, index + 1, str + chr);
  }
}