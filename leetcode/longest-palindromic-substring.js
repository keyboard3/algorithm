/**
 * @param {string} s
 * @return {string}
 */
 var longestPalindrome = function (s) {
  let ms = 0, me = 0;
  for (let i = 0; i < s.length; i++) {
      let start = i - 1, end = i + 1;
      expand();
      start = i; end = i + 1;
      expand();
      function expand() {
          while (start >= 0 && end < s.length) {
              if (s[start] != s[end]) break;
              if (end - start > me - ms) {
                  ms = start;
                  me = end ;
              }
              start--;
              end++;
          }
      }
  }
  return s.slice(ms, me + 1);
};