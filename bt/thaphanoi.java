public class thaphanoi {

      // Hàm đệ quy để giải bài toán tháp Hà Nội và đếm số lần chuyển đĩa
      public static int hanoi(int n, char from, char to, char aux) {
            if (n == 1) {
                  System.out.println("Di chuyển đĩa 1 từ cọc " + from + " sang cọc " + to);
                  return 1; // Chỉ có một đĩa, thực hiện một lần di chuyển
            }

            // Di chuyển n-1 đĩa từ cọc 'from' sang cọc 'aux', sử dụng 'to' làm cọc trung
            // gian
            int moves = hanoi(n - 1, from, aux, to);

            // Di chuyển đĩa thứ n từ cọc 'from' sang cọc 'to'
            System.out.println("Di chuyển đĩa " + n + " từ cọc " + from + " sang cọc " + to);
            moves += 1; // Đếm thêm 1 lần di chuyển cho đĩa lớn nhất

            // Di chuyển n-1 đĩa từ cọc 'aux' sang cọc 'to', sử dụng 'from' làm cọc trung
            // gian
            moves += hanoi(n - 1, aux, to, from);

            return moves; // Trả về tổng số lần di chuyển
      }

      public static void main(String[] args) {
            int n = 3; // Số lượng đĩa
            int totalMoves = hanoi(n, 'A', 'C', 'B'); // A là cọc xuất phát, C là cọc đích, B là cọc trung gian
            System.out.println("Tổng số lần chuyển đĩa là: " + totalMoves);
      }
}
