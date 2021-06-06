/**
 * 50. Pow(x, n)
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function (x, n) {
  return n > 0 ? powWhile(x, n) : 1 / powWhile(x, -n);
};
//递归
function powRecursion(x, n) {
  if (n == 0) return 1;
  let y = powRecursion(x, parseInt(n / 2));
  return n % 2 == 0 ? y * y : y * y * x;
}
//循环
function powWhile(x, n) {
  let y = x, ans = 1;
  while (n > 0) {
    if (n % 2 == 1) ans *= y;//最后*y，起始奇数y
    y = y * y;
    n = parseInt(n / 2);
  }
  return ans;
}
console.log(myPow(2, 10));