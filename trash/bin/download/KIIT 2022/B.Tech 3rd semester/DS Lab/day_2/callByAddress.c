// Write a C program to assign values to each members of the following structure. Pass the populated structure to a function Using call-by address and print the value of each member of the structure with in that function.
// struct info{
// int roll_no;
// char name[50];
// float CGPA;
// }

#include <stdio.h>
// Define the structure
struct info
{
    int roll_no;
    char name[50];
    float CGPA;
};
// Function to print the values of the structure using call-by-address
void printInfo(struct info *student)
{
    printf("Roll Number: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->CGPA);
}
int main()
{
    struct info student1;
    // Populate the structure members
    student1.roll_no = 101;
    strcpy(student1.name, "John Doe");
    student1.CGPA = 3.75;
    // Pass the structure to the function using call-by-address
    printInfo(&student1);
    return 0;
}
