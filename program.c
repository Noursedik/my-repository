#include <stdio.h>
#include<math.h>
#define min_amount 2 // The minimum amount of product
#define quantity 10 // The quantity of the products at the start 
/* Declaring the variables to be used in the program*/
static int admin_password=67678;                                                           
static char item1='A', item2='B', item3='C'; 
static float price1=2.0, price2=3.5, price3=1.5, total_amount;

/* Functions Prototypes*/
void display_itmes(void);
void admin_mode(void);
void end_program(void);

int main()
{
    int action;
    printf("Welcome to the Vending Machine\n");
    printf("Here are the options, please choose one:\n");
    printf("1-Purchase an Item\n2-Admin Mode\n3-Exit\n");
    scanf("%d",&action);
}
void display_itmes(void)// To diplay all details about the available items
{
    printf("The items availabe are:\n");
    printf("%c, code: 1, price %-8.2f\n",item1,price1);
    printf("%c, code: 2, price %-8.2f\n",item2,price2);
    printf("%c, code: 3, price %-8.2f\n",item3,price3);
    printf("Please select an item code or press 0 to cancel purchase:\n");
    int item_code;
    scanf("%d",&item_code);
}
void admin_mode(void)
{  
    printf("Please enter admin password:\n");
    int passcode;
    scanf("%d",&passcode);
} 
void end_program(void)
{
    printf("Thank you");
    return;
}