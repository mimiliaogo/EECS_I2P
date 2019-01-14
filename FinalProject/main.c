#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define GAME_TERMINATE -1
#define PRE_ANIMATION 5
#define MAIN_MENU 1
#define ABOUT 3
#define EXIT 4
#define GAME_END 6
#define STORE 7
#define RANK 8
// ALLEGRO Variables
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_BITMAP *image = NULL;
ALLEGRO_BITMAP *image2 = NULL;
ALLEGRO_BITMAP *image3 = NULL;
ALLEGRO_BITMAP *image_snoopy_right_shoot = NULL;
ALLEGRO_BITMAP *image_snoopy_left_shoot = NULL;
ALLEGRO_BITMAP *bullet_image = NULL;
ALLEGRO_BITMAP *background = NULL;
ALLEGRO_BITMAP *about_background = NULL;
ALLEGRO_BITMAP *exit_background = NULL;
ALLEGRO_BITMAP *store= NULL;
ALLEGRO_BITMAP *no_money= NULL;
ALLEGRO_BITMAP *image_marcie_bomb = NULL;
ALLEGRO_KEYBOARD_STATE keyState ;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_TIMER *timer2 = NULL;
ALLEGRO_TIMER *timer3 = NULL;
ALLEGRO_TIMER *bullet_timer = NULL;
ALLEGRO_TIMER *bomb_start_timer = NULL;
ALLEGRO_TIMER *bomb_shoot_timer = NULL;
ALLEGRO_TIMER *animation_timer = NULL;
ALLEGRO_TIMER *bone1_go_timer = NULL;
ALLEGRO_TIMER *bone2_go_timer = NULL;
ALLEGRO_SAMPLE *song=NULL;
ALLEGRO_FONT *font_20 = NULL;
ALLEGRO_FONT *font_12 = NULL;
ALLEGRO_FONT *font_15 = NULL;
float mouse_x, mouse_y;
//Custom Definition
const char *title = "Final Project 10xxxxxxx";
const float FPS = 60;
const int WIDTH = 700;
const int HEIGHT = 700;

typedef struct character
{
    int x;
    int y;
    ALLEGRO_BITMAP *image_path;

}Character;

Character character1;
Character character2;
Character character3;
Character bullet;
Character bomb;
Character bone1;

typedef struct weapon
{
    int x;
    int y;
    int use_time;
    bool is_using;
    ALLEGRO_BITMAP *image_path;

} WEAPON;
WEAPON shield;
WEAPON first_aid_kit;
typedef struct
{
    int score;
    int money;
    char name[25];
} USER;
USER data[1000];

typedef struct
{
    int x;
    int y;
    bool start;
    int len;
    int speed;
    ALLEGRO_BITMAP *image_path;
    bool dir;//false for -->
    bool is_bullet_bone;
} BONE;

BONE bone[10];

char title_ani[25] = "Hi,everybody";
char money_str[25];
char weapon_str[25];
int pre_ani_str = 11;

int imageWidth = 0;
int imageHeight = 0;
int draw = 0;
int done = 0;
int window = PRE_ANIMATION;
int NumOfData;
int k = 0;
int shield_time = 0;
int bone_time = 0;


float move_speed = 5.0;
float bullet_speed = 50;
float bomb_speed = 60;
float bone_speed = 4;
float bone1_len = 80.0;
float len_comp = 180.0;
float len_user = 180.0;
bool judge_next_window = false;
bool judge_last_window = false;
bool ture = true; //true: appear, false: disappear
bool next = false; //true: trigger
bool dir = true; //true: left, false: right
bool bullet_shoot_user = false;//shoot the bullet
bool bomb_start = false;//shoot the bomb
bool bone1_start = false;
bool is_bullet = false;
bool is_bomb = false;
bool show_origin = true;
bool comp_win = false;
bool user_win = false;
bool isno_money = false;
bool name_end = false;
bool show_origin_user = true;
bool money_added = false;
void show_err_msg(int msg);
void game_init();
void game_begin();
int process_event();
int game_run();
void game_destroy();
void main_menu();
void main_menu_button();

int main(int argc, char *argv[]) {
    int msg = 0;
    FILE *fin, *fout;
    fin = fopen("user_data.txt", "r");
    fscanf(fin, "%d", &NumOfData);
    int i;
    printf("num:%d\n", NumOfData);
    NumOfData += 1;
    for (i=0; i<NumOfData; i++) {
        fscanf(fin, "%s", data[i].name);
        fscanf(fin, "%d%d", &data[i].score, &data[i].money);
    }
    fclose(fin);
    game_init();
    game_begin();

    while (msg != GAME_TERMINATE) {
        msg = game_run();
        if (msg == GAME_TERMINATE)
            printf("Game Over\n");
    }
    fout = fopen("user_data.txt", "w");
    fprintf(fout, "%d\n", NumOfData);
    for (i=0; i<NumOfData; i++) {
        fprintf(fout, "%s\n", data[i].name);
        fprintf(fout, "%d\n", data[i].score);
        fprintf(fout, "%d\n", data[i].money);
    }
    fclose(fout);


    game_destroy();
    return 0;
}


void show_err_msg(int msg) {
    fprintf(stderr, "unexpected msg: %d\n", msg);
    game_destroy();
    exit(9);
}

void game_init() {
    if (!al_init()) {
        show_err_msg(-1);
    }
    if(!al_install_audio()){
        fprintf(stderr, "failed to initialize audio!\n");
        show_err_msg(-1);
    }
    if(!al_init_acodec_addon()){
        fprintf(stderr, "failed to initialize audio codecs!\n");
        show_err_msg(-1);
    }
    if (!al_reserve_samples(1)){
        fprintf(stderr, "failed to reserve samples!\n");
        show_err_msg(-1);
    }
    // Create display
    display = al_create_display(WIDTH, HEIGHT);
    event_queue = al_create_event_queue();
    if (display == NULL || event_queue == NULL) {
        show_err_msg(-1);
    }
    // Initialize Allegro settings
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_audio();
    al_init_image_addon();
    al_init_acodec_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_mouse();

    // Register event
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    //For the pre_animation
    animation_timer  = al_create_timer(1.0/15.0);
    al_register_event_source(event_queue, al_get_timer_event_source(animation_timer));
    al_start_timer(animation_timer);

    // Imag load
    about_background = al_load_bitmap("about.png");
    exit_background = al_load_bitmap("exit.png");
    store = al_load_bitmap("store.png");
    no_money = al_load_bitmap("no_money.png");
//    pre_animation_pic = al_load_bitmap("envelop.png");

    //weapon initial
    shield.use_time = 0;
    shield.is_using = false;
    data[NumOfData-1].money = 200;

}
void pre_animation()
{
    al_draw_bitmap(about_background, 0,0, 0);
    al_draw_text(font_20, al_map_rgb(255,215,0), WIDTH/2, 100 , ALLEGRO_ALIGN_CENTRE, "Please enter your name!");
    al_draw_text(font_20, al_map_rgb(255,215,0), WIDTH/2-100, 600 , ALLEGRO_ALIGN_CENTRE, data[NumOfData-1].name);

}
void main_menu()
{

    al_clear_to_color(al_map_rgb(51,161,201));
    al_draw_text(font_20, al_map_rgb(255,215,0), WIDTH/2, 100 , ALLEGRO_ALIGN_CENTRE, "Press 'A' to about");
    al_draw_text(font_20, al_map_rgb(218,112,114), WIDTH/2, 200 , ALLEGRO_ALIGN_CENTRE, "Press 'E' to Exit");
    al_draw_text(font_15, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+220 , ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start");
    al_draw_rectangle(WIDTH/2-150, 510, WIDTH/2+150, 920, al_map_rgb(255, 255, 255), 10);

    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
}
void main_menu_button()
{
    al_draw_rectangle(10,7,160,30,al_map_rgb(23, 30, 100), 3);
    al_draw_text(font_15, al_map_rgb(103, 20, 89), 15, 10,0,"Main Menu");
}

void print_money()
{
//    al_draw_rectangle(WIDTH/2+200,HEIGHT/2-250,WIDTH/2+500,HEIGHT/2-300,al_map_rgb(23, 30, 100), 3);
    sprintf(money_str, "%d", data[NumOfData-1].money);
    al_draw_text(font_20, al_map_rgb(255,255,255), WIDTH/2+200, HEIGHT/2-320 , ALLEGRO_ALIGN_CENTRE, money_str);
    al_draw_text(font_20, al_map_rgb(255,255,255), WIDTH/2+160, HEIGHT/2-320 , ALLEGRO_ALIGN_CENTRE, "$");

}
void print_score()
{
    sprintf(money_str, "%d", data[NumOfData-1].score);
    al_draw_text(font_20, al_map_rgb(255,255,255), WIDTH/2+300, HEIGHT/2-300 , ALLEGRO_ALIGN_CENTRE, money_str);
    al_draw_text(font_20, al_map_rgb(255,255,255), WIDTH/2+200, HEIGHT/2-300 , ALLEGRO_ALIGN_CENTRE, "SCORE: ");
}
void show_weapon_time()
{
    al_draw_text(font_20, al_map_rgb(255,255,255), 60, HEIGHT/2-320 , ALLEGRO_ALIGN_CENTRE, "Shield:");
    sprintf(weapon_str, "%d", shield.use_time);
    al_draw_text(font_20, al_map_rgb(255,255,255), 150, HEIGHT/2-320 , ALLEGRO_ALIGN_CENTRE, weapon_str);
    al_draw_text(font_15, al_map_rgb(255,255,255), 70, HEIGHT/2-290 , ALLEGRO_ALIGN_CENTRE, "First-aid kit:");
    sprintf(weapon_str, "%d", first_aid_kit.use_time);
    al_draw_text(font_15, al_map_rgb(255,255,255), 150, HEIGHT/2-290 , ALLEGRO_ALIGN_CENTRE, weapon_str);
}
void show_bone(int n)
{
    al_draw_rectangle(bone[n].x,bone[n].y-10,bone[n].x+bone[n].len,bone[n].y-10,al_map_rgb(255, 0, 255), 10);
    al_draw_rectangle(bone[n].x-5,bone[n].y-20,bone[n].x+bone[n].len,bone[n].y, al_map_rgb(255, 120, 100), 2);
    al_draw_bitmap(bone[n].image_path, bone[n].x, bone[n].y, 0);
}
void blood_rec_computer(float len)
{
    al_draw_rectangle(WIDTH-len,20,WIDTH,20,al_map_rgb(255, 0, 0), 30);
}
void blood_rec_user(float len)
{
    al_draw_rectangle(0,HEIGHT-100,len,HEIGHT-100,al_map_rgb(255, 0, 0), 30);
}
int collide_computer()
{
    if (bullet.y<character2.y&&bullet.x>character2.x+10&&bullet.x<character2.x+95&&is_bullet==false) {
        is_bullet = true;
        show_origin = false;
        data[NumOfData-1].score += 50;
        return 1;
    }

    return 0;
}

int collide_user()
{
    if (bomb.y>character1.y&&is_bomb==false&&bomb.x>character1.x-5&&bomb.x<character1.x+65&&shield.is_using==false) {
        is_bomb = true;
        show_origin_user = false;
        data[NumOfData-1].score -= 50;
        return 1;
    }
    return 0;
}
int collide_bone(int n)
{
    if (bullet.y<bone[n].y&&bullet.x>bone[n].x+5&&bullet.x<bone[n].x+95&&bone[n].is_bullet_bone==false) {
        bone[n].is_bullet_bone = true;
        data[NumOfData-1].score += 10;
        return 1;
    }
    return 0;
}
int cmp_score(const void *a, const void *b)
{
    USER *pa = (USER *)a;
    USER *pb = (USER *)b;
    return pb->score-pa->score;
}
void game_begin() {
    // Load sound
    song = al_load_sample( "hello.wav" );
    if (!song){
        printf( "Audio clip sample not loaded!\n" );
        show_err_msg(-1);
    }
    // Loop the song until the display closes
    al_play_sample(song, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);

    // Load and (draw text)
    font_20 = al_load_ttf_font("pirulen.ttf",20,0);
    font_12 = al_load_ttf_font("pirulen.ttf",12,0);
    font_15 = al_load_ttf_font("pirulen.ttf",15,0);


}


int process_event(){
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);

    // Our setting for controlling animation
//    if(event.timer.source == animation_timer) {
//
//        al_draw_text(font_20, al_map_rgb(255,215,0), WIDTH/2, 100 , ALLEGRO_ALIGN_CENTRE, title_ani);
//
//    }
    if(event.timer.source == timer){

        if(character2.x < -150) dir = false;
        else if(character2.x > WIDTH+50) dir = true;

        if(dir) character2.x -= move_speed;
        else character2.x += move_speed;
        move_speed += 0.0001;

        shield_time ++;
        bone_time ++;
        int w;
        for (w=0; w<4; w++) {
            if (bone[w].x<0) bone[w].dir = false; //--->
            else if (bone[w].x>600) bone[w].dir = true;
            if (dir) bone[w].x -= bone[w].speed;
            else bone[w].x += bone[w].speed;
        }
    }
    if(event.timer.source == timer2){
        ture = false;
        next = true;
    }
    if(event.timer.source == timer3){
        if(next) next = false;
        else ture = true;
    }
    if(event.timer.source == bullet_timer){
        bullet.y -= bullet_speed;

    }
    if(event.timer.source == bomb_start_timer) {
        bomb_start = true;
        al_start_timer(bomb_shoot_timer);
        is_bomb = false;
        bomb.x = character2.x+30;
        bomb.y = character2.y+80;
    }
    if(event.timer.source == bomb_shoot_timer) {
        bomb.y += bomb_speed;
    }

//    if (bone_time%200==0) {
//        bone1_start = true;
//        bone1_len = 80.0;
////        al_start_timer(bone1_go_timer);
//        bone1.x =  ( rand() % (600-20+1) ) + 20;
//        bone1.y = ( rand() % (300-50+1) ) + 50;
//    }

    int w;
    for (w=0; w<4; w++) {
        if (bone_time%(200+50*w)==0&&bone_time>0) {
            bone[w].start = true;
            bone[w].len = 80;
            bone[w].x =  ( rand() % (600-20+1) ) + 20;
            bone[w].y = ( rand() % (300-50+1) ) + 50;
        }
    }
//
//    if (event.timer.source == bone1_go_timer) {
//        bone1.x -= bone_speed;
//    }


    // Keyboard
    if(event.type == ALLEGRO_EVENT_KEY_UP)
    {
        switch(event.keyboard.keycode)
        {
            // Control
            case ALLEGRO_KEY_UP:
                if (character1.y>10) character1.y -= 30;
                break;
            case ALLEGRO_KEY_DOWN:
                if (character1.y<HEIGHT-200) character1.y += 30;
                break;
            case ALLEGRO_KEY_LEFT:
                if (character1.x>10) character1.x -= 30;
                break;
            case ALLEGRO_KEY_RIGHT:
                if (character1.x<600) character1.x += 30;
                break;

            // For Start Menu
            case ALLEGRO_KEY_ENTER:
                judge_next_window = true;//for window 1
                if (window==PRE_ANIMATION) {
                    name_end = true;
                }
                break;
            case ALLEGRO_KEY_SPACE:
                if (window==2) {
                     bullet_shoot_user = true;//for window 2
                     al_start_timer(bullet_timer);
                     bullet.x = character1.x;
                     bullet.y = character1.y;
                     is_bullet = false;
                     int k;
                     for (k=0; k<4; k++) {
                        bone[k].is_bullet_bone = false;
                     }
                }
                break;
            // For About
            case ALLEGRO_KEY_A:
                if (window == MAIN_MENU) {
                    window = 3;
                }
                break;
            // For Exit
            case ALLEGRO_KEY_E:
                if (window==4) {
                    //PRESS Again  'E' to terminate.
                    return GAME_TERMINATE;
                }
                else if (window==1) window = 4;
                break;
            case ALLEGRO_KEY_S:
                if (window==MAIN_MENU) {
                    window = STORE;
                }
                break;
            //for shield
            case ALLEGRO_KEY_P:
                if (window==STORE) {
                    if (data[NumOfData-1].money<50) {
                        isno_money = true;
                    }
                    else {
                        isno_money = false;
                        data[NumOfData-1].money -= 50;
                        shield.use_time += 1;
                    }
                }
                else if (window == 2) {
                    if (shield.use_time>0) {
                        shield.use_time -= 1;
                        shield_time = 0;
                        shield.is_using = true;
                    }
                }
                break;
            case ALLEGRO_KEY_B:
                if (window == STORE) {
                    if (data[NumOfData-1].money<60) {
                        isno_money = true;
                    }
                    else {
                        isno_money = false;
                        data[NumOfData-1].money -= 60;
                        first_aid_kit.use_time += 1;
                    }
                }
                else if (window==2) {
                    if (first_aid_kit.use_time>0) {
                        first_aid_kit.use_time -= 1;
                        len_user += 10;
                    }
                }
            case ALLEGRO_KEY_R:
                if (window==GAME_END) {
                    window = RANK;
                }
                else if (window==MAIN_MENU) {
                    window = RANK;
                }
        }
    }
    //keyboard input
    if (event.type==ALLEGRO_EVENT_KEY_CHAR&&name_end==false) {
        if (window==PRE_ANIMATION) {
            data[NumOfData-1].name[k] = event.keyboard.unichar;
            data[NumOfData-1].name[k+1] = '\0';
            k++;

        }
    }

    if (name_end==true) data[NumOfData-1].name[k-1] = '\0';

    // Mouse position
    if(event.type==ALLEGRO_EVENT_MOUSE_AXES) {
        mouse_x = event.mouse.x;
        mouse_y = event.mouse.y;
//        character1.x = event.mouse.x;
//        character1.y = event.mouse.y;
    }
    // Mouse click

    if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        if (event.mouse.button==1) {
            if((10<mouse_x&&mouse_x<160)&&(7<mouse_y&&mouse_y<30)) judge_last_window = true;
        }
    }

    if (len_user<=0) comp_win = true;

    if (len_comp<=0) user_win = true;


    // Shutdown our program
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        return GAME_TERMINATE;

    return 0;
}

int game_run() {

    int error = 0;

    if (window == PRE_ANIMATION) {
        pre_animation();
//        scanf(fin, "%s", data[NumOfData-1].name);


        al_flip_display();
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
            if (judge_next_window) window = 1;
        }


    }
    // First window(Menu)
//    main_menu;
    if(window == MAIN_MENU){
        main_menu();
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
            if(judge_next_window) {
                window = 2;
                //user initial
                data[NumOfData-1].score = 0;
                money_added = false;
                comp_win = false;
                user_win = false;
                len_user = 180.0;
                len_comp = 180.0;
                //bone initial

                // Setting Character
                character1.x = WIDTH / 2;
                character1.y = HEIGHT - 210 ;
                character2.x = WIDTH + 100;
                character2.y = 5;
                bullet.x = 10000;
                bullet.y = 10000;
                character1.image_path = al_load_bitmap("Marcie_from_Peanuts_resized.png");
                character2.image_path = al_load_bitmap("snoopy_left.png");
                character3.image_path = al_load_bitmap("snoopy_right.png");
                image_snoopy_left_shoot = al_load_bitmap("snoopy_left_shoot.png");
                bullet.image_path = al_load_bitmap("bullet.png");
                bomb.image_path = al_load_bitmap("bomb.png");
                int t;
                for (t=0; t<4; t++) {
                    bone[t].image_path = al_load_bitmap("bone.png");
                    bone[t].start = false;
                    bone[t].speed = t*0.01+t+2;
                }
                background = al_load_bitmap("snoopy_background_resized.png");
                image_snoopy_right_shoot = al_load_bitmap("snoopy_right_shoot.png");
                image_marcie_bomb = al_load_bitmap("marcie_bomb.png");
                //Initialize Timer
                timer  = al_create_timer(1.0/15.0);
                timer2  = al_create_timer(1.0);
                timer3  = al_create_timer(1.0/10.0);
                bullet_timer = al_create_timer(1.0/15.0);
                bomb_shoot_timer = al_create_timer(1.0/15.0);
                bomb_start_timer = al_create_timer(1.0/1.0);
//                bone1_go_timer = al_create_timer(1.0/15.0);
//                bone2_go_timer = al_create_timer(1.0/15.0);
                al_register_event_source(event_queue, al_get_timer_event_source(timer)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(timer2)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(timer3)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(bullet_timer)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(bomb_shoot_timer)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(bomb_start_timer)) ;
//                al_register_event_source(event_queue, al_get_timer_event_source(bone1_go_timer)) ;
//                al_register_event_source(event_queue, al_get_timer_event_source(bone2_go_timer)) ;
                al_start_timer(timer);
                al_start_timer(timer2);
                al_start_timer(timer3);
                al_start_timer(bomb_start_timer);

            }

        }
    }
    // Second window(Main Game)
    else if(window == 2){
        // Change Image for animation

        al_draw_bitmap(background, 0,0, 0);
        show_weapon_time();
        print_score();
        blood_rec_computer(len_comp);
        blood_rec_user(len_user);
        main_menu_button();



        //snoopy

        if (show_origin==false) {
            if (dir) al_draw_bitmap(image_snoopy_left_shoot, character2.x, character2.y, 0);
            else al_draw_bitmap(image_snoopy_right_shoot, character2.x, character2.y, 0);
        }
        else {
            if (dir) al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
            else al_draw_bitmap(character3.image_path, character2.x, character2.y, 0);
        }

        if (show_origin_user==false) al_draw_bitmap(image_marcie_bomb, character1.x, character1.y, 0);
        else {
            if(ture) al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
        }
        //bullet for user

        if(bullet_shoot_user) al_draw_bitmap(bullet.image_path, bullet.x, bullet.y, 0);
//        if (bullet.y==1) is_bullet = false;
        //bomb for computer
        if(bomb_start) al_draw_bitmap(bomb.image_path, bomb.x, bomb.y, 0);
        //bone
        int t;
        for (t=0; t<4; t++) {
            if (bone[t].start&&bone[t].len>0) show_bone(t);
            if (collide_bone(t)) {
                bone[t].len -= 40;
            }
        }

//        if (bone1_start&&bone1_len>0) show_bone1(bone1_len);
        //bullet to computer
        if (collide_computer()) {
            len_comp -= 10;
        }
        if (collide_user()) {
            len_user -= 10;
        }


        if (bullet.y<-300) show_origin = true;
        if (bomb.y>900) show_origin_user = true;
        if (shield_time>80) shield.is_using = false;
        if (shield.is_using == true) {
            al_draw_rectangle(character1.x,character1.y-10,character1.x+65,character1.y+150 ,al_map_rgb(234, 24, 145), 5);
        }




        // Listening for new event
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
            if (judge_last_window) window = 1;
            if (comp_win==true||user_win == true) window = GAME_END;
        }
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
    }
    //about window
    else if (window == ABOUT) {
        al_draw_bitmap(about_background, 0,0, 0);
        main_menu_button();
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        // Listening for new event
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
            if (judge_last_window) window = 1;
        }
    }
    //exit window
    else if (window==EXIT) {
        al_draw_bitmap(exit_background, 0,0, 0);
        main_menu_button();
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        // Listening for new event
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
            if (judge_last_window) window = 1;
        }
    }
    else if (window==STORE) {
        al_draw_bitmap(store, 0,0, 0);
        print_money();
        main_menu_button();
        show_weapon_time();
        if (isno_money==true) {
            al_draw_bitmap(no_money, 300,300, 0);
        }
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
            if (judge_last_window) window = 1;

        }
    }
    else if (window == RANK) {
        al_clear_to_color(al_map_rgb(0,0,0));
        qsort(data, NumOfData, sizeof(USER), cmp_score);
        main_menu_button();
        int j;
        for (j=0; j<NumOfData; j++) {
            al_draw_text(font_20, al_map_rgb(255,255,255), 100, HEIGHT/2-300+40*j , ALLEGRO_ALIGN_CENTRE, data[j].name);
            sprintf(money_str, "%d", data[j].score);
            al_draw_text(font_20, al_map_rgb(255,255,255), WIDTH/2+200, HEIGHT/2-300+40*j , ALLEGRO_ALIGN_CENTRE, money_str);
        }
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
            if (judge_last_window) window = 1;
        }
        al_flip_display();
    }

    else if (window==GAME_END) {
        al_clear_to_color(al_map_rgb(0,230,128));
        main_menu_button();
        if (data[NumOfData-1].score>0&&money_added == false) {
            money_added = true;
            data[NumOfData-1].money += data[NumOfData-1].score;
        }
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
            if (judge_last_window) window = 1;
        }
        al_flip_display();
    }
    judge_last_window = false;
    judge_next_window = false;

    return error;
}

void game_destroy() {
    // Make sure you destroy all things
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destrㄇㄠoy_timer(timer);
    al_destroy_timer(timer2);
    al_destroy_timer(animation_timer);
    al_destroy_timer(bomb_shoot_timer);
    al_destroy_timer(bullet_timer);
    al_destroy_timer(bomb_start_timer);
    al_destroy_bitmap(image);
    al_destroy_sample(song);
}
