// Write a program to create a structure to store the information of n number of Employees. Employee's information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the information of employees with gross salary. Use array of structure.
// DA = 45*Basic
// HRA = 15*Basic
// Gross-salary = Basic + HRA + DA

#include <stdio.h>

struct employee
{
    int id;
    char name[25];
    char designation[25];
    int basicSalary;
    int da, hra, grossSalary;
};

int main()
{
    int num;
    printf("Enter the number of employee : ");
    scanf("%d", &num);

    struct employee emp[num];

    for (int i = 0; i < num; i++)
    {
        printf("Enter the information of employee :- \n");
        printf("Enter the Emp-id :- ");
        scanf("%d", &emp[i].id);
        printf("Enter the Name of employee :- ");
        scanf("%s", &emp[i].name);
        printf("Enter the Designation of employee :- ");
        scanf("%s", &emp[i].designation);
        printf("Enter the basic salary of employee :- ");
        scanf("%d", &emp[i].basicSalary);

        emp[i].da = 45 * emp[i].basicSalary;
        emp[i].hra = 15 * emp[i].basicSalary;
        emp[i].grossSalary = emp[i].basicSalary + emp[i].hra + emp[i].da;
    }

    printf("\nThe detail of employee are : \n");
    for (int i = 0; i < num; i++)
    {
        printf("Employee ID: %d \n", emp[i].id);
        printf("Employee Name: %s \n", emp[i].name);
        printf("Employee Designation: %s \n", emp[i].designation);
        printf("Employee basic salary: %d \n", emp[i].basicSalary);
        printf("Employee DA: %d \n", emp[i].da);
        printf("Employee HRA: %d \n", emp[i].hra);
        printf("Employee Gross salary: %d \n", emp[i].grossSalary);
    }
}