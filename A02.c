#include <stdio.h>
#include <ctype.h>


int Valid(char satr, int satrAdad) {
    if (satr >= 'a' && satr <= 'h' && satrAdad >= 1 && satrAdad <= 8) {
        return 1; // Valid input
    }
    return 0; // Invalid input
}

// Function to get valid 
void GetValidMove() {
    char satrShoru, satrMaqsad;
    int shomareShoru, shomareMaqsad;

    while (1) {
        printf("Please enter the starting square (e.g., a1): ");
        scanf(" %c%d", &satrShoru, &shomareShoru);
        satrShoru = tolower(satrShoru);

        printf("Please enter the destination square (e.g., b2): ");
        scanf(" %c%d", &satrMaqsad, &shomareMaqsad);
        satrMaqsad = tolower(satrMaqsad); 

        if (Valid(satrShoru, shomareShoru) && Valid(satrMaqsad, shomareMaqsad)) {
            printf("Valid input: %c%d to %c%d\n", satrShoru, shomareShoru, satrMaqsad, shomareMaqsad);
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("Move registered from %c%d to %c%d.\n", satrShoru, shomareShoru, satrMaqsad, shomareMaqsad);
}

int main() {
    GetValidMove();

    return 0;
}
