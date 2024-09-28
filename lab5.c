/*
Name: Zaid Bulbul
Lab: Lab-5
Date: 9/27/2024


This program generates a random story from user input, and then will
repeat it as long as the user has not opted out from the game.
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Seeding
    srand(time(NULL));

    char choice[10];

    do {
        // El variables
        char name[50];
        int age;
        char age_input[10];
        char color[20];
        char fav_person[20];
        char fav_car[50];
        char enemy[50];
        char weapon[50];


        // The questions to start
        printf("What is your name? ");
        fgets(name, sizeof(name), stdin);
        // takes away the newline character from fgets
        name[strcspn(name, "\n")] = 0;

        printf("How old are you? ");
        fgets(age_input, sizeof(age_input), stdin);
        age = atoi(age_input);

        printf("What is your favorite color? ");
        fgets(color, sizeof(color), stdin);
        color[strcspn(color, "\n")] = 0;

        printf("Who is your favorite person? ");
        fgets(fav_person, sizeof(fav_person), stdin);
        fav_person[strcspn(fav_person, "\n")] = 0;
        
        printf("What is your favorite car? ");
        fgets(fav_car, sizeof(fav_car), stdin);
        fav_car[strcspn(fav_car, "\n")] = 0;
        
        printf("Who is your number one enemy? ");
        fgets(enemy, sizeof(enemy), stdin);
        enemy[strcspn(enemy, "\n")] = 0;
        
        printf("Weapon of (mass destruction) of choice? ");
        fgets(weapon, sizeof(weapon), stdin);
        weapon[strcspn(weapon, "\n")] = 0;

        // Different things for the story to choose from
        char *objects[] = {"laptop", "bicycle", "phone", "porsche", "nikon 360 shot camera"};
        int nobj = sizeof(objects) / sizeof(objects[0]);

        char *adjectives[] = {"god-awful", "crappy", "new", "quick", "spooky"};
        int nadj = sizeof(adjectives) / sizeof(adjectives[0]);

        char *places[] = {"in the park", "under a waterfall", "in the mountains", "in the city", "at home"};
        int nplace = sizeof(places) / sizeof(places[0]);
    


        // The illusion of choice
        char *midpoint[] = {
            "and then went on an adventure to go lift weights.",
            "and lived happily ever after. (Shredded)",
            "and decided to learn BODYBUILDING!!!!.",
            "and started a new hobby (which was bodybuilding)."
        };
        int num_midpoints = sizeof(midpoint) / sizeof(midpoint[0]);

        // Randomly select elements
        int obj_index = rand() % nobj;
        int adj_index = rand() % nadj;
        int place_index = rand() % nplace;
        int midpoint_index = rand() % num_midpoints;

        // Makes the story
        printf("\n%s is %d years old. They love their %s %s %s. One day, while %s with %s they did the dougie, %s\nHow were they going to get to the gym from here? Well, they'll hop into their %s of course!\nNext, when they got there, they saw %s using the bench they wanted, and so they blasted them with their %s and we all lived happily ever after.\nexcept %s, they deserve that.\n ",
               name, age, color, adjectives[adj_index], objects[obj_index],
               places[place_index], fav_person, midpoint[midpoint_index], fav_car, enemy, weapon, enemy);

        // Checks with the user if they want to repeat it 
        printf("\nWould you like to play again? (yep/no): ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = 0;

    } while (strcmp(choice, "yep") == 0);

    return 0;
}
