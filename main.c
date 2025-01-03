#include <stdio.h>
int position(int i , int j);
int pan(int i , int j);
int knight(int i , int j);
int move(int i , int j);
int bishop(int i , int j);
int rook(int i , int j);
int queen(int i , int j);
int King(int i , int j);
void print_board();
int main(void) {
    print_board();
    return 0;
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
    location[0][0] = ;
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
int move(int i , int j) {

}
int pan(int i , int j) {
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