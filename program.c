#include <stdio.h>
#include<math.h>
#define min_amount 2 // The minimum amount of product
/* Declaring the variables to be used in the program*/
static int admin_password=67678;                                                           
static char item1='A', item2='B', item3='C',item_name;; 
static float price1=2.0, price2=3.5, price3=1.5, total_sales;
int item_code,quantity=10;

/* Functions Prototypes*/
void display_itmes(void);
void admin_mode(void);
void end_program(void);
int pruchase_confirmation(void);
void pay(void);

int main(){   
       int action;
        printf("Welcome to the Vending Machine\n");
        printf("Here are the options, please choose one:\n");
        printf("1-Purchase an Item\n2-Admin Mode\n3-Exit\n");
        scanf("%d",&action);
        switch(action){
        case 1:
        display_itmes();
        break;
        case 2:
        admin_mode();
        break; 
        case 3:
        end_program();
        break;
        default:
        printf("Invalid number");

        } 
    return(1);
}

void pay(void){
    float amount_to_pay,total_paid=0,coin;
    int cancel;
    switch(item_code){
        case 1:
        amount_to_pay=price1;
        item_name=item1;
        break;
        case 2:
        amount_to_pay=price2;
        item_name=item2;
        break;
        case 3:
        amount_to_pay=price3;
        item_name=item3;
    }
    printf("Please pay using these coins only[1,0.5,0.25]AED\n");
    printf("Amount to pay:%-8.2f\n",amount_to_pay);
     while (total_paid < amount_to_pay) {
        printf("Please insert coin ");
        scanf("%f",&coin);
        if (coin==1 || coin==0.5 || coin==0.25){
       total_paid+=coin;
        }
            else {
                printf("Invalid coin inserted\n");
                printf("Would you like to cancel purchase?(1=Yes or 0=No)");
                scanf("%d",&cancel);
                    if (cancel==1){
                        display_itmes();
                        return;
                    }
                        else {
                            printf("The machine will eject the coin, collect it and repay\n");
                            pay();
                        }
            }
    }
    if (total_paid==amount_to_pay){
        ++total_sales;
        --quantity;
        printf("Thank you for buying item %c, price %-8.2f\n",item_name,amount_to_pay);
        printf("You paid %-8.2f, No change",total_paid);
    }
        else{
            if (total_paid>amount_to_pay){
                ++total_sales;
                --quantity;
                printf("Thank you for buying item %c, price %-8.2f\n",item_name,amount_to_pay);  
                printf("The change is %-8.2f, please collect it",total_paid-amount_to_pay);
            }

        }
if (quantity<=min_amount){
    printf("Alert, there isan item quantity that ts less than the minimum quantity");
}
return;
}




int pruchase_confirmation(void)
{   int confirm;
    printf("Please press 1 to confirm purchase\nor\n0 to cancel\n");
    scanf("%d",&confirm);
    if (confirm==1){
           pay();
        }
        else{
            display_itmes();

        } 
    return(confirm);
}
void display_itmes(void)// To diplay all details about the available items
{
    printf("The items availabe are:\n");
    printf("%c, code: 1, price %-8.2f\n",item1,price1);
    printf("%c, code: 2, price %-8.2f\n",item2,price2);
    printf("%c, code: 3, price %-8.2f\n",item3,price3);
    printf("Please select an item code or press 0 to cancel purchase:\n");

    scanf("%d",&item_code);
    switch(item_code){
        case 1:
        printf("Item chosen is %c, price is %-8.2f\n ",item1,price1);
        pruchase_confirmation();
        break;
        case 2:
        printf("Item chosen is %c, price is %-8.2f\n ",item2,price2);
        pruchase_confirmation();
        break;
        case 3:
        printf("Item chosen is %c, price is %-8.2f\n ",item3,price3);
        pruchase_confirmation();
        break;
        case 0:
        printf("The purchase is cancelled");
        return;
        break;
        default:
        printf("Invalid number");
        return;
        break;

    }
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



