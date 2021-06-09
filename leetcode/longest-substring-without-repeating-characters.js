/**
 * @param {string} s
 * @return {number}
 */
 var lengthOfLongestSubstring = function (s) {
  let len = 0;
  let maxLen = 0;
  for (let i = 0; i < s.length; i++) {
      check(s[i], i);
      len++;
  }
  if (len > maxLen) maxLen = len;
  return maxLen;
  function check(chr, end) {
      for (let i = end - len; i < end; i++) {
          if (s[i] != chr) continue;
          if (len > maxLen) maxLen = len;
          len = end - i - 1;
          break;
      }
  }
};