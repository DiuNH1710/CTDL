#include <stdio.h>
#include <stdlib.h>

// Job structure to store deadline and profit of each job
typedef struct {
    int deadline;
    int profit;
} Job;

// Compare function for sorting jobs in decreasing order of profit
int compare(const void* a, const void* b) {
    Job* jobA = (Job*)a;
    Job* jobB = (Job*)b;
    return jobB->profit - jobA->profit;
}

// Find function for the Union-Find structure (with path compression)
int find(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent, parent[i]);
}

// Union function for the Union-Find structure
void unionSets(int parent[], int i, int j) {
    parent[find(parent, i)] = find(parent, j);
}

int main() {
    int n;
    
    // Reading the number of jobs
    scanf("%d", &n);
    
    Job jobs[n];
    
    // Reading the deadlines and profits of jobs
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
    }
    
    // Sorting jobs by profit in decreasing order
    qsort(jobs, n, sizeof(Job), compare);
    
    // Maximum deadline (we need to track available time slots)
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    
    // Union-Find structure to track the latest available slot
    int parent[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) {
        parent[i] = i;
    }
    
    int totalProfit = 0;
    
    // Iterating over the sorted jobs
    for (int i = 0; i < n; i++) {
        int availableSlot = find(parent, jobs[i].deadline);
        
        // If there's a slot available before or at the job's deadline
        if (availableSlot > 0) {
            // Add the profit of this job to the total profit
            totalProfit += jobs[i].profit;
            
            // Union the current slot with the previous one to mark it as occupied
            unionSets(parent, availableSlot, availableSlot - 1);
        }
    }
    
    // Output the total profit
    printf("%d\n", totalProfit);
    
    return 0;
}
