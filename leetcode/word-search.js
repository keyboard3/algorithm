/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
let maxRowLen = 0;
let maxColumnLen = 0;
let gBoard = [];
let gWord = "";
var exist = function (board, word) {
  gBoard = board;
  gWord = word;
  maxColumnLen = board.length;
  for (let column = 0; column < board.length; column++) {
    maxRowLen = board[column].length;
    for (let row = 0; row < maxRowLen; row++) {
      if (dfs(row, column, 0)) return true;
    }
  }
  return false;
};

function dfs(row, column, index) {
  if (gWord.length == index) return true;
  if (row < 0 || row >= maxRowLen || column < 0 || column >= maxColumnLen) return false;
  if (gBoard[column][row] == "#") return false;

  let chr = gBoard[column][row];
  if (chr != gWord[index]) return false;

  gBoard[column][row] = "#";
  let directions = [[-1, 0], [0, -1], [1, 0], [0, 1]];
  for (let [x, y] of directions) {
    if (dfs(row + x, column + y, index + 1)) return true;
  }
  gBoard[column][row] = chr;
  return false;
}

console.log(exist(
  [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
  , "SEE"));