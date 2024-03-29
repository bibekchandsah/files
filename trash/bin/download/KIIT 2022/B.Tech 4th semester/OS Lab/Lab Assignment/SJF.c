#include <stdio.h>

// Structure to represent a process
struct Process
{
    int arrivalTime;
    int burstTime;
};

// Function to sort processes based on arrival time
void sortProcesses(struct Process processes[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (processes[i].arrivalTime > processes[j].arrivalTime)
            {
                // Swap processes
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// Function to compute waiting time and turnaround time
void computeTimes(struct Process processes[], int n)
{
    int completionTime = 0;
    for (int i = 0; i < n; i++)
    {
        completionTime += processes[i].burstTime;
        int turnaroundTime = completionTime - processes[i].arrivalTime;
        int waitingTime = turnaroundTime - processes[i].burstTime;

        printf("Process %d:\n", i + 1);
        printf("Completion Time: %d\n", completionTime);
        printf("Turnaround Time: %d\n", turnaroundTime);
        printf("Waiting Time: %d\n\n", waitingTime);
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    // Sort processes based on arrival time
    sortProcesses(processes, n);

    // Compute waiting time and turnaround time
    computeTimes(processes, n);

    return 0;
}