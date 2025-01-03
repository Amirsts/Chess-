#include <math.h>
#include <stdio.h>
int position(int i , int j);
int pan(int i1 , int j1, int i2 , int j2);
int knight(int i1 , int j1, int i2 , int j2);
int move(int i1 , int j1, int i2 , int j2);
int bishop(int i1 , int j1, int i2 , int j2);
int rook(int i1 , int j1, int i2 , int j2);
int queen(int i1 , int j1, int i2 , int j2);
int King(int i1 , int j1, int i2 , int j2);
void print_board();
int convertJ(char j);
int convertI(char i);
int is_valid(int value , int state);
int command ();
int ConvertToInt(char j);
int main(void) {
    print_board();
    command();

    return 0;
}
int command () {
    char cmd1 [2];
    char cmd2 [2];
    scanf("%s", cmd1);
    scanf("%s", cmd2);

    int j1 = convertJ(cmd1[0]);
    int j2 = convertJ(cmd2[0]);
    int i1 = convertI(cmd1[1]);
    int i2 = convertI(cmd2[1]);

}
int position(int i , int j) {
    /*
    int location [8][8] = {
        {82, 78, 66, 81, 75, 66, 78, 82},
        {80, 80, 80, 80, 80, 80, 80, 80},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {112, 112, 112, 112, 112, 112, 112, 112},
        {114, 110, 98, 113, 107, 98, 110, 114}
    };
    */
    int location [8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            location[i][j] = 46;
        }
    }
    location[1][3] = 80;
    return location [i] [j];
}
void print_board() {
    for (int i = 7; i >= 0; i--) {
        printf("%d ", i+1);
        for (int j = 0; j < 8; j++) {
            printf("%c ",position(i,j));
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}
int move(int i1 , int j1 ,int i2 , int j2) {
    int piece = position(i1,j1);
    switch (piece) {
        case 80:
            pan(i1,j1,i2,j2);

    }
    if (piece == 46) {
        return -1; //-1 means it position not have any piece
    }

}
int pan(int i , int j, int i2 , int j2) {
    int motivate [4] = { 0, 0, 0 ,0}; //first digit is true if could move left. second is can move forward so on. last is for convert
    if (position(i,j) == 112) {
        if (position(i-1,j) == 46) {
            motivate[1] = 1;
        }
        if (i < 7 && j < 7 || i > 0 && j > 0) {
            if (position(i-1,j-1) != 46 || position(i+1,j+1) != 46) {
                motivate[0] = 1;
                motivate[2] = 1;
            }
            else if (position(i-1,j-1) != 46) {
                motivate[0] = 1;
            }
            else if (position(i+1,j+1) != 46) {
                motivate[2] = 1;
            }
        }
        else if (j==0 || j==7) {
            if (position(i+1,j+1) != 46 && j==0) {
                motivate[2] = 1;
            }
            else if (position(i-1,j-1) != 46) {
                motivate[0] = 1;
            }
        }
        else if (i == 0) {
            printf("you can select one piece of piece below  \n1.Queen\n2.Rook\n3.Bishop\n4.Knight\nselect with number:");
            scanf("%d",motivate[3]);
            while (motivate[3] >= 5 && motivate[3] <= 0) {

            }
        }
    }
    else {

    }
}
int convertJ(char j) {
    switch (j) {
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
int convertI(int i) {
    return 8-convertJ(i);
}

int is_valid(int value , int state) {
    if (state == 1) {
        if (value <= 8 && value >= 0) {
            return value;
        }
    }
    while (convert(value) == state) {
        printf("please enter a valid character : ");
        scanf("%c", &value);
    }
    return value;
};
int ConvertToInt(char j) {
    switch (j) {
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
    }
}