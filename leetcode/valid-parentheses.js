/**
 * @param {string} s
 * @return {boolean}
 */
const pairs = ["()", "{}", "[]"];
const leftMap = pairs.reduceRight((cur, pair) => cur.set(pair[0], pair[1]), new Map())
const rightMap = pairs.reduceRight((cur, pair) => cur.set(pair[1], pair[0]), new Map())
var isValid = function (s) {
  if (s.length % 2 == 1) return false;

  let leftStack = [];
  for (let i = 0; i < s.length; i++) {
    if (leftStack.length > s.length - i) return false;

    let chr = s[i];
    if (leftMap.has(chr)) leftStack.push(chr);
    else if (rightMap.has(chr)) {
      let leftChr = leftStack.pop();
      if (leftMap.get(leftChr) !== chr) return false;
    }
  }
  return leftStack.length == 0;
};