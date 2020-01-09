/*Rafael Chavez
3/26/18*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/*PROBLEM ANALYSIS
Goal: Create pizza ordering application
Input: User inputs numbers [1-3] for pizza size, and [1-5] for toppings
Output: User's choices with prices totaled
Formula: addTax = (pizzaSizeCost + toppingCost) * .1;
Requirements: Integers for user input. Floats to calculate price totals. Switch case for choices; and functions for organization.
*/
//Function Prototype
void openingScreen(); //opening logo screen
void pizzaSize(); //size of pizza function
void pizzaToppings(); //toppings function

//Declarations
int pizzaChoice; //user's size choice
int pizzaTop; //user's topping choice
float pizzaSizeCost = 0; //price of user's pizza size (initialized to 0)
float toppingCost = 0; //price of user's pizza toppings (initialized to 0)
float addTax; //tax on customer's order

int main()
{
	int loopControl = 1; //loop control variable initialized
	
	system("color bc"); //background color (light blue); font color (red)
	openingScreen();
	
	while(loopControl != 2){ //user places order at this point 
		pizzaSize();
		pizzaToppings();
		printf("You ordered:\n"); //receipt displayed here
		printf("Size\t\t$%.2f\n", pizzaSizeCost);
		printf("Toppings\t$%.2f\n\n", toppingCost);
		addTax = (pizzaSizeCost + toppingCost) * .1; //tax calculation
		printf("Tax\t\t$%.2f\n\n", addTax);
		printf("Order Total\t$%.2f\n\n", pizzaSizeCost + toppingCost + addTax); //total displayed
		printf("Your order has been placed and your pizza will arrive in 30 minutes.\n"); //oder placed
		printf("If not, it's FREE. Enjoy your pizza!\n\n\n");
		printf("\nWould you like to place another order?\n");
		printf("(1) for Yes\n(2) for No\n");
		scanf("%d", &loopControl);
		while(loopControl < 1 || loopControl >2){ //validates potential for ordering again (limited to numbers 1 or 2)
			printf("Please enter (1) to place another order, or (2) to exit\n");
			scanf("%d", &loopControl);
		}
	}
	printf("\n************\\(^U^)/ Thank you for ordering at Pizza City! \\(`u`)/***************\n"); //thank you prompt with  happy faces!
	system ("pause"); //holds window open
	return 0; //successful program
}

void openingScreen()
{ //opening screen logo
	printf("\n\t\t\t       **************\n");
	Sleep(100);
	printf("\t\t\t    ********************\n");
	Sleep(100);
	printf("\t\t\t  *******\t ##*******\n");
	Sleep(100);
	printf("\t\t\t ***##\t\t ###\t***\n");
	Sleep(100);
	printf("\t\t\t***###\t###\t\t ***\n");
	Sleep(100);
	printf("\t\t       ***\t###\t\t  ***\n");
	Sleep(100);
	printf("\t\t       **\tWELCOME TO  ###    **\n");
	Sleep(100);
	printf("\t\t       **\tPIZZA CITY! ###    **\n");
	Sleep(100);
	printf("\t\t       **   ###\t\t###        **\n");
	Sleep(100);
	printf("\t\t       **   ###\t\t###        **\n");
	Sleep(100);
	printf("\t\t       **\t\t\t   **\n");
	Sleep(100);
	printf("\t\t       ***\t###\t\t  ***\n");
	Sleep(100);
	printf("\t\t\t***\t###\t      ###***\n");
	Sleep(100);
	printf("\t\t\t ***\t      ###     ##***\n");
	Sleep(100);
	printf("\t\t\t  *******     ###  *******\n");
	Sleep(100);
	printf("\t\t\t    ********************\n");
	Sleep(100);
	printf("\t\t\t       **************\n");
	system("pause");
	system("cls");
}

void pizzaSize() //used for ordering pizza size
{
	system("cls");
	printf("What size pizza will you be ordering today?\n\n");//display pizza size options and scan user's choice
	printf("(1) - Small\t<$5.00>\n");
	printf("(2) - Medium\t<$7.00>\n");
	printf("(3) - Large\t<$10.00>\n\n");
	printf("Type 1-3 below:\n");
	scanf("%d", &pizzaChoice);
	while(pizzaChoice < 1|| pizzaChoice > 3){
		printf("Error: Please choose 1-3 for your pizza size\n");
		scanf("%d", &pizzaChoice);
	}
	switch(pizzaChoice){
		case 1:
			printf("You selected: Small\n");
			pizzaSizeCost = pizzaSizeCost + 5.00;
			system("pause");			
			break;
		case 2:
			printf("You selected: Medium\n");
			pizzaSizeCost = pizzaSizeCost + 7.00;
			system("pause");
			break;
		case 3:
			printf("You selected: Large\n");
			pizzaSizeCost = pizzaSizeCost + 10.00;
			system("pause");
			break;
		default:
			system("cls");
			printf("Error: Please enter 1-3\n\n");
			printf("What size of pizza would you like?\n\n");
			printf("Choose (1) for Small\t<$5.00>\n");
			printf("Choose (2) for Medium\t<$7.00>\n");
			printf("Choose (3) for Large\t<$10.00>\n\n");
			scanf(" %c", &pizzaChoice);
	}
	system("cls");
}

void pizzaToppings() //choose pizza topping
{
	int closeLoop = 0; //used for ending while loop
	
	system("cls");	
	printf("What toppings would you like?\n\n"); //asks for topping with options below
	printf("(1) - Extra Cheese\t<$1.50>\n");
	printf("(2) - Pepperoni\t\t<$2.50>\n");
	printf("(3) - Veggie\t\t<$2.50>\n");
	printf("(4) - Combination\t<$3.00>\n");
	printf("(5) - No (More) Toppings\n\n"); //note:"more" is in parenthesis in grammatical sense incase they never wanted toppings to order
	puts("Type your choice below:");
	scanf("%d", &pizzaTop);
	while(closeLoop != -1){ //runs while close loop doens't equal 1
		switch(pizzaTop){
			case 1:
				printf("You selected: Extra Cheese\n"); //cheese topping with calculation
				toppingCost = toppingCost + 1.50;
				printf("Select another topping:\n");
				scanf("%d", &pizzaTop);
				break;
			case 2:
				printf("You selected: Pepperoni\n"); //pepperoni topping with calculation
				toppingCost = toppingCost + 2.50;
				printf("Select another topping:\n");
				scanf("%d", &pizzaTop);
				break;
			case 3:
				printf("You selected: Veggie\n"); //veggie topping with calculation
				toppingCost = toppingCost + 2.50;
				printf("Select another topping:\n");
				scanf("%d", &pizzaTop);
				break;
			case 4:
				printf("You selected: Combination\n"); //combination topping with calculation
				toppingCost = toppingCost + 3.00;
				printf("Select another topping:\n");
				scanf("%d", &pizzaTop);
				break;
			case 5:
				closeLoop = -1; //No more toppings chosen; exits loop
				break;
			default:
				system("cls");
				printf("Error: Please enter a number between 1-5\n\n"); //Error message ,reenter value below
				printf("What toppings would you like?\n\n");
				printf("1 for Extra Cheese\t<$1.50>\n");
				printf("2 for Pepperoni\t\t<$2.50>\n");
				printf("3 for Veggie\t\t<$2.50>\n");
				printf("4 for Combination\t<$3.00>\n");
				printf("5 for No More Toppings\n\n");
				puts("Type your choice below:");
				scanf("%d", &pizzaTop);
				
		}
	}
	
	system("cls");
}

