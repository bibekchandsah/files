// Wap in C to display and accept of the details of n number of  employee(id,name,salary) details using dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>
struct employee
{
    int id;
    char name[50];
    float salary;
};
int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct employee *employees = (struct employee *)malloc(n * sizeof(struct employee));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }
    printf("\nThe details of the employees are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Salary: %.2f\n\n", employees[i].salary);
    }
    return 0;
}