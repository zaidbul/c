/*
Name: Zaid Bulbul
Lab: Lab-6
Date: 10/04/2024

This progam will allow users to store, delete, and view contacts. It works by taking in the
details as an array and makes sure there are no two same entries, and the phone book
grows with each person added. You can also remove and check the phonebook. The program
releases the data once terminated.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char firstName[50];
    char lastName[50];
    char phoneNumber[20];
} Contact;

Contact* phonebk = NULL;
int phonebkSize = 0;       // The ammount of valid entries
int phonebkcap = 0;   // The capacity of the array

void addperson();
void deleteperson();
void showphonebk();
void intphonebk();

int main() {
    int choice;
    intphonebk();

    while (1) {
        printf("Phone Book Application\n");
        printf("1) Add person\n");
        printf("2) Delete person\n");
        printf("3) Show phone book\n");
        printf("What do you want to do: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // This will clear the input buffer

        switch (choice) {
            case 1:
                addperson();
                break;
            case 2:
                deleteperson();
                break;
            case 3:
                showphonebk();
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    // freeing allocated memory :thumbsup: :thumbsup: 
    if (phonebk != NULL) {
        free(phonebk);
    }
    return 0;
}

void intphonebk() {
    // default entry YOURS TRULY!
    phonebkcap = 1;
    phonebk = (Contact*)malloc(phonebkcap * sizeof(Contact));
    if (phonebk == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(phonebk[0].firstName, "Zaid");
    strcpy(phonebk[0].lastName, "Bulbul");
    strcpy(phonebk[0].phoneNumber, "443-712-XXXX");
    phonebkSize = 1;
}

void addperson() {
    Contact newentry;
    printf("First name: ");
    fgets(newentry.firstName, sizeof(newentry.firstName), stdin);
    newentry.firstName[strcspn(newentry.firstName, "\n")] = 0; // removes the first line

    printf("Last name: ");
    fgets(newentry.lastName, sizeof(newentry.lastName), stdin);
    newentry.lastName[strcspn(newentry.lastName, "\n")] = 0;

    printf("Phone number: ");
    fgets(newentry.phoneNumber, sizeof(newentry.phoneNumber), stdin);
    newentry.phoneNumber[strcspn(newentry.phoneNumber, "\n")] = 0;

    // this will verify to make sure the entry is unique
    for (int i = 0; i < phonebkSize; i++) {
        if (strcmp(phonebk[i].firstName, newentry.firstName) == 0 &&
            strcmp(phonebk[i].lastName, newentry.lastName) == 0) {
            printf("Contact with this name already exists\n");
            return;
        }
    }

    // checks capacity O_O 
    if (phonebkSize == phonebkcap) {
        phonebkcap = (phonebkcap == 0) ? 1 : phonebkcap * 2;
        Contact* temp = realloc(phonebk, phonebkcap * sizeof(Contact));
        if (temp == NULL) {
            printf("the world is broken\n");
            exit(1);
        }
        phonebk = temp;
    }

    // adds new contact
    phonebk[phonebkSize++] = newentry;

    printf("Record added! AWESOME!!\n");
}

void deleteperson() {
    char firstName[50];
    char lastName[50];
    printf("First name: ");
    fgets(firstName, sizeof(firstName), stdin);
    firstName[strcspn(firstName, "\n")] = 0;

    printf("Last name: ");
    fgets(lastName, sizeof(lastName), stdin);
    lastName[strcspn(lastName, "\n")] = 0;

    // this will find the contact
    int index = -1;
    for (int i = 0; i < phonebkSize; i++) {
        if (strcmp(phonebk[i].firstName, firstName) == 0 &&
            strcmp(phonebk[i].lastName, lastName) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Contact not found\n");
        return;
    }

    // removes the contact GOODBHYE!
    for (int i = index; i < phonebkSize - 1; i++) {
        phonebk[i] = phonebk[i + 1];
    }
    phonebkSize--;
    printf("Record deleted from the phone book\n");
}

void showphonebk() {
    printf("Phone Book Entries:\n");
    for (int i = 0; i < phonebkSize; i++) {
        printf("\n%s %s \n%s\n", phonebk[i].firstName, phonebk[i].lastName, phonebk[i].phoneNumber);
        printf("----------------\n");
    }
}
