// Write a C program to swap the content of 2 structure of student having data members are Student(name,age,roll,marks)
#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[50];
    int age;
    int roll;
    float marks;
};
void swapStudents(struct student *s1, struct student *s2)
{
    struct student temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
int main()
{
    struct student s1 = {"Shyam", 20, 22054029, 95.5};
    struct student s2 = {"Ram", 21, 22054039, 90.0};
    printf("Before swapping:\n");
    printf("s1: %s, %d, %d, %.1f\n", s1.name, s1.age, s1.roll, s1.marks);
    printf("s2: %s, %d, %d, %.1f\n", s2.name, s2.age, s2.roll, s2.marks);
    swapStudents(&s1, &s2);
    printf("\nAfter swapping:\n");
    printf("s1: %s, %d, %d, %.1f\n", s1.name, s1.age, s1.roll, s1.marks);
    printf("s2: %s, %d, %d, %.1f\n", s2.name, s2.age, s2.roll, s2.marks);
    return 0;
}