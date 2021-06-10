/**
 * 123
 * 3->2->1
 * 3->(3)*10+2->((3*10+2)*10+1
 * 在拆解数字的过程中就可以递推出结果的部分
 */
const maxNum = Math.pow(2, 31) - 1;
const minNum = -Math.pow(2, 31);
var reverse = function (x) {
  let result = 0;
  while (x != 0) {
    const num = x % 10;
    result = result * 10 + num;
    x = ~~(x / 10);
    if (result > maxNum || result < minNum) return 0;
  }
  return result;
}
//暂存区存拆分数的结果，然后栈弹出累加
var reverse2 = function (x) {
  const array = [];
  let result = 0;
  while (x != 0) {
    const num = x % 10;
    array.push(num);
    x = parseInt(x / 10);
  }
  for (let mutil = 1; array.length > 0; mutil *= 10) {
    let num = array.pop();
    result += num * mutil;
    if (result > maxNum || result < minNum) return 0;
  }
  return result;
};