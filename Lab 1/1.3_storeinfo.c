#include <stdio.h>

struct Employee {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percent;
    float da_percent;
    float gross_salary;
};

int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Emp_ID: ");
        scanf("%d", &emp[i].emp_id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Designation: ");
        scanf("%s", emp[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);
        printf("HRA Percent: ");
        scanf("%f", &emp[i].hra_percent);
        printf("DA Percent: ");
        scanf("%f", &emp[i].da_percent);

        // Calculate gross salary
        emp[i].gross_salary = emp[i].basic_salary + 
                              (emp[i].basic_salary * emp[i].hra_percent / 100) + 
                              (emp[i].basic_salary * emp[i].da_percent / 100);
    }

    printf("\nEmployee Information:\n");

    for(int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Emp_ID: %d\n", emp[i].emp_id);
        printf("Name: %s\n", emp[i].name);
        printf("Designation: %s\n", emp[i].designation);
        printf("Basic Salary: %.2f\n", emp[i].basic_salary);
        printf("HRA Percent: %.2f\n", emp[i].hra_percent);
        printf("DA Percent: %.2f\n", emp[i].da_percent);
        printf("Gross Salary: %.2f\n", emp[i].gross_salary);
    }
}