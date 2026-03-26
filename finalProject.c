#include <stdio.h>
#include <string.h>
#include <conio.h>



void login(){
    char username[100];
    char password[100];
    char ch;
    int i;

    char user[] = "hello";
    char pass[] = "world";

    while (1) {
        i = 0;

        // --- USERNAME ---
        printf("Username: ");
        scanf("%s", username);

        // Consume leftover newline from scanf
        // while ((ch = getchar()) != '\n' && ch != EOF);

        // --- PASSWORD ---
        i = 0;
        printf("Password: ");
        while (1) {
            ch = getch();

            if (ch == 13) break; // Enter
            else if (ch == 8) {  // Backspace
                if (i > 0) {
                    i--;
                    printf("\b \b");
                }
            }
            else{
                password[i++] = ch;
                printf("*");
            }
        }
        password[i] = '\0';
        printf("\n");

        // --- VALIDATION ---
        if (strcmp(username, user) == 0 && strcmp(password, pass) == 0) {
            printf("Valid user\n");
            break;
        } else {
            printf("Invalid user\n\n");
        }
    }
}

int action(){
    int options;
    printf("Resutation options\n\n");

    printf("1 Back to Menu\n");
    printf("2 Take Order\n");
    printf("3 Exit\n\n");
    printf("Option: ");
    while(1){
        scanf("%d", &options);
        switch (options)
        {
        case 1:
            return 0;
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;   
        default:
            printf("Invalid Input\n");
        }
    }

    return 0;
}

void menu(){
    char press;
    while(1){
        printf("Menu\n\n");
        press = getch();
        if(press || press == 0){
            action();
        }
    }

}



int main(){
    printf("Restaurant Name\n\n");
    login();
    menu();
    
    
    return 0;
}