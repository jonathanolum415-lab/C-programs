
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define SUBJECTS 5

// Student structure
struct Student {
    char name[50];
    float marks[SUBJECTS];
    float total;
    float average;
    char grade;
};

// Function to calculate grade
char calculateGrade(float average) {

    if (average >= 80)
        return 'A';
    else if (average >= 70)
        return 'B';
    else if (average >= 60)
        return 'C';
    else if (average >= 50)
        return 'D';
    else
        return 'F';
}

// Function to enter valid marks
float getMarks(int subjectNumber) {

    float marks;

    while (1) {

        printf("Enter subject %d marks (0-100): ",
               subjectNumber);

        if (scanf("%f", &marks) != 1) {

            printf("Invalid input! Enter a number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            continue;
        }

        if (marks >= 0 && marks <= 100) {
            return marks;
        }

        printf("Marks must be between 0 and 100.\n");
    }
}

// Function to add student
void addStudent(struct Student students[], int *count) {

    if (*count >= MAX_STUDENTS) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter student name: ");

    scanf(" %49[^\n]", students[*count].name);

    students[*count].total = 0;

    for (int i = 0; i < SUBJECTS; i++) {

        students[*count].marks[i] = getMarks(i + 1);

        students[*count].total +=
            students[*count].marks[i];
    }

    students[*count].average =
        students[*count].total / SUBJECTS;

    students[*count].grade =
        calculateGrade(students[*count].average);

    (*count)++;

    printf("\nStudent added successfully!\n");
}

// Function to view students
void viewStudents(struct Student students[], int count) {

    if (count == 0) {
        printf("No students registered yet.\n");
        return;
    }

    for (int i = 0; i < count; i++) {

        printf("\n===== STUDENT %d =====\n", i + 1);

        printf("Name: %s\n", students[i].name);

        printf("Total: %.2f\n", students[i].total);

        printf("Average: %.2f\n", students[i].average);

        printf("Grade: %c\n", students[i].grade);
    }
}

// Function to search student
void searchStudent(struct Student students[], int count) {

    char searchName[50];

    printf("Enter student name to search: ");

    scanf(" %49[^\n]", searchName);

    for (int i = 0; i < count; i++) {

        if (strcmp(students[i].name, searchName) == 0) {

            printf("\nStudent found!\n");

            printf("Name: %s\n", students[i].name);

            printf("Total: %.2f\n", students[i].total);

            printf("Average: %.2f\n", students[i].average);

            printf("Grade: %c\n", students[i].grade);

            return;
        }
    }

    printf("Student not found!\n");
}

// Main function
int main() {

    struct Student students[MAX_STUDENTS];

    int count = 0;
    int choice;

    do {

        printf("\n============================\n");
        printf("  STUDENT MANAGEMENT SYSTEM\n");
        printf("============================\n");

        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {

            printf("Please enter a valid menu number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            continue;
        }

        switch (choice) {

            case 1:
                addStudent(students, &count);
                break;

            case 2:
                viewStudents(students, count);
                break;

            case 3:
                if (count == 0) {
                    printf("No students to search.\n");
                } else {
                    searchStudent(students, count);
                }
                break;

            case 4:
                printf("Thank you for using the system!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
