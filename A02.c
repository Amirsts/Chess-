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
