/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
 let line;
 var convert = function (s, numRows) {
   let res = "";
   if(numRows<=1) return s;
   line = numRows - 1;
   for (let i = 0; i < numRows; i++) {
     res += dfs(s, 0, numRows - 1, i, i == 0 ? s[i] : "");
   }
   return res;
 };
 function dfs(s, start, end, pos, str) {
   if (start + pos >= s.length) return str;
   if (pos != 0) {
     str += s[start + pos];
   }
   return dfs(s, end, end + line, line - pos, str);
 }

 
let input = "PAYPALISHIRING";
console.log(input)
console.log(convert(input, 4));