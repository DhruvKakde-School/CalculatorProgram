// Imports
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


// Clear Screen Customise per Operating System
#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif


//Custom Functions

//Clear Screen
void clearScreen() {
    system(CLEAR_SCREEN);
}

//Program Pauser
void pauseProgram() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');  // Clear input buffer
    getchar();  // Wait for Enter
}


//Prime Checker
int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}


//Menu Printer
void printMenu() {
    printf("\n    1  : Addition\n");
    printf("    2  : Subtraction\n");
    printf("    3  : Multiplication\n");
    printf("    4  : Division\n");
    printf("    5  : Even or Odd\n");
    printf("    6  : Greater or Less Than\n");
    printf("    7  : Prime or Composite\n");
    printf("    8  : Factors of a Number\n");
    printf("    9  : Logarithm (Base 10)\n");
    printf("    10 : Natural Logarithm\n");
    printf("    11 : Square Root\n");
    printf("    12 : Raise to Power\n");
    printf("    13 : Print Fibonacci Sequence \n");
    printf("    14 : Quit\n");
}


//Main Loop
int main() {
    int choice;
    int num1, num2;
    double result;

    while (1) {
        clearScreen();
        printMenu();

        printf("\nSelect an operation: "); // Operation Selection
        scanf(" %d", &choice);


        switch (choice) {
            case 1: //Addition
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("Result: %d\n", num1 + num2);
                break;

            case 2: //Subtraction
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("Result: %d\n", num1 - num2);
                break;

            case 3: //Multiplication
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("Result: %d\n", num1 * num2);
                break;

            case 4: //Division
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    printf("Result: %.2lf\n", (double)num1 / num2);
                }
                break;

            case 5: //Even or Odd
                printf("Enter a number: ");
                scanf("%d", &num1);
                printf("The number is %s.\n", (num1 % 2 == 0) ? "Even" : "Odd");
                break;

            case 6: // Greater than or Lesser than
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                if (num1 > num2) {
                    printf("%d is greater.\n", num1);
                } else if (num1 < num2) {
                    printf("%d is greater.\n", num2);
                } else {
                    printf("Both numbers are equal.\n");
                }
                break;

            case 7: // Prime or Composite
                printf("Enter a number: ");
                scanf("%d", &num1);
                printf("%d is %s.\n", num1, isPrime(num1) ? "Prime" : "Composite");
                break;

            case 8: // Factors
                printf("Enter a number: ");
                scanf("%d", &num1);
                printf("Factors of %d: ", num1);
                for (int i = 1; i <= num1; i++) {
                    if (num1 % i == 0) {
                        printf("%d ", i);
                    }
                }
                printf("\n");
                break;

            case 9: // Logarithm
                printf("Enter a number: ");
                scanf("%d", &num1);
                if (num1 <= 0) {
                    printf("Error: Logarithm undefined for non-positive values.\n");
                } else {
                    printf("Log base 10 of %d is %.6lf\n", num1, log10(num1));
                }
                break;

            case 10: //Natural Logarithm
                printf("Enter a number: ");
                scanf("%d", &num1);
                if (num1 <= 0) {
                    printf("Error: Natural logarithm undefined for non-positive values.\n");
                } else {
                    printf("Natural log of %d is %.6lf\n", num1, log(num1));
                }
                break;

            case 11: // Square Root
                printf("Enter a number: ");
                scanf("%d", &num1);
                if (num1 < 0) {
                    printf("Error: Square root of negative numbers is undefined.\n");
                } else {
                    printf("Square root of %d is %.6lf\n", num1, sqrt(num1));
                }
                break;

            case 12: // Powers 
                printf("Enter a number and its power: ");
                scanf("%d %d", &num1, &num2);
                result = pow(num1, num2);
                printf("%d raised to the power of %d is %.6lf\n", num1, num2, result);
                break;

            case 13: //Fibonacci Series
                printf("Enter the number of terms: ");
                scanf("%d", &num1);
                int a = 0, b = 1, c;
                printf("Fibonacci Series until specified term:");
                for (int i = 1; i <= num1; i++) {
                    printf("\n %d ", a);
                    c = a + b;
                    a = b;
                    b = c;
                }
                printf("\n");
                break;

            case 14: // Exiter
                printf("Exiting...\n");
                exit(0);

            Default: // Incorrect Input
                printf("Invalid option! Please try again.\n");
        }

        pauseProgram(); // Pause the program before repeating.
    }

    return 0;
}
