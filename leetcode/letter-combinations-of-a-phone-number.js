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
//循环广度有限
var letterCombinations = function (digits) {
  if (!digits.length) return [];
  let prevList = [""];
  for (let num of digits) {
    let list = [];
    for (let prev of prevList)
      for (let chr of numMap.get(num) || "")
        list.push(prev + chr);
    prevList = list;
  }
  return prevList;
};
//递归枚举
var letterCombinations2 = function (digits) {
  if (!digits.length) return [];
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


let input = "235";
console.log(letterCombinations(input));