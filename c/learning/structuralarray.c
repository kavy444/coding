#include <stdio.h>
struct employee
{
    int code;
    float salary;
    char name[20];
};
int main()
{
    struct employee facebook[100];
    facebook[0].salary = 100;
    facebook[1].salary = 879;
    printf("%f %f\n",facebook[0].salary,facebook[1].salary);
    struct employee kavyansh={3,768,"hey hi"};
    struct employee *ptr;
    ptr=&kavyansh;//ptr pointer in structure storing value of kavyansh
    printf("%d",(*ptr).code);
    return 0;
}