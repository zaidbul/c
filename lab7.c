/*
Name: Zaid Bulbul
Lab: Lab-7
Date: 10/18/2024

This progam will allow users to store, delete, and view contacts. It works by taking in the
details as an array and makes sure there are no two same entries, and the phone book
grows with each person added. You can also remove and check the phonebook. The program
releases the data once terminated. Added functionality includes uhhhh SORTING! AND DELETING ! 
and finally it includes searching contact with just the name (as well as giving a random contact)
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char firstName[50];
    char lastName[50];
    char phonenum[20];
} Contact;

Contact* phonebk = NULL;
int phonebkSize = 0;
int phonebkcap = 0;

void addperson();
void deleteperson();
void showphonebk();
void intphonebk();
void sortphonebk();
void findphonenum();
void randFriend();
void deleteall();

int main() {
    int choice;
    intphonebk();
    srand(time(NULL)); // Initialize random number generator

    while (1) {
        printf("Phone Book Application\n");
        printf("1) Add person\n");
        printf("2) Delete person\n");
        printf("3) Show phone book\n");
        printf("4) Sort phone book\n");
        printf("5) Find phone number\n");
        printf("6) Call random friend\n");
        printf("7) Delete all contacts\n");
        printf("What do you want to do: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear input buffer

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
            case 4:
                sortphonebk();
                break;
            case 5:
                findphonenum();
                break;
            case 6:
                randFriend();
                break;
            case 7:
                deleteall();
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    if (phonebk != NULL) {
        free(phonebk);
    }
    return 0;
}
// keeping og copy inside as well as the phonebook
void intphonebk() {
    phonebkcap = 1;
    phonebk = (Contact*)malloc(phonebkcap * sizeof(Contact));
    if (phonebk == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(phonebk[0].firstName, "Zaid");
    strcpy(phonebk[0].lastName, "Bulbul");
    strcpy(phonebk[0].phonenum, "443-712-XXXX");
    phonebkSize = 1;
}
// adding a person
void addperson() {
    Contact newentry;
    printf("First name: ");
    fgets(newentry.firstName, sizeof(newentry.firstName), stdin);
    newentry.firstName[strcspn(newentry.firstName, "\n")] = 0;

    printf("Last name: ");
    fgets(newentry.lastName, sizeof(newentry.lastName), stdin);
    newentry.lastName[strcspn(newentry.lastName, "\n")] = 0;

    printf("Phone number: ");
    fgets(newentry.phonenum, sizeof(newentry.phonenum), stdin);
    newentry.phonenum[strcspn(newentry.phonenum, "\n")] = 0;

    for (int i = 0; i < phonebkSize; i++) {
        if (strcmp(phonebk[i].firstName, newentry.firstName) == 0 &&
            strcmp(phonebk[i].lastName, newentry.lastName) == 0) {
            printf("Contact with this name already exists :(\n");
            return;
        }
    }

    if (phonebkSize == phonebkcap) {
        phonebkcap = (phonebkcap == 0) ? 1 : phonebkcap * 2;
        Contact* temp = realloc(phonebk, phonebkcap * sizeof(Contact));
        if (temp == NULL) {
            printf("the world is broken\n");
            exit(1);
        }
        phonebk = temp;
    }

    phonebk[phonebkSize++] = newentry;
    printf("Record added! AWESOME!!\n");
}
// function to delete person
void deleteperson() {
    char firstName[50];
    char lastName[50];
    printf("First name: ");
    fgets(firstName, sizeof(firstName), stdin);
    firstName[strcspn(firstName, "\n")] = 0;

    printf("Last name: ");
    fgets(lastName, sizeof(lastName), stdin);
    lastName[strcspn(lastName, "\n")] = 0;

    int index = -1;
    for (int i = 0; i < phonebkSize; i++) {
        if (strcmp(phonebk[i].firstName, firstName) == 0 &&
            strcmp(phonebk[i].lastName, lastName) == 0) {
            index = i;
            break;
        }
    }
    // if we cant find
    if (index == -1) {
        printf("Contact not found\n");
        return;
    }

    for (int i = index; i < phonebkSize - 1; i++) {
        phonebk[i] = phonebk[i + 1];
    }
    phonebkSize--;
    printf("Record deleted from the phone book\n");
}
// printing phone book
void showphonebk() {
    printf("Phone Book Entries:\n");
    for (int i = 0; i < phonebkSize; i++) {
        printf("\n%s %s \n%s\n", phonebk[i].firstName, phonebk[i].lastName, phonebk[i].phonenum);
        printf("----------------\n");
    }
}

// sorting the phone book (yay!)

void sortphonebk() {
    for (int i = 0; i < phonebkSize - 1; i++) {
        for (int j = i + 1; j < phonebkSize; j++) {
            if (strcmp(phonebk[i].lastName, phonebk[j].lastName) > 0) {
                Contact temp = phonebk[i];
                phonebk[i] = phonebk[j];
                phonebk[j] = temp;
            }
        }
    }
    printf("Phone book sorted by last name.\n");
}
// finding phone number via contact name
void findphonenum() {
    char firstName[50], lastName[50];
    fgets(firstName, sizeof(firstName), stdin);
    firstName[strcspn(firstName, "\n")] = 0;

    printf("Enter last name: ");
    fgets(lastName, sizeof(lastName), stdin);
    lastName[strcspn(lastName, "\n")] = 0;

    for (int i = 0; i < phonebkSize; i++) {
        if (strcmp(phonebk[i].firstName, firstName) == 0 &&
            strcmp(phonebk[i].lastName, lastName) == 0) {
            printf("Phone number: %s\n", phonebk[i].phonenum);
            return;
        }
    }
    printf("Contact not found.\n");
}
// outputs random contact from list
void randFriend() {
    if (phonebkSize == 0) {
        printf("No contacts available.\n");
        return;
    }
    int randomIndex = rand() % phonebkSize;
    printf("Call your friend: %s %s - %s\n", phonebk[randomIndex].firstName, phonebk[randomIndex].lastName, phonebk[randomIndex].phonenum);
}
// empties it
void deleteall() {
    phonebkSize = 0;
    printf("All contacts have been deleted.\n");
}

