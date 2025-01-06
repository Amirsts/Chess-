int pan(int i1 , int j1, int i2 , int j2) { 
             //white pawn move 
    if (turn_player == 1) {  
            if (i2 == i1 - 1 && j2 == j1 && location[i2][j2] == 46) { 
            return 1; 
        } 


            if (i2 == i1 - 1 && (j2 == j1 - 1 || j2 == j1 + 1) && location[i2][j2] != 46 && location[i2][j2] >= 97 && location[i2][j2] <= 122) { 
            return 1; 
        } 
             if (i1 == 6 && i2 == i1 - 2 && j2 == j1 && location[i2][j2] == 46 && location[i1 - 1][j1] == 46) { 
            return 1; 
        } 


        
    } else { 
               // black pawn move 
             if (i2 == i1 + 1 && j2 == j1 && location[i2][j2] == 46) { 
            return 1; 
        } 
             if (i2 == i1 + 1 && (j2 == j1 - 1 || j2 == j1 + 1) && location[i2][j2] != 46 && location[i2][j2] >= 65 && location[i2][j2] <= 90) { 
            return 1; 
        } 
             if (i1 == 1 && i2 == i1 + 2 && j2 == j1 && location[i2][j2] == 46 && location[i1 + 1][j1] == 46) { 
            return 1; 
        } 
    } 
    return 0; 
}
