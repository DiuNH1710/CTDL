// const readline = require("readline");

// const rl = readline.createInterface({
//   input: process.stdin,
//   output: process.stdout,
// });

// // Hàm nhập mảng
// function inputArray() {
//   return new Promise((resolve) => {
//     rl.question(
//       "Nhập các số cách nhau bởi dấu phẩy (ví dụ: 5,3,8,1,2): ",
//       (input) => {
//         const arr = input.split(",").map(Number); // Tách chuỗi và chuyển đổi thành số
//         resolve(arr);
//       }
//     );
//   });
// }

let arr = [1, 2, 45, 45, 14, 341, 21, 14];
function selectionSort(arr) {
  let n = arr.length;
  for (let i = 0; i < n - 1; i++) {
    let minIndex = i;
    for (let j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
      console.log(minIndex);
    }
    [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
    console.log([arr[minIndex], arr[i]]);
  }
  return arr;
}
