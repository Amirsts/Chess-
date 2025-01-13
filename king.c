

void knig(int i1 , int j1, int i2 , int j2);  {


 if (turn_player) { 

        
        //upper third
        if ((location [i1-1][j1] == 46) || (location [i1-1][j1] > 90) ) {
            canMove[i1-1][j1] = 1;
        }
        if ((location[i1-1][j1+1] == 46) || (location [i1-1][j1+1] > 90) ) {
            canMove[i1-1][j1+1] = 1;
        }
        if ((location [i1-1][j1-1]== 46) || (location [i1-1][j1-1] > 90) ) {
            canMove[i1-1][j1-1] = 1;
        }

        //lelt and right
        if ((location [i1][j1+1] == 46) || (location [i1][j1+1] > 90) ) {
            canMove[i1][j1+1] = 1;
        }
         if ((location [i1][j1-1] == 46) || (location [i1][j1-1] > 90) ) {
            canMove[i1][j1-1] = 1;
        }

        //lower third
        if ((location [i1+1][j1] == 46) || (location [i1+1][j1] > 90) ) {
            canMove[i1+1][j1] = 1;
        }
        if ((location[i1+1][j1+1] == 46) || (location [i1+1][j1+1] > 90) ) {
            canMove[i1+1][j1+1] = 1;
        }
        if ((location [i1+1][j1-1]== 46) || (location [i1+1][j1-1] > 90) ) {
            canMove[i1+1][j1-1] = 1;
        }

        
    }
    else {

        //upper third
        if ((location [i1-1][j1] == 46) || (location [i1-1][j1] > 90) ) {
            canMove[i1-1][j1] = 1;
        }
        if ((location[i1-1][j1+1] == 46) || (location [i1-1][j1+1] > 90) ) {
            canMove[i1-1][j1+1] = 1;
        }
        if ((location [i1-1][j1-1]== 46) || (location [i1-1][j1-1] > 90) ) {
            canMove[i1-1][j1-1] = 1;
        }

        //lelt and right
        if ((location [i1][j1+1] == 46) || (location [i1][j1+1] > 90) ) {
            canMove[i1][j1+1] = 1;
        }
         if ((location [i1][j1-1] == 46) || (location [i1][j1-1] > 90) ) {
            canMove[i1][j1-1] = 1;
        }

        //lower third
        if ((location [i1+1][j1] == 46) || (location [i1+1][j1] > 90) ) {
            canMove[i1+1][j1] = 1;
        }
        if ((location[i1+1][j1+1] == 46) || (location [i1+1][j1+1] > 90) ) {
            canMove[i1+1][j1+1] = 1;
        }
        if ((location [i1+1][j1-1]== 46) || (location [i1+1][j1-1] > 90) ) {
            canMove[i1+1][j1-1] = 1;
        }
       
    }
}