/*
NAME: Zaid Bulbul
DATE: 9/13/2024
LAB: Lab 3

This program is a simple calculator made in C, it works by using a switch case
to determine what part of the code to execute. 


*/




#include <stdio.h>

int main() {
    int mode; // Our first value that will check for what mode is picked
    do {
        // This prints the menu 
        printf("\nCalculator Menu:\n");
        printf("(1) Addition\n");
        printf("(2) Subtraction\n");
        printf("(3) Multiplication\n");
        printf("(4) Division\n");
        printf("(5) Modulus (integers only)\n");
        printf("(6) Test if prime (integers only)\n");
        printf("(7) Exit\n");
        printf("Please choose an operation: ");
        // Checks what the user has as input
        scanf("%d", &mode);
        // Using switch instead of for loop because we have specific use cases.
        switch (mode) {
            case 1: {
                // Addition
                double a, b;
                printf("First number: ");
                scanf("%lf", &a);
                printf("Second number: ");
                scanf("%lf", &b);
                printf("\n%.lf + %.lf = %.lf\n", a, b, a + b);
                break;
            }

            case 2: {
                // Subtraction
                double a, b;
                printf("First number: ");
                scanf("%lf", &a);
                printf("Second number: ");
                scanf("%lf", &b);
                printf("\n%.lf - %.lf = %.lf\n", a, b, a - b);
                break;
            }

            case 3: {
                // Multiplication
                double a, b;
                printf("First number: ");
                scanf("%lf", &a);
                printf("Second number: ");
                scanf("%lf", &b);
                printf("\n%.lf x %.lf = %.lf\n", a, b, a * b);
                break;
            }

            case 4: {
                // Division
                double a, b;
                printf("First number: ");
                scanf("%lf", &a);
                printf("Second number: ");
                scanf("%lf", &b);
                if (b == 0) {
                    printf("\nDivision by 0 is not allowed.\n");
                } else {
                    printf("\n%.lf / %.lf = %.lf\n", a, b, a / b);
                }
                break;
            }

            case 5: {
                // Modulus, used int instead of double to hold value
                int a, b;
                printf("First number: ");
                scanf("%d", &a);
                printf("Second number: ");
                scanf("%d", &b);
                if (b == 0) {
                    printf("\nDivision by 0 is not allowed.\n");
                } else {
                    printf("\n%d %% %d = %d\n", a, b, a % b);
                }
                break;
            }
			// case 6 was difficult, sources used was stack overflow to figure out logic behind it
            case 6: {
                // Testing if prime
                int a, i; // a is the variable, i for loop
                printf("Enter the number to be tested: ");
                scanf("%d", &a);
                // Less than or equal to 1 is not prime, rule out case for efficency
                if (a <= 1) {
                    printf("Not prime: %d is not greater than 1.\n", a);
                    break;
                }
                int isPrime = 1; // Makes the assumption a number is prime
                for (i = 2; i <= a / 2; i++) {
                    if (a % i == 0) {
                        // Found a divisor
                        int factor1 = i;
                        int factor2 = a / i;
                        printf("\nNot prime: %d x %d = %d\n", factor1, factor2, a);
                        isPrime = 0;
                        break;
                    }
                }
                if (isPrime) {
                    // Number is prime
                    printf("\n%d is a prime number.\n", a);
                }
                break;
            }

            case 7:
                // Leaves the code
                printf("\nGood Bye!\n");
                break;

            default:
                // This is for when wrong input is given
                printf("\nOption not valid, try again\n");
        }

    } while (mode != 7); // If they choose 7, it closes the code

    return 0;
}