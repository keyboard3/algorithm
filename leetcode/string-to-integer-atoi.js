/**
 * @param {string} s
 * @return {number}
 */
const maxNum = Math.pow(2, 31) - 1;
const minNum = -Math.pow(2, 31);
var myAtoi = function (s) {
  let result = null, opt = 1;
  for (let chr of s) {
    if (!(chr >= '0' && chr <= '9')) {
      if (result == null) {
        if (chr == '+' || chr == '-') {
          opt = chr == '-' ? -1 : 1;
          result = 0;
          continue;
        }
        if (chr == ' ') continue;
        break;
      }
      break;
    }
    if (result == null) result = 0;
    result = result * 10 + parseInt(chr);
    if (result * opt > maxNum) return maxNum;
    else if (result * opt < minNum) return minNum;
  }
  return (result || 0) * opt;
};