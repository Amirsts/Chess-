

void king(int i1 , int j1, int i2 , int j2);


 if (turn_player) { //turn player 1 means piece white must move

        
        //right half
        if (location [i1-2][j1+1] == 46 || location [i1-2][j1+1] > 90 ) {
            canMove[i1-2][j1+1] = 1;
        }
        if (location [i1+2][j1+1] == 46 || location [i1+2][j1+1] > 90 ) {
            canMove[i1+2][j1+1] = 1;
        }
        if (location [i1-1][j1+2] == 46 || location [i1-1][j1+2] > 90 ) {
            canMove[i1-1][j1+2] = 1;
        }
        if (location [i1+1][j1+2] == 46 || location [i1+1][j1+2] > 90 ) {
            canMove[i1+1][j1+2] = 1;
        }


        //left half
        if (location [i1-2][j1-1] == 46 || location [i1-2][j1-1] > 90 ) {
            canMove[i1-2][j1-1] = 1;
        }
        if (location [i1+2][j1-1] == 46 || location [i1+2][j1-1] > 90 ) {
            canMove[i1+2][j1-1] = 1;
        }
        if (location [i1-1][j1-2] == 46 || location [i1-1][j1-2] > 90 ) {
            canMove[i1-1][j1-2] = 1;
        }
        if (location [i1+1][j1-2] == 46 || location [i1+1][j1-2] > 90 ) {
            canMove[i1+1][j1-2] = 1;
        }


        
    }
    else {

         //right half
        if (location [i1-2][j1+1] == 46 || location [i1-2][j1+1] < 90 ) {
            canMove[i1-2][j1+1] = 1;
        }
        if (location [i1+2][j1+1] == 46 || location [i1+2][j1+1] < 90 ) {
            canMove[i1+2][j1+1] = 1;
        }
        if (location [i1-1][j1+2] == 46 || location [i1-1][j1+2] < 90 ) {
            canMove[i1-1][j1+2] = 1;
        }
        if (location [i1+1][j1+2] == 46 || location [i1+1][j1+2] < 90 ) {
            canMove[i1+1][j1+2] = 1;
        }


        //left half
        if (location [i1-2][j1-1] == 46 || location [i1-2][j1-1] < 90 ) {
            canMove[i1-2][j1-1] = 1;
        }
        if (location [i1+2][j1-1] == 46 || location [i1+2][j1-1] < 90 ) {
            canMove[i1+2][j1-1] = 1;
        }
        if (location [i1-1][j1-2] == 46 || location [i1-1][j1-2] < 90 ) {
            canMove[i1-1][j1-2] = 1;
        }
        if (location [i1+1][j1-2] == 46 || location [i1+1][j1-2] < 90 ) {
            canMove[i1+1][j1-2] = 1;
        }
       
    }
