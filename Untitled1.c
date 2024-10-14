#include <stdio.h>

int main() {
    float radius, height, volume;
    const float pi = 3.14;

    do {
        printf("Enter your radius: ");
        scanf("%f", &radius);
        if (radius <= 0) {
            printf("Invalid input.\n");
        }
    } while (radius <= 0); 

    do {
        printf("Enter your height:");
        scanf("%f", &height);
        if (height <= 0) {
            printf("Invalid input.\n");
        }
    } while (height <= 0);  

    volume = pi * radius * radius * height;
    printf("The volume of the cylinder is: %.2f\n", volume);

    return 0;
}