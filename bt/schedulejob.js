// Định nghĩa lớp Job
class Job {
  constructor(id, deadline, profit) {
    this.id = id; // ID của công việc
    this.deadline = deadline; // Thời hạn hoàn thành công việc
    this.profit = profit; // Lợi nhuận của công việc
  }
}

// Hàm lập lịch công việc để tối ưu hóa lợi nhuận
function scheduleJobs(jobs) {
  // Sắp xếp công việc theo lợi nhuận giảm dần
  jobs.sort((a, b) => b.profit - a.profit);
  console.log(jobs);

  // Tìm thời hạn tối đa (max deadline)
  let maxDeadline = Math.max(...jobs.map((job) => job.deadline));

  // Khởi tạo mảng để theo dõi các thời điểm đã được chọn (thời gian bắt đầu từ 1 đến maxDeadline)
  let jobSequence = new Array(maxDeadline + 1).fill(-1); // Khởi tạo mảng toàn -1 (trống)

  // Biến tổng lợi nhuận
  let totalProfit = 0;

  // Xếp lịch các công việc
  for (let job of jobs) {
    // Thử xếp công việc vào thời điểm gần nhất trước hoặc đúng thời hạn mà còn trống
    for (let j = job.deadline; j > 0; j--) {
      if (jobSequence[j] === -1) {
        jobSequence[j] = job.id; // Đặt công việc tại thời điểm j
        totalProfit += job.profit; // Cộng lợi nhuận của công việc
        break; // Ra khỏi vòng lặp sau khi xếp công việc
      }
    }
  }

  // Kết quả
  console.log("Tổng lợi nhuận thu được:", totalProfit);

  // Liệt kê các công việc đã được chọn
  console.log("Các công việc được chọn:");
  for (let i = 1; i < jobSequence.length; i++) {
    if (jobSequence[i] !== -1) {
      console.log(`Công việc ${jobSequence[i]} tại thời điểm ${i}`);
    }
  }

  return { totalProfit, jobSequence };
}

// Ví dụ sử dụng hàm scheduleJobs
let jobs = [
  new Job(1, 4, 20), // Công việc 1: deadline = 4, profit = 20
  new Job(2, 1, 10), // Công việc 2: deadline = 1, profit = 10
  new Job(3, 2, 40), // Công việc 3: deadline = 2, profit = 40
  new Job(4, 2, 30), // Công việc 4: deadline = 2, profit = 30
];

// Gọi hàm để lập lịch các công việc
scheduleJobs(jobs);
