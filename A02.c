#include <stdio.h>
#include <ctype.h>

int Valid(char satr, int satrAdad) {
    if (satr >= 'a' && satr <= 'h' && satrAdad >= 1 && satrAdad <= 8) {
        return 1; 
         // Valid input
    }
    return 0;  
         // Invalid input
}

int main() {
    char satrShoru, satrMaqsad;
    int shomareShoru, shomareMaqsad;

    while (1) {
        printf("Please enter the starting square (e.g., a1): ");
        scanf(" %c%d", &satrShoru, &shomareShoru);
        satrShoru = tolower(satrShoru);  
        
        // Convert to lowercase

        printf("Please enter the destination  (e.g., b2): ");
        scanf(" %c%d", &satrMaqsad, &shomareMaqsad);
        satrMaqsad = tolower(satrMaqsad);  
        
        // Convert to lowercase

        if (Valid(satrShoru, shomareShoru) && Valid(satrMaqsad, shomareMaqsad)) {
            printf("Valid input: %c%d to %c%d\n", satrShoru, shomareShoru, satrMaqsad, shomareMaqsad);
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}
