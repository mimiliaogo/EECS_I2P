#include <stdio.h>
#define MAP_SIZE 12
#define CAR_SIZE 3

/* #define ONLINE_JUDGE */
int map[MAP_SIZE][MAP_SIZE];
void map_reset(void);
void map_show(void);

int blocks[MAP_SIZE][MAP_SIZE];
void blocks_read(void);
void blocks_put_on_map(void);

int jewels[MAP_SIZE][MAP_SIZE];
void jewels_read(void);
void jewels_put_on_map(void);

int car[CAR_SIZE][CAR_SIZE] = {{'0', '0', '@'}, {'0', '0', '0'},{'0', '0', '@'}};

int car_row = 3, car_col = 4;

int car_direction;
int car_earnings;
void car_rotate90(void);
void car_put_on_map(void);
void car_move(void);



int main()
{
    int ch;
	blocks_read();
	jewels_read();

    map_reset();
    blocks_put_on_map();
    jewels_put_on_map();
    car_put_on_map();

    map_show();//initial map

#ifndef ONLINE_JUDGE
    freopen("actions.txt", "r", stdin);
#endif // ONLINE_JUDGE
    while ((ch=getchar()) != EOF) {
        if (ch=='R') {
            car_rotate90();
        }

        if (ch=='F') {
            car_move();
        }

        map_reset();
        blocks_put_on_map();
        jewels_put_on_map();
        car_put_on_map();
        map_show; //for testing
    }
    printf("Earnings: %d\n",car_earnings);
    printf("Position: row=%d, col=%d\n", car_row, car_col);

    char dirs[] = "RDLU";
    printf("%c", dirs[car_direction]);

    return 0;

}

void blocks_read(void)
{
    int i,n,row,col;
    #ifndef ONLINE_JUDGE
	freopen("blocks.txt", "r", stdin);
    #endif
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d%d", &row, &col);
        blocks[row][col] = 1;
    }
}
void blocks_put_on_map(void)
{
    int i,j;
    for (i=0; i<MAP_SIZE; i++) {
        for (j=0; j<MAP_SIZE; j++) {
            if (blocks[i][j]) {
                map[i][j] = '#';
            }
        }
    }
}
void jewels_read(void)
{
    int i,j,n;
    int row, col;
    #ifndef ONLINE_JUDGE
    freopen("jewels.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d%d",&row, &col);
        jewels[row][col] = 1;
    }
}

void jewels_put_on_map(void)
{
    int i, j;
	for (i=0; i<MAP_SIZE; i++) {
		for (j=0; j<MAP_SIZE; j++) {
			if (jewels[i][j])
				map[i][j] = '$';
		}
	}
}
void map_reset(void)
{
    int i, j;
	for (i=0; i<MAP_SIZE; i++) {
		for (j=0; j<MAP_SIZE; j++) {
			map[i][j] = '.';
		}
	}
	for (i=0; i<MAP_SIZE; i++) {
		map[i][0] = 'H';
		map[i][MAP_SIZE-1] = 'H';
	}
	for (j=0; j<MAP_SIZE; j++) {
		map[0][j] = 'H';
		map[MAP_SIZE-1][j] = 'H';
	}
}

void map_show(void)
{
    int i, j;
    for (i=0; i<MAP_SIZE; i++) {
        for (j=0; j<MAP_SIZE; j++) {
            putchar(map[i][j]);
        }
        printf("\n");
    }
}

void car_put_on_map(void)
{
    int i, j;
    for (i=0; i<CAR_SIZE; i++) {
        for (j=0; j<CAR_SIZE; j++) {
            map[i+car_row][j+car_col]=car[i][j];
        }
    }
}








void car_rotate90(void)
{
    int tmp;
    if (car_direction==0 || car_direction ==2) {
            tmp = car[0][2];
            car[0][2] = car[2][0];
            car[2][0] = tmp;
    }else {
        tmp = car[0][0];
        car[0][0] = car[2][2];
        car[2][2] = tmp;
    }

    car_direction = (car_direction+1) % 4;
}

void car_move(void)
{
    int row_diff[] = {0, 1, 0, -1};
    int col_diff[] = {1, 0, -1, 0};// 查表
    int car_row_new, car_col_new;
    int valid = 1;
    int i, j;
    car_row_new = car_row + row_diff[car_direction];
    car_col_new = car_col + col_diff[car_direction];
    // don't need to do the branching
    for (i=0; i<CAR_SIZE; i++) {
        for (j=0; j<CAR_SIZE; j++) {
            if (map[i+car_row_new][j+car_col_new]=='H'
                || blocks[i+car_row_new][j+car_col_new]==1) {
                    valid = 0;
                }
        }
    }
    if (valid) {
        car_row = car_row_new;
        car_col = car_col_new;
        for (i=0; i<CAR_SIZE; i++) {
            for (j=0; j<CAR_SIZE; j++) {
                if (jewels[i+car_row_new][j+car_col_new]==1) {
                    car_earnings++;
                    jewels[i+car_row_new][j+car_col_new]--;
                }
            }
        }

    }


}
