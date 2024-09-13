/*
Name: Zaid Bulbul
Lab #2
9/6/2024

This program allows you to input an ammount of currency, 
and then it outputs that in different currencies.

The way the table is formatted allows you to put any ammount,
and compare it to the rest. No need to specify 1 USD or 1 GBP

*/
 
#include <stdio.h>

int main() 
{
    // Exchange rates going from USD, GBP, CAD, EUR, AUD, SAR (SOURCE GOOGLE SEARCH BRUH....)
    // This is the grid we will use for the base of how we do our calculations
    // I added SAR because I used to live in saudi!
    double rates[6][6] = {
        {1.0, 0.547525, 1.0527, 0.680967, 1.16036, 3.75},     // USD
        {1.8264, 1.0, 1.92265, 1.24371, 2.11928, 6.84},       // GBP
        {0.949938, 0.520114, 1.0, 0.646876, 1.10227, 3.56},   // CAD
        {1.46849, 0.80404, 1.54588, 1.0, 1.70398, 5.61},      // EUR
        {0.861801, 0.471857, 0.907218, 0.586858, 1.0, 3.29},  // AUD
        {0.266667, 0.146199, 0.280899, 0.178003, 0.303953, 1.0} // SAR (Saudi Riyal)
    };

    // cName (Currency Name)
    char* cName[6] = {"USD", "GBP", "CAD", "EUR", "AUD", "SAR"};

    double amount;

    while (1) // Infinite loop for updating the amount continuously, I made a similar program in python and wanted to do the same here
    {
        // Input amount in any one currency
        printf("\nEnter the amount of currency (0 to exit): ");
        scanf("%lf", &amount);

        // Exit condition
        if (amount == 0) {
            break;
        }

        // Print table header 
        printf("      |  %-6s   %-6s   %-6s   %-6s   %-6s   %-6s\n", 
                cName[0], cName[1], cName[2], cName[3], cName[4], cName[5]);
        printf("------------------------------------------------------------------------\n");

        // USD
        printf("%-6s|  %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf\n",
            cName[0], amount * rates[0][0], amount * rates[0][1], 
            amount * rates[0][2], amount * rates[0][3], amount * rates[0][4], amount * rates[0][5]);

        // GBP
        printf("%-6s|  %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf\n",
            cName[1], amount * rates[1][0], amount * rates[1][1], 
            amount * rates[1][2], amount * rates[1][3], amount * rates[1][4], amount * rates[1][5]);

        // CAD
        printf("%-6s|  %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf\n",
            cName[2], amount * rates[2][0], amount * rates[2][1], 
            amount * rates[2][2], amount * rates[2][3], amount * rates[2][4], amount * rates[2][5]);

        // EUR
        printf("%-6s|  %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf\n",
            cName[3], amount * rates[3][0], amount * rates[3][1], 
            amount * rates[3][2], amount * rates[3][3], amount * rates[3][4], amount * rates[3][5]);

        // AUD
        printf("%-6s|  %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf\n",
            cName[4], amount * rates[4][0], amount * rates[4][1], 
            amount * rates[4][2], amount * rates[4][3], amount * rates[4][4], amount * rates[4][5]);

        // SAR
        printf("%-6s|  %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf   %-6.3lf\n",
            cName[5], amount * rates[5][0], amount * rates[5][1], 
            amount * rates[5][2], amount * rates[5][3], amount * rates[5][4], amount * rates[5][5]);

    }

    return 0;
}