#include <stdio.h>

int main()
{
    char name[50];
    char grade;
    float mathematics;
    float english;
    float computer;
    float biology;
    float physics;
    float total;
    float average;
    
    printf("\n====================================\n");
    printf("\n===== STUDENT MARKS CALCULATOR =====\n");
    printf("\n====================================\n");
    
    printf("Enter student's name: ");
    scanf("%49s", name);

    printf("Enter mathematics marks: ");
    scanf("%f", &mathematics);

    printf("Enter english marks: ");
    scanf("%f", &english);

    printf("Enter computer marks: ");
    scanf("%f", &computer);

    printf("Enter biology marks: ");
    scanf("%f", &biology);

    printf("Enter physics marks: ");
    scanf("%f", &physics);

    //    the calculations start here
    total = mathematics + english + computer + biology + physics;
    average = total / 5;
    //    the if statements come in
    if (average >= 80)
    {
        grade = 'A';
    }
    else if (average >= 70)
    {
        grade = 'B';
    }
    else if (average >= 60)
    {
        grade = 'C';
    }
    else if (average >= 50)
    {
        grade = 'D';
    }
    else
    {
        grade = 'F';
    }
    //	student results
    printf("\n==============================\n");
    printf("\n===== STUDENT RESULTS =====\n");
    printf("\n==============================\n");
    printf("Student Name: %s\n", name);

    printf("Mathematics: %.2f\n", mathematics);
    printf("English: %.2f\n", english);
    printf("Computer: %.2f\n", computer);
    printf("Biology: %.2f\n", biology);
    printf("Physics: %.2f\n", physics);
    //    the calculations
    printf("Total Marks: %.2f\n", total);
    printf("Average: %.2f\n", average);
    printf("Grade: %c\n", grade);
    return 0;
}
