/*In a lab there were 15 computers which are having numbers as
35 to 50. Students registered for a lab are 14 only. Design
appropriate hash function to assign a computer to every
student. Now assume that two students are absent of this batch
so another batch's three students want to use computers in this
lab. Allocate the computers to these new students by using
linear probing with replacement.*/

#include <stdio.h>

#define TABLE_SIZE 14

// Hash function
int hash(int student_id) {
    return student_id % TABLE_SIZE;
}

int main() {
    int computers[TABLE_SIZE] = {35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48};
    int students[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int absents[] = {13, 14}; // Absent students
    int new_students[] = {15, 16, 17}; // New students

    // Assign computers to students
    for (int i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
        int computer_index = hash(students[i]) % TABLE_SIZE;
        printf("Student %d is assigned computer %d\n", students[i], computers[computer_index]);
    }

    // Assign computers to new students using linear probing
    for (int i = 0; i < sizeof(new_students)/sizeof(new_students[0]); i++) {
        int computer_index = hash(new_students[i]) % TABLE_SIZE;
        if (computers[computer_index] != 0) {
            // Collision detected, use linear probing with replacement
            int j = (computer_index + 1) % TABLE_SIZE;
            while (j != computer_index && computers[j] != 0) {
                j = (j + 1) % TABLE_SIZE;
            }
            if (j == computer_index) {
                printf("Hash table is full, cannot assign computer to student %d\n", new_students[i]);
            } else {
                computers[j] = computers[computer_index];
                computers[computer_index] = 0;
                printf("Student %d is assigned computer %d (using linear probing with replacement)\n", new_students[i], computers[j]);
            }
        } else {
            computers[computer_index] = new_students[i];
            printf("Student %d is assigned computer %d\n", new_students[i], computers[computer_index]);
        }
    }

    return 0;
}
