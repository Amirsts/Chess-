#include <stdio.h>
int position(int i , int j);
void print_board();
int main(void) {
    print_board();
    return 0;
}
int position(int i , int j) {
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
    return location [i] [j];
}
void print_board() {
    for (int i = 7; i >= 0; i--) {
        printf("%d ", i+1);
        for (int j = 0; j < 8; j++) {
            switch (position(i, j)) {
                case 80:
                    printf("♙");
                break;
                case 78:
                    printf("♘");
                break;
                case 66:
                    printf("♗");
                break;
                case 82:
                    printf("♖");
                break;
                case 81:
                    printf("♕");
                break;
                case 75:
                    printf("♔");
                break;
                case 112:
                    printf("♟");
                break;
                case 110:
                    printf("♞");
                break;
                case 98:
                    printf("♝");
                break;
                case 114:
                    printf("♜");
                break;
                case 113:
                    printf("♛");
                break;
                case 107:
                    printf("♚");
                break;
                default:
                    printf(".");
            }
        }
        printf("\n");
    }
    printf("  a  b  c  d  e  f  g  h\n");
}
