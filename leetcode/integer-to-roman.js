/**
 * @param {number} num
 * @return {string}
 */
const intRomanMap = [
  [1000, "M"],
  [900, "CM"],
  [500, "D"],
  [400, "CD"],
  [100, "C"],
  [90, "XC"],
  [50, "L"],
  [40, "XL"],
  [10, "X"],
  [9, "IX"],
  [5, "V"],
  [4, "IV"],
  [1, "I"],
];
var intToRoman = function (num) {
  let romanStr = "";
  for (let [value, roman] of intRomanMap) {
    while (num >= value) {
      num -= value;
      romanStr += roman;
    }
    if (num == 0) break;
  }
  return romanStr;
};