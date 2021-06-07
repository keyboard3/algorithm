#include "vector"
#include "string"
using namespace std;

class Solution
{
public:
  vector<vector<char>> gBoard;
  string gWord;
  int maxRowLen;
  int maxColumnLen;
  bool exist(vector<vector<char>> &board, string word)
  {
    gBoard = board;
    gWord = word;
    maxColumnLen = board.size();
    for (int column = 0; column < maxColumnLen; column++)
    {
      maxRowLen = board[column].size();
      for (int row = 0; row < maxRowLen; row++)
      {
        if (dfs(row, column, 0))
          return true;
      }
    }
    return false;
  }
  bool dfs(int row, int column, int index)
  {
    if (gWord.length() == index)
      return true;
    if (row < 0 || row >= maxRowLen || column < 0 || column >= maxColumnLen)
      return false;
    if (gBoard[column][row] == '#')
      return false;

    if (gBoard[column][row] != gWord[index])
      return false;

    gBoard[column][row] = '#';
    int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 0; i < 4; i++)
    {
      if (dfs(row + directions[i][0], column + directions[i][1], index + 1))
        return true;
    }
    gBoard[column][row] = gWord[index];
    return false;
  }
};