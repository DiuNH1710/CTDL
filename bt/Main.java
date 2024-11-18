
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static class Job {
        int deadline;
        int profit;

        Job(int deadline, int profit) {
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    public static int maxProfit(int n, Job[] jobs) {

        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);

        int maxDeadline = 0;
        for (Job job : jobs) {
            maxDeadline = Math.max(maxDeadline, job.deadline);
        }

        boolean[] scheduled = new boolean[maxDeadline + 1];
        int totalProfit = 0;

        // Lặp qua từng công việc
        for (Job job : jobs) {

            for (int j = Math.min(job.deadline, maxDeadline); j > 0; j--) {
                if (!scheduled[j]) {
                    scheduled[j] = true;
                    totalProfit += job.profit;
                    break;
                }
            }
        }

        return totalProfit;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        Job[] jobs = new Job[n];

        for (int i = 0; i < n; i++) {
            int deadline = scanner.nextInt();
            int profit = scanner.nextInt();
            jobs[i] = new Job(deadline, profit);
        }

        System.out.println(maxProfit(n, jobs));

        scanner.close();
    }
}
