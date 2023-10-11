#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define min_amount 2 // The minimum amount of product
/* Declaring the variables to be used in the program*/
static int admin_password=67678,passcode;;                                                           
static char item1='A', item2='B', item3='C',item_name;; 
static float price1=2.0, price2=3.5, price3=1.5, total_quantitysales=0, totalsales=0,new_price;
int item_code,quantity1=10,quantity2=10,quantity3=10;

/* Functions Prototypes*/
void display_itmes(void);
void admin_mode(void);
void end_program(void);
int pruchase_confirmation(void);
void pay(void);
void replenishsitems(void);
void changeitemprice(void);
void displaytotalsales(void);
void display_itmes2(void);
void enter_password(void);

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
        enter_password();
        admin_mode();
        break; 
        case 3:
        end_program();
        break;
        default:
        printf("Invalid number\n");
        main();
        return(1);
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
        ++total_quantitysales;
        printf("The total quantity sales now is:%-8.2f\n",total_quantitysales);
        printf("Thank you for buying item %c, price %-8.2f\n",item_name,amount_to_pay);
        printf("You paid %-8.2f, No change\n\n",total_paid);
        totalsales+=amount_to_pay;
        switch(item_code){
        case 1:
        --quantity1;
        printf("The quantity of product %c now is: %d\n",item1,quantity1);
        break;
        case 2:
        --quantity2;
        printf("The quantity of product %c now is: %d\n",item2,quantity2);
        break;
        case 3:
        --quantity3;
        printf("The quantity of product %c now is: %d\n",item3,quantity3);
    }
    }
        else{
            if (total_paid>amount_to_pay){
                ++total_quantitysales;
                printf("The total quantity sales now is:%-8.2f\n",total_quantitysales);
                printf("Thank you for buying item %c, price %-8.2f\n",item_name,amount_to_pay);  
                printf("The change is %-8.2f, please collect it\n\n",total_paid-amount_to_pay);
                totalsales+=amount_to_pay;
                switch(item_code){
                case 1:
                --quantity1;
                printf("The quantity of product %c now is: %d\n",item1,quantity1);
                break;
                case 2:
                --quantity2;
                printf("The quantity of product %c now is: %d\n",item2,quantity2);
                break;
                case 3:
                --quantity3;
                printf("The quantity of product %c now is: %d\n",item3,quantity3);
            }
            }

        }
if (quantity1<=min_amount){
    printf("Alert, item %c quantity is less than the minimum quantity\n",item1);
}
else {
    if (quantity2<=min_amount){
    printf("Alert, item %c quantity is less than the minimum quantity\n",item2);
    }
    else {
        if (quantity3<=min_amount){
        printf("Alert, item %c quantity is less than the minimum quantity\n",item3);
    }
    }
}
main();
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
        printf("The purchase is cancelled\n");
        main();
        return;
        break;
        default:
        printf("Invalid number");
        display_itmes();
        return;
        break;

    }
    return;
}


void replenishsitems(void){
    printf("replenishing items\n");
    quantity1= rand() % 20 + 1;  
    quantity2= rand() % 20 + 1;  
    quantity3= rand() % 20 + 1;  
    printf("Items replenished:\n");
    printf("%c: %d\n",item1,quantity1);
    printf("%c: %d\n",item2,quantity2);
    printf("%c: %d\n",item3,quantity3);
    admin_mode();
    return;
}




void changeitemprice(void){
    printf("Please select the product you wish to change the price for(1-A,2-B,3-C)\n");
    scanf("%d",&item_code);
        switch(item_code){
            case 1:
            printf("You chose item %c, price %-8.2f\n",item1,price1);
            printf("Please eneter the new price for this product\n");
            scanf("%f",&new_price);
            price1=new_price;
            break;
            case 2:
            printf("You chose item %c, price %-8.2f\n",item2,price2);
            printf("Please eneter the new price for this product\n");
            scanf("%f",&new_price);
            price2=new_price;
            break;
            case 3:
            printf("You chose item %c, price %-8.2f\n",item3,price3);
            printf("Please eneter the new price for this product\n");
            scanf("%f",&new_price);
            price3=new_price;
            break;
            default: 
            printf("Invalid product name, please try again\n");
            admin_mode();
            return;
    }
    admin_mode();
    return;

}   


void displaytotalsales(void){
    int reset;
    printf("The total sales:%-8.2f\n",totalsales);
    printf("Would you like to reset the total sales to 0?\n(1-Yes,0-No)");
    scanf("%d",&reset);
    if (reset==1)
    totalsales=0;
    else {
        if(reset==0)
        ;
        else {
            printf("Invalid number,please try again\n");
            displaytotalsales();
        }
    }
    printf("Please do not forget to collect sales money.\n");
    admin_mode();
    return;

}



void display_itmes2(void){
    printf("The items availabe are:\n");
    printf("%c, code: 1, price %-8.2f,quantity %d\n",item1,price1,quantity1);
    printf("%c, code: 2, price %-8.2f,quantity %d\n",item2,price2,quantity2);
    printf("%c, code: 3, price %-8.2f,quantity %d\n",item3,price3,quantity3);
    if (quantity1<=min_amount){
    printf("Alert, item %c quantity is less than the minimum quantity\n",item1);
}
else {
    if (quantity2<=min_amount){
    printf("Alert, item %c quantity is less than the minimum quantity\n",item2);
    }
    else {
        if (quantity3<=min_amount){
        printf("Alert, item %c quantity is less than the minimum quantity\n",item3);
    }
    }
}
    admin_mode();
    return;
}

void enter_password(void)
{
    printf("Please enter admin password:\n");
    scanf("%d",&passcode);
    return;
}
void admin_mode(void)
{  
    
    int option;
    if(passcode==admin_password){
        printf("Please select one of the following actions\n");
        printf("1-Replenish Items\n2-Change Item Prices\n3-Display Total Sale\n4-Display Item Availability\n0-Exit Admin Mode\n");
        scanf("%d",&option);
        switch (option){
            case 1:
            replenishsitems();
            break;
            case 2:
            changeitemprice();
            break;
            case 3:
            displaytotalsales();
            break;
            case 4:
            display_itmes2();
            break;
            case 0:
            printf("Exiting Adim Mode\n");
            main();
            return;
            default:
            printf("Invalid Option, pleaase try again\n");
            admin_mode();


        }

    }
    else {
        printf("Incorrect Pasword\n");
        main();
        return;
    }
    return;
} 


void end_program(void)
{
    printf("Thank you");
    return;
}



