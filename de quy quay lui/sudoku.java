
public class sudoku {
      private void backtrack(char[][] a, int i, int j) {
            if (i >= 0 && i <= 8 && j >= 0 && j <= 8) {
                  for (char c = '1'; c < '9'; c++) {
                        a[i][j] = c;
                        if (i == 8 && j == 8) {
                              // kiem tra cau hinh hoan thien co dung khong?

                        } else {
                              int next_i = i;
                              int next_j = j;
                              if (j < 8) {
                                    next_i = i;
                                    next_j = j + 1;
                              } else {
                                    next_i = i + 1;
                                    next_j = 0;
                              }
                              backtrack(a, next_i, next_j);
                        }
                  }
            }
      }

      public void solveSudoku(char[][] a) {
            backtrack(a, 0, 0);
      }

      public static void main(String[] args) {

      }
}
