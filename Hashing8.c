/*In a lab there were 10 computers which are having numbers as
21 to 30. Students registered for a lab are 10 only. Design
appropriate hash function to assign a computer to every
student. Now assume that three students are absent of this
batch so another batch students want to use computers in this
lab. Allocate the computers to these new students by using
linear probing with chaining without replacement.*/


#include <stdio.h>

#define NUM_COMPUTERS 10
#define FIRST_COMPUTER 21

int hash(int id) {
    return (id % 10) + FIRST_COMPUTER - 1;
}

int main() {
    // Assign computers to first batch of students
    printf("First batch of students:\n");
    for (int i = 1; i <= 10; i++) {
        int id;
        printf("Enter student %d ID: ", i);
        scanf("%d", &id);
        int computer = hash(id);
        printf("Student %d assigned to computer %d\n", i, computer);
    }

    // Assign computers to second batch of students using linear probing with chaining without replacement
    printf("Second batch of students:\n");
    int numAbsent = 3;
    int numStudents = 7;
    int computers[NUM_COMPUTERS];
    for (int i = 0; i < NUM_COMPUTERS; i++) {
        computers[i] = 0;
    }
    for (int i = 1; i <= numStudents; i++) {
        int id;
        printf("Enter student %d ID: ", i);
        scanf("%d", &id);
        int computer = hash(id);
        while (computers[computer - FIRST_COMPUTER] != 0) {
            computer++;
            if (computer > FIRST_COMPUTER + NUM_COMPUTERS - 1) {
                computer = FIRST_COMPUTER;
            }
        }
        computers[computer - FIRST_COMPUTER] = id;
        printf("Student %d assigned to computer %d\n", i + 10 - numAbsent, computer);
    }

    return 0;
}