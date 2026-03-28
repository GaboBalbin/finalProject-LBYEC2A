#include <stdio.h>
#include <string.h>
#include <conio.h>


// login
void login(){
    char username[100];
    char password[100];
    char ch;
    int i;

    char user[] = "hello";
    char pass[] = "world";

    while (1) {
        // Iteration number i
        i = 0;

        // Asks username
        printf("Username: ");
        scanf("%s", username);

        // Asks password
        printf("Password: ");
        // Replace the letters with *
        while (1) {
            ch = getch();

            if (ch == 13) break; // Checks for Enter
            else if (ch == 8) {  // Checks for Backspace
                if (i > 0) {
                    i--; // Moves back one index in the array (Delete)
                    printf("\b \b"); // Deletes the asterisk and the letter
                }
            }
            else{
                password[i++] = ch; // Adds the pressed letter on the password array
                printf("*");
            }
        }
        password[i] = '\0'; // Adds where the string ends to be checked for validity
        printf("\n");

        // Check validity
        if (strcmp(username, user) == 0 && strcmp(password, pass) == 0) {
            printf("Valid user\n");
            break;
        } else {
            printf("Invalid user\n\n");
        }
    }
}

// Option to take by the user
int action(){
    int options;
    printf("Resutation options\n\n");

    printf("1 Back to Menu\n");
    printf("2 Take Order\n");
    printf("3 Exit\n\n");
    printf("Option: ");
    // Check if option taken is valid
    while(1){
        int input = scanf("%d", &options);
        if(input != 1){
            printf("Invalid input\n");
            // Removes ALL the characters on the input so that it can take another one. That's why it's a loop
            while(1){
                char c = getchar();
                if(c == '\n'){
                break;
            }
        }

            continue;
        }
        switch (options)
        {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;   
        default:
            printf("Invalid Input\n");
        }
    }

    return 0;
}

// The receipt
void receipt(int order[], int quantity[], int total[], char itemNames[][100], int orderIteration, int price[]){
    printf("Receipt\n");
    printf("%-10s %-20s %-10s %-10s\n", "Order", "Item", "Qty", "Price");
    for(int i = 0; i < orderIteration; i++){
        printf("%-10d %-20s %-10d %-10d\n",
               order[i],
               itemNames[order[i] - 1],
               quantity[i],
               price[i]);
    }
    printf("Grand Total: %d\n", total[orderIteration - 1]);

}


// take order
int takeOrder(int itemNum[], int itemPrice[], char itemNames[][100]){
    int order[100];
    int quantity[100];
    int total[100];
    int orderIteration = 0;
    int price[100];
    char add;
    
    
    while(1){
        printf("Take Order\n\n");
        printf("Enter Order: ");
        int inputOrder = scanf("%d", &order[orderIteration]);
        // Check if valid input
        if(inputOrder != 1){
            printf("Invalid input\n");
            // Removes ALL the characters on the input so that it can take another one. That's why it's a loop
            while(1){
                char c = getchar();
                if(c == '\n'){
                break;
        }
            
        }
        continue;
    }   
        // Check if number inputted is actually in the menu
        else if(order[orderIteration] < 1 || order[orderIteration] > 2){
            printf("Invalid item number\n\n");
            continue;
        }


        printf("Quantity: ");
        int inputQuantity = scanf("%d", &quantity[orderIteration]);
        // Same validity checks as last time
        if(inputQuantity != 1){
            printf("Invalid input\n");
            while(1){
                char c = getchar();
                if(c == '\n'){
                break;
        }
            
        }
        continue;
    }
        // Checks if quantity number is valid
        else if(quantity[orderIteration] <= 0){
            printf("Quantity must be greater than 0\n\n");
            continue;
        }
        
        // If this is the first order, then do this
        if(orderIteration == 0){
            // Adds the item price and its corresponding quantity to the total
            total[orderIteration] = (itemPrice[order[orderIteration] - 1] * quantity[orderIteration]);
            // Adds this SINGULAR item's total into its total price
            price[orderIteration] = total[orderIteration];
        }
        // If this is NOT the first order and there were others beforehand to add to the total
        else{
            // Same as last time but now you add the previous total
            total[orderIteration] = (itemPrice[order[orderIteration] - 1] * quantity[orderIteration]) + total[orderIteration - 1];
            // However, price still needs to be about this singular item later for total. So do the same operation as last time
            price[orderIteration] = (itemPrice[order[orderIteration] - 1] * quantity[orderIteration]);
        }

        printf("TOTAL: %d\n", total[orderIteration]);
        // Adds to the iteration of how many orders you have done
        orderIteration++;
        while(1){
            printf("Additional Orders? (Press y or n): ");
            scanf(" %c", &add);
            if(add == 'y'){
                break;
            }
            else if(add == 'n'){
                receipt(order, quantity, total, itemNames, orderIteration, price);
                return 0;
            }
            else{
                printf("Invalid Choice\n");
                continue;
            }
        }
    }
}

// Showcases the menu
void menu(){
    char press;
    int userChoice;
    int itemNum[100] = {1, 2};
    int itemPrice[100] = {100, 200};
    char itemNames[100][100] = {"test 1", "test 2"};

    // Prints the menu
    while(1){
        printf("Menu\n\n");
        for(int i = 0; i < 2; i++){
            printf("%d %s %dPHP\n", itemNum[i], itemNames[i], itemPrice[i]);
        }
        
        printf("Press any key to continue...\n\n");
        // Press any key to continue
        press = getch();
        // IIRC, the 0 key and the up arrow key produces an ASCII of 0, that's why we need to get that
        if(press || press == 0){
            // Calls upon the action function
            userChoice = action();
            // Reacts to what you did in the action function
            if(userChoice == 1){
                continue;
            }
            else if(userChoice == 2){
                takeOrder(itemNum, itemPrice, itemNames);
                break;
            }
            else if(userChoice == 3){
                break;
            }
        }
    }

}


// Main
int main(){
    printf("Restaurant Name\n\n");
    login();
    menu();
    printf("Thank you!");
    
    
    return 0;
}