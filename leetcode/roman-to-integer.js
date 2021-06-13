/**
 * @param {string} s
 * @return {number}
 */
const romanIntMap = [
  ["M", 1000],
  ["CM", 900],
  ["D", 500],
  ["CD", 400],
  ["C", 100],
  ["XC", 90],
  ["L", 50],
  ["XL", 40],
  ["X", 10],
  ["IX", 9],
  ["V", 5],
  ["IV", 4],
  ["I", 1],
];
var romanToInt = function (s) {
  let val = 0;
  for (let [roman, intVal] of romanIntMap) {
    while (s.startsWith(roman)) {
      s = s.slice(roman.length);
      val += intVal;
    }
    if (!s) break;
  }
  return val;
};