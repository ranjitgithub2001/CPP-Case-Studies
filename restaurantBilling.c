/*
 * Restaurant Management System
 * 
 * This program is a simple Restaurant Management System implemented in C.
 * It allows users to:
 * 1. Display the menu card
 * 2. Take orders for tables
 * 3. Generate bills for tables
 * 
 * The program uses structures to store menu items, orders, and table information.
 * Each table can place up to 10 orders. The program calculates the total bill for each table.
 * 
 * Features:
 * - Display Menu: Displays the list of dishes along with their prices.
 * - Take Order: Takes orders for a specified table number and calculates the total amount.
 * - Bill Making: Generates a bill for a specified table number and resets the table status.
 * 
 * Structures:
 * - menuCard: Stores the dish name and its price.
 * - bill: Stores details of a single order including dish name, quantity, price, and total amount.
 * - table: Stores the table status and an array of orders for that table.
 * 
 * Limitations:
 * - Each table can place up to 10 orders.
 * - The program is designed for 5 tables (Table numbers from 1 to 5).
 * 
 * Author: Ranjit Kale 
 */
#include <stdio.h>
#include <string.h>
int s=10;
typedef struct menuCard {
    char dishName[20];
    double price;
} menuCard;

typedef struct bill {
    char dish[20];
    int quantity;
    double price;
    double tamt;
} bill;

typedef struct table {
    int ch;
    bill bl[10];
} table;

void store(menuCard *);
void displayMenu(menuCard*);
int takeOrder(menuCard*,table*,int);
void billMaking(table*,int,int);
void main() 
{
    table tbl[5];
    menuCard menu[10];
    store(menu);
    int choice,i,count,c=0;

    for (i = 0; i < 5; i++) {
        tbl[i].ch = 0; 
    }

    do {
        printf("*--*--*--*--*(Ctrl + Eat)*--*--*--*--*\n");
        printf("Press 1 for Display menu card.\n");
        printf("Press 2 to take an order.\n");
        printf("Press 3 for Bill making.\n");
        printf("Enter the valid choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                displayMenu(menu);
                break;
            case 2:
                {
                    int tNo;
                    printf("Enter the table number from (1-5): ");
                    scanf("%d", &tNo);

                    if (tNo >= 1 && tNo <= 5) 
					{
                        if (tbl[tNo - 1].ch == 0) 
						{
                            tbl[tNo - 1].ch = 1;
                            printf("Table Number: %d\n",tNo);
                            count=takeOrder(menu, tbl, tNo - 1);
                        } else {
                            printf("Table is not vacant.\n");
                        }
                    } else {
                        printf("Invalid table number.\n");
                    }
                }
                break;
            case 3:
                {
                    int tNo;
                    printf("Enter the table number from (1-5): ");
                    scanf("%d", &tNo);

                    if (tNo >= 1 && tNo <= 5 && tbl[tNo - 1].ch == 1) 
					{
                        billMaking(tbl, tNo - 1,count);
                        tbl[tNo - 1].ch = 0;
                    } else {
                        printf("Table is vacant.\n");
                    }
                }
                break;
            default:
                printf("Invalid Choice\n");
        }

        
        printf("\nPress 1 to enter a valid choice: ");
        scanf("%d", &c);
    } while (c == 1);
}

void store(menuCard *menu) {
    strcpy(menu[0].dishName,"Chapati(ch)");
	menu[0].price=10;
	
	strcpy(menu[1].dishName,"Kurdai Papad(kp)");
	menu[1].price=20;
	
	strcpy(menu[2].dishName,"Butter Roti(br)");
	menu[2].price=20;
	
	strcpy(menu[3].dishName,"Paneer Tikka(pt)");
	menu[3].price=150;
	
	strcpy(menu[4].dishName,"Dal Tadka(dt)");
	menu[4].price=120;
	
	strcpy(menu[5].dishName,"Panner Bhurji(pb)");
	menu[5].price=140;
	
	strcpy(menu[6].dishName,"Mix Veg(mv)");
	menu[6].price=120;
	
	strcpy(menu[7].dishName,"Jeera Rice(jr)");
	menu[7].price=70;
	
	strcpy(menu[8].dishName,"Indrayani Rice(ir)");
	menu[8].price=100;
	
	strcpy(menu[9].dishName,"Gulab Jamun(gj)");
	menu[9].price=80;
}

void displayMenu(menuCard* menu) 
{
    int i;
	printf("+----------------------------------------------------------------+\n");
	printf("|\tDish Name                                            Price \n");
	for(i=0;i<=9;i++)
	{
		printf("|\t%-44s| %-44lf\n", menu[i].dishName,menu[i].price);
	}
}
int takeOrder(menuCard* menu, table* tbl, int tNo) {
    int i = 0, a = 0;
    char o[5];
    do {
        printf("Enter order: ");
        fgets(o, sizeof(o), stdin);
        o[strcspn(o, "\n")] = 0;  
        
        if (strcmp(o, "ch") == 0 || strcmp(o, "kp") == 0 || strcmp(o, "br") == 0 || strcmp(o, "pt") == 0 || 
            strcmp(o, "dt") == 0 || strcmp(o, "pb") == 0 || strcmp(o, "mv") == 0 || strcmp(o, "jr") == 0 || 
            strcmp(o, "ir") == 0 || strcmp(o, "gj") == 0) {
            
            printf("Quantity? : ");
            scanf("%d", &tbl[tNo].bl[i].quantity);
            getchar();  // Consume the newline character
            
            if(strcmp(o,"ch")==0){
                strcpy(tbl[tNo].bl[i].dish, menu[0].dishName);
                tbl[tNo].bl[i].price = menu[0].price;
            }
            else if(strcmp(o,"kp")==0){
                strcpy(tbl[tNo].bl[i].dish, menu[1].dishName);
                tbl[tNo].bl[i].price = menu[1].price;
            }
            else if(strcmp(o,"br")==0){
                strcpy(tbl[tNo].bl[i].dish, menu[2].dishName);
                tbl[tNo].bl[i].price = menu[2].price;
            }
            else if(strcmp(o,"pt")==0){
                strcpy(tbl[tNo].bl[i].dish, menu[3].dishName);
                tbl[tNo].bl[i].price = menu[3].price;
            }
            else if(strcmp(o,"dt")==0){
                strcpy(tbl[tNo].bl[i].dish, menu[4].dishName);
                tbl[tNo].bl[i].price = menu[4].price;
            }
            else if(strcmp(o,"pb")==0){
                strcpy(tbl[tNo].bl[i].dish, menu[5].dishName);
                tbl[tNo].bl[i].price = menu[5].price;
            }
            else if(strcmp(o,"mv")==0){
                strcpy(tbl[tNo].bl[i].dish, menu[6].dishName);
                tbl[tNo].bl[i].price = menu[6].price;
            }
            else if(strcmp(o,"jr")==0){
                strcpy(tbl[tNo].bl[i].dish, menu[7].dishName);
                tbl[tNo].bl[i].price = menu[7].price;
            }
            else if(strcmp(o,"ir")==0){
                strcpy(tbl[tNo].bl[i].dish, menu[8].dishName);
                tbl[tNo].bl[i].price = menu[8].price;
            }
            else if(strcmp(o,"gj")==0){
                strcpy(tbl[tNo].bl[i].dish, menu[9].dishName);
                tbl[tNo].bl[i].price = menu[9].price;
            }
            
            tbl[tNo].bl[i].tamt = tbl[tNo].bl[i].quantity * tbl[tNo].bl[i].price;
            
        } else {
            printf("Invalid Dish Name.\n");
            continue;
        }
        
        printf("Anything Else->1: ");
        scanf("%d", &a);
        getchar();  
        
        i++;
    } while (a == 1 && i < 10);  // Limiting to 10 orders per table
    
    return i;
}



void billMaking(table* tbl, int tNo,int count) 
{
    printf("\n*********** Bill ***********\n");
    printf("Table Number: %d\n", tNo + 1);

    double totalBill = 0;

    printf("Dish\t\tQuantity\tPrice\t\tTotal\n");
    printf("--------------------------------------------\n");
	int i;
    for (i = 0; i<count; i++) 
	{
        printf("%-20s%-8d%-12.2lf%.2lf\n", tbl[tNo].bl[i].dish, tbl[tNo].bl[i].quantity,tbl[tNo].bl[i].price, tbl[tNo].bl[i].tamt);
        totalBill = totalBill+tbl[tNo].bl[i].tamt;
    }

    printf("--------------------------------------------\n");
    printf("Total Bill: %.2lf\n", totalBill);

    tbl[tNo].ch = 0;

    printf("Thank you for dining with us!\n");
}

