#include <stdio.h>
#include <string.h>

struct Activity {
    char name[20];
    int start;
    int finish;
};

void sortByFinishTime(struct Activity arr[], int n) {
    struct Activity temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i].finish > arr[j].finish) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    printf("Enter activity names:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%s", activities[i].name);
    }

    printf("Enter start times:\n");
    for (int i = 0; i < n; i++) {
        printf("Start time of %s: ", activities[i].name);
        scanf("%d", &activities[i].start);
    }

    printf("Enter finish times:\n");
    for (int i = 0; i < n; i++) {
        printf("Finish time of %s: ", activities[i].name);
        scanf("%d", &activities[i].finish);
    }

    // Sort activities by finish time
    sortByFinishTime(activities, n);

    // Print sorted table
    printf("\nSorted Activity Table:\n");
    printf("+------------+");
    for (int i = 0; i < n; i++) printf("--------+");
    printf("\n| %-10s |", "Activity");
    for (int i = 0; i < n; i++) printf(" %-6s|", activities[i].name);
    printf("\n| %-10s |", "Start");
    for (int i = 0; i < n; i++) printf(" %-6d|", activities[i].start);
    printf("\n| %-10s |", "Finish");
    for (int i = 0; i < n; i++) printf(" %-6d|", activities[i].finish);
    printf("\n+------------+");
    for (int i = 0; i < n; i++) printf("--------+");
    printf("\n");

    // Select non-conflicting activities
    printf("\nStep-by-step selection:\n");
    int lastFinish = -1;
    printf("Selected activities:\n");
    struct Activity selectedActivities[n];
    int selectedCount = 0;

    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            printf("Selected: %s (starts at %d, ends at %d)\n",
                   activities[i].name, activities[i].start, activities[i].finish);
            selectedActivities[selectedCount++] = activities[i];
            lastFinish = activities[i].finish;
        } else {
4        }
    }

    // Print final answer with table format for selected activities
    printf("\nFinal Activity Selection:\n");
    printf("+------------+--------+--------+\n");
    printf("| Activity  | Start  | Finish |\n");
    printf("+------------+--------+--------+\n");
    for (int i = 0; i < selectedCount; i++) {
        printf("| %-10s | %-6d | %-6d |\n", selectedActivities[i].name, selectedActivities[i].start, selectedActivities[i].finish);
    }
    printf("+------------+--------+--------+\n");

    return 0;
}
