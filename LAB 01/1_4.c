#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int EmpId;
    char Name[50];
    char Designation[20];
    int BasicSalary;
    int HRA;
    int DA;
};
int main()
{
    int n;
    printf("Enter no of Employee:");
    scanf("%d",&n);
    int GrossSalary[n];
    struct Employee Emp[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter employee %d information: \n",i+1);
        scanf("%d",&Emp[i].EmpId);
        scanf("%s",Emp[i].Name);
        scanf("%s",Emp[i].Designation);
        scanf("%d",&Emp[i].BasicSalary);
        scanf("%d",&Emp[i].HRA);
        scanf("%d",&Emp[i].DA);
        GrossSalary[i] =((Emp[i].HRA*Emp[i].BasicSalary+Emp[i].DA*Emp[i].BasicSalary)/100)+Emp[i].BasicSalary;
    }
    printf("Employee information: \n");
    for(int i=0;i<n;i++)
    {
        printf("Employee Id: %d \n",Emp[i].EmpId);
        printf("Name: %s \n",Emp[i].Name);
        printf("Designation: %s \n",Emp[i].Designation);
        printf("Basic Salary: %d \n",Emp[i].BasicSalary);
        printf("HRA % : %d % \n",Emp[i].HRA);
        printf("DA % : %d % \n",Emp[i].DA);
        printf("Gross Salary: %d \n",GrossSalary[i]);
        printf("\n");
    }
    return 0;
}
