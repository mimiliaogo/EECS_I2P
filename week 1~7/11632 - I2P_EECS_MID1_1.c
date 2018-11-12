#include <stdio.h>
#include <string.h>

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

char map[100][100];
char actions[100]={};
int coin_amount = 0;

// tank's initial direction
char init_dir;
// tank's direction now
int dir_now ;
// tank's center x and y
int center_x, center_y;

int center_x_new, center_y_new;// by myself

void decide_initial_direction()
{
    /// Decide tank's initial direction
    /// Using init_dir
    /// To determine dir_now
    char dir[] = "ESWN";
    int i;
    for (i=0; i<4; i++) {
        if (dir[i]==init_dir) dir_now = i;
    }



}

void take_a_step()
{
    int row_diff[] = {0, 1, 0, -1};
    int col_diff[] = {1, 0, -1, 0};
    int i,j;
    int valid = 1;
    center_x_new = center_x + row_diff[dir_now];
    center_y_new = center_y + col_diff[dir_now];

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (map[center_x_new-1+i][center_y_new-1+j]=='#'
                ||map[center_x_new-1+i][center_y_new-1+j]=='^') {
                    valid = 0;
                }
        }
    }
     if (valid) {
        center_x = center_x_new;
        center_y = center_y_new;
     }
}

void pick_the_coins()
{
    int j, k;
    for (j = center_x - 1; j <= center_x + 1; j++){
        for (k = center_y - 1; k <= center_y + 1; k++){
            /// determine whether there are coins under the tank
            if (map[j][k] == '$') {
                coin_amount++;
                map[j][k] = '=';
            }

        }
    }
}

void turn_right()
{
    /// Change direction depending on dir_now
    dir_now = (dir_now+1)%4;
}



void turn_left()
{
    /// Change direction depending on dir_now
    dir_now = (dir_now+3)%4;
}

int main()
{
    int i, j, k, rows, cols;
    int actions_number;
    int component = 0;

    /// Raed problem's input
    scanf("%d %d %d %c", &rows, &cols, &actions_number, &init_dir);
    while (getchar() != '\n');
    for (i = 0; i < actions_number; i++){
        scanf("%c", &actions[i]);
    }

    /// Read map
    for (i = 1; i <= rows; i++){
        while (getchar() != '\n');
        for (j = 1; j <= cols; j++){
            scanf("%c", &map[i][j]);
            /// Find tank's center x and y
            if (((map[i][j]) == 'x') || ((map[i][j]) == 'o') || ((map[i][j]) == 'O')){
                component++;
                if (component == 5){
                    center_x = i;
                    center_y = j;
                }
            }
        }
    }

    decide_initial_direction();

    for (i = 0; i < actions_number; i++){
        if (actions[i] == 'F'){
            take_a_step();
            pick_the_coins();
        }
        else{
            if (actions[i] == 'R'){
                turn_right();
            }
            if (actions[i] == 'L'){
                turn_left();
            }
        }
    }

    printf("%d\n", coin_amount);

    return 0;
}
