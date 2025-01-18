#include <math.h>
#include <string.h>
#include <stdio.h>
//main funcion


int move(int i1 , int j1, int i2 , int j2);
void print_board();
int command ();
int checkTurn(int i1, int j1, int turn_player);
void DoMove(int i1 , int j1, int i2 , int j2);
void setCanMove();
int getCommand(char notation,char justNote);

//function for pieces
int Pawn(int i1 , int j1, int i2 , int j2);
int Knight(int i1 , int j1, int i2 , int j2);
int Bishop(int i1 , int j1, int i2 , int j2);
int Rook(int i1 , int j1, int i2 , int j2);
int Queen(int i1 , int j1, int i2 , int j2);
int King(int i1 , int j1, int i2 , int j2);
int canTakePiece(int i2 , int j2);



//usefull fanction
void print_key();
void DoItration(int i1 , int j1, int d1, int d2);
int Region(int i1, int j1, int i2, int j2);
int convertJ(char j);
int convertI(char i);
int limit_motion(int i, int j);
int ConvertToInt(char j);
int Valid(char satr, int satrAdad);
//global variable and matrix
typedef struct{
    int update;
    int check;
    int ckeckmate;
    int casteling;
    int casteling2;
    int unpos;
    int i1;
    int j1;
    int i2;
    int j2;
}SpecialMove;
SpecialMove SM;                             //SM standfor Special move
char cmd1[3], cmd2[3];
int turn_player = 1;                        //1 means white and 0 means black

int location [8][8] = {
  {66, 46, 46, 78, 46, 46, 46, 66},
    {46, 112, 46, 46, 46, 46, 46, 46},
    {46, 46, 112, 46, 46, 46, 46, 46},
    {46, 46, 46, 107, 80, 46, 46, 46},
    {46, 46, 46, 46, 82, 46, 46, 46},
    {46, 46, 46, 46, 46, 46, 46, 46},
    {46, 46, 46, 46, 46, 46, 46, 46},
    {81, 46, 46, 46, 46, 46, 46, 46}, //81 is queen 113
};


int canMove[8][8] ={
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
};
int main(void) {
    SM.update = 0;
    SM.check = 0;
    SM.ckeckmate = 0;
    SM.casteling = 0;
    SM.casteling2 = 0;
    SM.unpos = 0;
    SM.i1 = 0;
    SM.j1 = 0;
    SM.i2 = 0;
    SM.j2 = 0;
    printf(
        "please attention to my note first if you want to exit program please enter ex\nyou must enter first position as the piece and second position as the where piece will go like \"e6 e7\"\n please attend to my warning\n");
    setCanMove();
    command();
    return 0;
}

                                     /*===take a look===*/
                                  /*start the functions of main*/


int command () {
    do{
        if ( SM.update ) {
            SM.update = 0;
            getCommand (6,1);
            int update;
            scanf("%d", &update);
            while (update <0 && update > 5) {
                printf("Please enter a number again . please enter correct number between 1 to 4\n");
                scanf("%d", update);
            }
            if (turn_player) {
                switch (update) {
                    case 1:
                        location [SM.i2][SM.j2] = 113;
                        break;
                    case 2:
                        location [SM.i2][SM.j2] = 113;
                        break;
                    case 3:
                        location [SM.i2][SM.j2] = 110;
                        break;
                    case 4:
                        location [SM.i2][SM.j2] = 98;
                        break;
                }
            }
            else {
                switch (update) {
                    case 1:
                        location [SM.i2][SM.j2] = 81;
                    break;
                    case 2:
                        location [SM.i2][SM.j2] = 82;
                    break;
                    case 3:
                        location [SM.i2][SM.j2] = 66;
                    break;
                    case 4:
                        location [SM.i2][SM.j2] = 78;
                    break;
                }
            }
        }
        print_board();
        if (turn_player)printf("Please enter the motion (white): \n");
        else printf("Please enter the position (black): \n");
        char exit = getCommand(0,0);
        if (exit || strcmp(cmd1,"ex")==0 ) break;
        while (Valid(cmd1[0], ConvertToInt(cmd1[1])) == 0 || Valid(cmd2[0], ConvertToInt(cmd2[1])) == 0) {
            getCommand(4,0);
        }
        while (checkTurn(convertI(ConvertToInt(cmd1[1])) , convertJ(cmd1[0]),turn_player)==0) {
            printf("state is %s ans %s and %d \n", cmd1, cmd2, turn_player);
            getCommand(4,0);
        }
        int i1 = convertI(ConvertToInt(cmd1[1]));
        int i2 = convertI(ConvertToInt(cmd2[1]));
        int j1 = convertJ(cmd1[0]);
        int j2 = convertJ(cmd2[0]);
    //    move(i1,j1, i2, j2);
        if (move(i1,j1, i2, j2)){
          turn_player++;
            turn_player = (turn_player == 2) ? 0 : 1 ;
            printf("now player is %d \n", turn_player);
        }
    }while (1);
    return 0;
}

int move(int i1 , int j1 ,int i2 , int j2) {
    /*
     * this function manage move and call the correspond function .move return one number as the it motion is acomplish
     * or not 1 as the it correct and 0 as the not correct
     */
    int piece = location[i1][j1];
    switch (piece) {
        case 80:
            Pawn(i1,j1,i2,j2);
            if (canMove[i2][j2]) {
                DoMove(i1,j1,i2,j2);
                setCanMove();
                return 1;
            }
            else {
                getCommand(5,1);
                setCanMove();
                return 0;
            }
        case 112:
            Pawn(i1,j1,i2,j2);
            if (canMove[i2][j2]) {
                DoMove(i1,j1,i2,j2);
                setCanMove();
                return 1;
            }
            else {
                getCommand(5,1);
                setCanMove();
                return 0;
            }
        case 78:
            Knight(i1,j1,i2,j2);
            if (canMove[i2][j2]) {
                DoMove(i1,j1,i2,j2);
                setCanMove();
                return 1;
            }
            else {
                getCommand(5,1);
                setCanMove();
                return 0;
            }
        case 110:
            Knight(i1,j1,i2,j2);
            if (canMove[i2][j2]) {
                DoMove(i1,j1,i2,j2);
                setCanMove();
                return 1;
            }
            else {
                getCommand(5,1);
                setCanMove();
                return 0;
            }
        case 82:
            Rook(i1,j1,i2,j2);
            if (canMove[i2][j2]) {
                DoMove(i1,j1,i2,j2);
                setCanMove();
                return 1;
            }
            else {
                getCommand(5,1);
                setCanMove();
                return 0;
            }
        case 114:
            Rook(i1,j1,i2,j2);
            if (canMove[i2][j2]) {
                DoMove(i1,j1,i2,j2);
                setCanMove();
                return 1;
            }
            else {
                getCommand(5,1);
                setCanMove();
                return 0;
            }
        case 66:
            Bishop(i1,j1,i2,j2);
            if (canMove[i2][j2]) {
                DoMove(i1,j1,i2,j2);
                setCanMove();
                return 1;
            }
            else {
                getCommand(5,1);
                setCanMove();
                return 0;
            }
        case 98:
            Bishop(i1,j1,i2,j2);
            if (canMove[i2][j2]) {
                DoMove(i1,j1,i2,j2);
                setCanMove();
                return 1;
            }
            else {
                getCommand(5,1);
                setCanMove();
                return 0;
            }
        case 81:
            Queen(i1,j1,i2,j2);
            if (canMove[i2][j2]) {
                DoMove(i1,j1,i2,j2);
                setCanMove();
                return 1;
            }
            else {
                getCommand(5,1);
                setCanMove();
                return 0;
            }
        case 113:
            Queen(i1,j1,i2,j2);
            if (canMove[i2][j2]) {
                DoMove(i1,j1,i2,j2);
                setCanMove();
                return 1;
            }
            else {
                getCommand(5,1);
                print_key();
                setCanMove();
                return 0;
            }
        case 75:
            King(i1,j1,i2,j2);
            if (canMove[i2][j2]) {
                DoMove(i1,j1,i2,j2);
                setCanMove();
                return 1;
            }
            else {
                getCommand(5,1);
                setCanMove();
                return 0;
            }
        case 107:
            King(i1,j1,i2,j2);
            if (canMove[i2][j2]) {
                DoMove(i1,j1,i2,j2);
                setCanMove();
                return 1;
            }
            else {
                getCommand(5,1);
                setCanMove();
                return 0;
            }
        default:
            return 0;
    }
}


void setCanMove() {
    int i = 0, j = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            canMove[i][j] = 0;
        }
    }
}


int getCommand(char notation ,char justNote) {
    switch (notation) {
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
            break;
        case 5:
            printf("nut can not go there\n");
            break;
        case 6:
            printf("your pan can updated please enter a number :\n1.Queen.\n2.Rood\n3.bishop\n4.knight\n");
            break;
        default:
            break;
    }
    if (justNote == 0) {
        scanf("%2s", cmd1);
        if (strcmp(cmd1, "ex") == 0) return 1;
        scanf("%2s", cmd2);
    }
    return 0;
}


void print_board() {
    int k=8;
    for (int i = 0; i < 8; i++) {
        printf("%d ", k--);
        for (int j = 0; j < 8; j++) {
   //        printf("%c ",location[i][j]);
   switch (location[i][j]) {
                case 112:  printf("♙ "); break;
                case 110:  printf("♘ "); break;
                case 98:  printf("♗ "); break;
                case 114:  printf("♖ "); break;
                case 113:  printf("♕ "); break;
                case 107:  printf("♔ "); break;
                case 80:  printf("♟ "); break;
                case 78: printf("♞ "); break;
                case 66:  printf("♝ "); break;
                case 82: printf("♜ "); break;
                case 81: printf("♛ "); break;
                case 75: printf("♚ "); break;
                default:  printf(". ");
            }
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


int Pawn(int i1 , int j1, int i2 , int j2) {
    int d = 0 ;
    int first = 0;
    int update_stage=0;
    if (turn_player) {
        // can take return 1 as the determinate raito value for white piece
        d = -1;
        first = 6;
        update_stage = 0;
    }
    else {
        d = 1;
        first = 1;
        update_stage = 7;
    }
    if (location [i1+d][j1] == 46 ) {
        canMove[i1+d][j1] = 1;
    }
    if (i1 == first && location [i1+ d*2][j1] == 46 && canMove[i1 + d][j1]) {
        canMove[i1 + d*2][j1] = 1;
    }
    if (canTakePiece(i2,j2)) {
        canMove[i1 +d ][j1+d] = 1;
    }
    if (canTakePiece(i2,j2)) {
        canMove[i1+d][j1-d] = 1;
    }
    if (i2 == update_stage && canMove[i2][j2]) {
        SM.update=1;
        SM.i2=i2;
        SM.j2=j2;
    }
}

int Knight(int i1 , int j1, int i2 , int j2) {
    int delta_i = i2 - i1;
    int delta_j = j2 - j1;
    if (((delta_i == 2 || delta_i== -2) && (delta_j == 1 || delta_j== -1)) || ((delta_i == 1 || delta_i== -1) && (delta_j == 2 || delta_j== -2)) && (canTakePiece(i2,j2) || location [i2][j2])) {
        canMove[i2][j2] = 1;
    }
}

int Bishop(int i1 , int j1, int i2 , int j2) {
    int d1,d2;
    int region = Region(i1,j1,i2,j2);
    switch (region) {
        case 1:
            d1 = 1;
            d2 = 1;
            break;
        case 2:
            d1 = 1;
            d2 = -1;
            break;
        case 3:
            d1 = -1;
            d2 = -1;
            break;
        case 4:
            d1 = -1;
            d2 = 1;
            break;
    }
    DoItration(i1,j1,d1,d2);
    return 0;
}

int Rook(int i1 , int j1, int i2 , int j2) {
    int d1,d2;
    int region = Region(i1,j1,i2,j2);
    switch (region) {
        case 1:
            d1 = 1;
            d2 = 0;
            break;
        case 2:
            d1 = 0;
            d2 = -1;
            break;
        case 3:
            d1 = -1;
            d2 = 0;
            break;
        case 4:
            d1 = 0;
            d2 = 1;
            break;
    }
    DoItration(i1,j1,d1,d2);
    return 0;
}

int Queen(int i1 , int j1, int i2 , int j2) {
    Rook(i1,j1,i2,j2);
    Bishop(i1,j1,i2,j2);
    return 0;
}

int King(int i1 , int j1, int i2 , int j2) {
    int di = i2 - i1;
    int dj = j2 - j1;
    if ((abs(di) > 0 || abs(dj) > 0) && (abs(di) < 2 && abs(dj) < 2 ) && (canTakePiece(i2 ,j2) || location [i2][j2]==46)) {
        canMove[i2][j2] = 1;
    }
}

int canTakePiece(int i2 , int j2) {
    /*
     * this funcion perform deteminater raito value in pan and use it for determinate other funcion
     * thet we dont repeat it
     */
    if (turn_player && location [i2][j2] > 90) {
        return 1;
    }
    else if (turn_player==0 && location [i2][j2] < 90 ) {
        return 1;
    }
    else {
        return 0;
    }
}

                        /*---------------------------------------------------*/
                                    /*----------attention----------*/
                                /*here is the edn the functions of peaces*/
                        /*---------------------------------------------------*/




                                            /*===take a look===*/

void print_key(){
    int i = 0, j = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%d ",canMove[i][j]);
        }
        printf("\n");
    }
}

void DoItration(int i1 , int j1, int d1, int d2) {
    /*
     * this function performs check the repetitive movement of bishop rook and queen
    */
    int c = 1; //c standfor coeffience in my code here
    while (c < 8) {
        int new_i = i1 + c * d1;
        int new_j = j1 + c * d2;
        if (new_i >= 8 || new_i < 0 || new_j >= 8 || new_j < 0) break;
        if (location[new_i][new_j] == 46) {
            canMove[new_i][new_j] = 1;
        } else {
            if ((location[new_i][new_j] > 90 && turn_player == 1) ||
                (location[new_i][new_j] < 90 && turn_player == 0)) {
                canMove[new_i][new_j] = 1;
                }
            break;
        }

        c++;
    }
}
int convertI(char a) {
    return 8-a;
}
int Region(int i1, int j1, int i2, int j2) {
    /*
     I specify in the region function if the zero coordinate
     of the coordinates is considered then we decide to move on
     */
    int delta_i = i2 - i1;
    int delta_j = j2 - j1;
    if (delta_i > 0 && delta_j >= 0) {
        return 1;   // region 1 and so on
    }
    else if (delta_i >= 0 && delta_j < 0) {
        return 2;
    }
    else if (delta_i < 0 && delta_j <= 0) {
        return 3;
    }
    else if (delta_i <= 0 && delta_j > 0) {
        return 4;
    }
    else return 0;
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
