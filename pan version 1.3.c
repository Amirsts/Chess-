#include <math.h>
#include <string.h>
#include <stdio.h>
//main funcion

int position(int i , int j);
int move(int i1 , int j1, int i2 , int j2);
void print_board();
int command ();
int checkTurn(int i1, int j1, int turn_player);
void DoMove(int i1 , int j1, int i2 , int j2);
void setCanMove();
int getCommand(char bug);

//function for pieces
void pan(int i1 , int j1, int i2 , int j2);
int knight(int i1 , int j1, int i2 , int j2);
int bishop(int i1 , int j1, int i2 , int j2);
int rook(int i1 , int j1, int i2 , int j2);
int queen(int i1 , int j1, int i2 , int j2);
int king(int i1 , int j1, int i2 , int j2);



//usefull fanction 
int convertJ(char j);
int convertI(char i);
int limit_motion(int i, int j);
int ConvertToInt(char j);
int Valid(char satr, int satrAdad);
//global variable and matrix
char cmd1[3], cmd2[3];
int turn_player = 1;                        //1 means white and 0 means black
/*
int location [8][8] = {
    {114, 110, 98, 113, 107, 98, 110, 114},
    {112, 112, 112, 112, 112, 112, 112, 112},
    {46, 46, 46, 46, 46, 46, 46, 46},
    {46, 46, 46, 46, 46, 46, 46, 46},
    {46, 46, 46, 46, 46, 46, 46, 46},
    {46, 46, 46, 46, 46, 46, 46, 46},
    {80, 80, 80, 80, 80, 80, 80, 80},
    {82, 78, 66, 81, 75, 66, 78, 82},
};
*/
int location[8][8];
char canMove[8][8];
int main(void) {
    printf(
        "please attention to my note first if you want to exit program please enter ex\nyou must enter first position as the piece and second position as the where piece will go like \"e6 e7\"\n please attend to my warning\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            canMove[i][j] = 0;
            if (i == 6) {
                location[i][j] = 80;
            }
            else if (i == 1) {
                location[i][j] = 112;
            }
            else {
                location[i][j] = 46;
            }
        }
    }
    command();
    return 0;
}

                                     /*===take a look===*/
                                  /*start the functions of main*/


int command () {
    do{
        print_board();
        if (turn_player)printf("Please enter the motion (white): \n");
        else printf("Please enter the position (black): \n");
        //char cmd1[3], cmd2[3];
        //scanf("%2s", cmd1);
        char exit = getCommand(0);
        //if (strcmp(cmd1, "ex")==0) break;
        if (exit || strcmp(cmd1,"ex")==0 ) break;
        //scanf("%2s", cmd2);
        while (Valid(cmd1[0], ConvertToInt(cmd1[1])) == 0 || Valid(cmd2[0], ConvertToInt(cmd2[1])) == 0) {
            getCommand(3);
            //printf("Sorry, your input is incorrect. Please enter again: \n");
            //scanf("%2s", cmd1);
            //scanf("%2s", cmd2);
        }
        while (checkTurn(convertI(ConvertToInt(cmd1[1])) , convertJ(cmd1[0]),turn_player)==0) {
            printf("state is %s ans %s and %d \n", cmd1, cmd2, turn_player);
            getCommand(4);
        }
        int i1 = convertI(ConvertToInt(cmd1[1]));
        int i2 = convertI(ConvertToInt(cmd2[1]));
        int j1 = convertJ(cmd1[0]);
        int j2 = convertJ(cmd2[0]);
        if (move(i1,j1, i2, j2)){
            turn_player++;
            turn_player = (turn_player == 2) ? 0 : 1 ;
            printf("now player is %d \n", turn_player);
        }
        //printf("now i1 is %d\nj1 is %d\ni2 is %d\nj2 is %d\n", i1, j1, i2, j2);
    }while (1);
    return 0;
}

int move(int i1 , int j1 ,int i2 , int j2) {
    int piece = location[i1][j1];
    switch (piece) {
        case 80:
            pan(i1,j1,i2,j2);
        if (canMove[i2][j2]) {
            DoMove(i1,j1,i2,j2);
            setCanMove();
            return 1;
        }
        else {
            getCommand(3);
            return 0;
        }
        break;
        case 112:
            pan(i1,j1,i2,j2);
        break;
        case 78:
            knight(i1,j1,i2,j2);
        break;
        case 110:
            knight(i1,j1,i2,j2);
        break;
        case 82:
            rook(i1,j1,i2,j2);
        break;
        case 114:
            rook(i1,j1,i2,j2);
        break;
        case 66:
            bishop(i1,j1,i2,j2);
        break;
        case 98:
            bishop(i1,j1,i2,j2);
        break;
        case 81:
            queen(i1,j1,i2,j2);
        break;
        case 113:
            queen(i1,j1,i2,j2);
        break;
        case 75:
            king(i1,j1,i2,j2);
        break;
        case 107:
            king(i1,j1,i2,j2);
        break;
        default:
            return 0;
    }
}
int position(int i , int j) {
    /*
    int location [8][8] = {
        {114, 110, 98, 113, 107, 98, 110, 114},
        {112, 112, 112, 112, 112, 112, 112, 112},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {80, 80, 80, 80, 80, 80, 80, 80},
        {82, 78, 66, 81, 75, 66, 78, 82},
    };
    */
    return location [i] [j];
}
void setCanMove() {
    int i = 0, j = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            canMove[i][j] = 0;
        }
    }
}
int getCommand(char bug) {
    switch (bug) {
        case 1:
            printf("Same position\n");
            break;
        case 2:
            printf("Wrong position\n");
            break;
        case 3:
            printf("Sorry, your input is incorrect. Please enter again: \n");
            break;
        case 4:
            printf("Chosing the wrong nut\n");
        default:
            break;
    }
    scanf("%2s", cmd1);
    if (strcmp(cmd1, "ex") == 0) return 1;
    scanf("%2s", cmd2);
    return 0;
}
void print_board() {
    int k=8;
    for (int i = 0; i < 8; i++) {
        printf("%d ", k--);
        for (int j = 0; j < 8; j++) {
            printf("%c ",location[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}
void DoMove(int i1 , int j1, int i2 , int j2) {
    location [i2][j2] = location[i1][j1];
    location [i1][j1] = 46;
}

int checkTurn(int i1 , int j1,int turn_player) {
    if (location[i1][j1] > 90 && turn_player == 0) {
        return 1;
    }
    else if (location[i1][j1] < 90 && turn_player == 1 && location[i1][j1]>46) {
        return 1;
    }
    else {
        return 0;
    }

}


                    /*---------------------------------------------------*/
                             /*----------attention----------*/
                         /*here is the edn of the main funcions*/
                  /*---------------------------------------------------*/


void pan(int i1 , int j1, int i2 , int j2) {
    if (turn_player) { //turn player 1 means piece white must move
        if (i1 == 6) {
            if (location [i1-2][j1] == 46 && location [i2-1][j1] == 46) {
                canMove[i1-1][j1] = 1;
                canMove[i1-2][j1] = 1;
            }
        }
        if (location [i1-1][j1] == 46 ) {
            canMove[i1-1][j1] = 1;
        }
        if (location [i1-1][j1-1] > 90) {
            canMove[i1-1][j1-1] = 1;
        }
        if (location [i1-1][j1+1] > 90 ) {
            canMove[i1-1][j1+1] = 1;
        }
    }
    else {
        if (i1 == 1) {
            if (location [i1+2][j1] == 46 && location [i2+1][j1] == 46) {
                canMove[i1+1][j1] = 1;
                canMove[i1+2][j1] = 1;
            }
        }
        if (location [i1+1][j1] == 46 ) {
            canMove[i1+1][j1] = 1;
        }
        if (location [i1+1][j1-1] < 90 ) {
            canMove[i1+1][j1-1] = 1;
        }
        if (location [i1+1][j1+1] > 90 ) {
            canMove[i1+1][j1+1] = 1;
        }
    }
}
int knight(int i1 , int j1, int i2 , int j2) {
    return position(i1,j1) + position(i2,j2);
}
int rook(int i1 , int j1, int i2 , int j2) {
    return position(i1,j1) + position(i2,j2);
}
int bishop(int i1 , int j1, int i2 , int j2) {
    return position(i1,j1) + position(i2,j2);
}
int queen(int i1 , int j1, int i2 , int j2) {
    return position(i1,j1) + position(i2,j2);
}
int king(int i1 , int j1, int i2 , int j2) {
    return position(i1,j1) + position(i2,j2);
}

                        /*---------------------------------------------------*/
                                    /*----------attention----------*/
                                /*here is the edn the functions of peaces*/
                        /*---------------------------------------------------*/




                                            /*===take a look===*/



int convertI(int a) {
    return 8-a;
}
void func() {
    printf("Hello World\n");
}
int ConvertToInt(char a) {
    switch (a) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8' :
            return 8;
        case '9':
            return 9;
        default:
            return -1;
    }
}
int convertJ(char a) {
    switch (a) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        default:
            return -1;
    }
}

int limit_motion(int i, int j) {
    if (i>= 0 && i <= 7 && j >= 0 && j <= 7) {
        return 1;
    }
    return 0;
}

int Valid(char satr, int satrAdad) {
    if (satr >= 'a' && satr <= 'h' && satrAdad >= 1 && satrAdad <= 8) {
        return 1;
        // Valid input
    }
    return 0;
    // Invalid input
}