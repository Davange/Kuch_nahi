/*In Computer Engg. Dept. of VIT there are S.Y., T.Y., and B.Y.
students. Assume that all these students are on ground for a
function. We need to identify a student of S.Y. div. (X) whose
name is "XYZ" and roll no. is "17". Apply appropriate searching
method to identify a required student.*/

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100 // maximum number of students
#define HASH_SIZE 20 // hash table size

typedef struct {
    char name[50];
    int roll_no;
    char div;
} Student;

int hash(char div, int roll_no) {
    // hash function: sum of ASCII codes of division and roll number
    return (int)div + roll_no;
}

int main() {
    Student students[MAX_STUDENTS];
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // get student details from user
    for (int i = 0; i < num_students; i++) {
        printf("Enter details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No.: ");
        scanf("%d", &students[i].roll_no);
        printf("Division: ");
        scanf(" %c", &students[i].div);
    }

    // create hash table
    Student hash_table[HASH_SIZE] = {0};

    // insert students into hash table
    for (int i = 0; i < num_students; i++) {
        int h = hash(students[i].div, students[i].roll_no) % HASH_SIZE;
        if (hash_table[h].roll_no == 0) {
            // insert student into hash table
            hash_table[h] = students[i];
        } else {
            // linear probing with chaining
            int j = h;
            do {
                j = (j + 1) % HASH_SIZE;
            } while (j != h && hash_table[j].roll_no != 0);

            if (j == h) {
                printf("Hash table is full, cannot insert student %s with roll no. %d\n",
                       students[i].name, students[i].roll_no);
            } else {
                // insert student into hash table
                hash_table[j] = students[i];
            }
        }
    }

    // search for student with given name and roll no.
    char search_div = 'S';
    int search_roll_no = 17;
    int h = hash(search_div, search_roll_no) % HASH_SIZE;
    if (hash_table[h].roll_no == search_roll_no && hash_table[h].div == search_div) {
        // found student
        printf("Found student: %s (Roll No.: %d, Division: %c)\n",
               hash_table[h].name, hash_table[h].roll_no, hash_table[h].div);
    } else {
        // linear probing with chaining
        int j = h;
        do {
            j = (j + 1) % HASH_SIZE;
        } while (j != h && (hash_table[j].roll_no != search_roll_no || hash_table[j].div != search_div));

        if (j == h) {
            printf("Student not found\n");
        } else {
            // found student
            printf("Found student: %s (Roll No.: %d, Division: %c)\n",
                   hash_table[j].name, hash_table[j].roll_no, hash_table[j].div);
        }
    }

    return 0;
}
