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

// ALLEGRO Variables
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_BITMAP *image = NULL;
ALLEGRO_BITMAP *image2 = NULL;
ALLEGRO_BITMAP *image3 = NULL;
ALLEGRO_BITMAP *bullet_image = NULL;
ALLEGRO_BITMAP *background = NULL;
ALLEGRO_BITMAP *about_background = NULL;
ALLEGRO_BITMAP *exit_background = NULL;
ALLEGRO_KEYBOARD_STATE keyState ;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_TIMER *timer2 = NULL;
ALLEGRO_TIMER *timer3 = NULL;
ALLEGRO_TIMER *bullet_timer = NULL;
ALLEGRO_TIMER *bomb_start_timer = NULL;
ALLEGRO_TIMER *bomb_shoot_timer = NULL;
ALLEGRO_SAMPLE *song=NULL;
ALLEGRO_FONT *font_20 = NULL;
ALLEGRO_FONT *font_12 = NULL;
ALLEGRO_FONT *font_15 = NULL;
float mouse_x, mouse_y;
//Custom Definition
const char *title = "Final Project 10xxxxxxx";
const float FPS = 60;
const int WIDTH = 700;
const int HEIGHT = 500;

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

int imageWidth = 0;
int imageHeight = 0;
int draw = 0;
int done = 0;
int window = 1;
float move_speed = 10.0;
float bullet_speed = 50;
float bomb_speed = 60;
float len_comp = 185.0;
float len_user = 185.0;
bool judge_next_window = false;
bool judge_last_window = false;
bool ture = true; //true: appear, false: disappear
bool next = false; //true: trigger
bool dir = true; //true: left, false: right
bool bullet_shoot_user = false;//shoot the bullet
bool bomb_start = false;//shoot the bomb

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

    game_init();
    game_begin();

    while (msg != GAME_TERMINATE) {
        msg = game_run();
        if (msg == GAME_TERMINATE)
            printf("Game Over\n");
    }

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


    // Imag load
    about_background = al_load_bitmap("about.png");
    exit_background = al_load_bitmap("exit.png");

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
    al_draw_text(font_15, al_map_rgb(103, 20, 89), 15, 10,0,"Main menu");


}

void blood_rec_computer(float len)
{
    al_draw_rectangle(WIDTH-len,20,WIDTH,20,al_map_rgb(255, 0, 0), 30);
}
void blood_rec_user(float len)
{
    al_draw_rectangle(0,HEIGHT-20,len,HEIGHT-20,al_map_rgb(255, 0, 0), 30);
}
void collide_computer(float len)
{
    //waiting
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
    if(event.timer.source == timer){

        if(character2.x < -150) dir = false;
        else if(character2.x > WIDTH+50) dir = true;

        if(dir) character2.x -= move_speed;
        else character2.x += move_speed;
        move_speed += 0.0001;

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
        bomb.x = character2.x;
        bomb.y = character2.y;
    }
    if(event.timer.source == bomb_shoot_timer) {
        bomb.y += bomb_speed;
    }


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
                if (character1.y<320) character1.y += 30;
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
                if (window==2) {
                     bullet_shoot_user = true;//for window 2
                     al_start_timer(bullet_timer);
                     bullet.x = character1.x;
                     bullet.y = character1.y;
                }
                break;
            // For About
            case ALLEGRO_KEY_A:
                window = 3;
                break;
            // For Exit
            case ALLEGRO_KEY_E:
                if (window==4) {
                    //PRESS Again  'E' to terminate.
                    return GAME_TERMINATE;
                }
                else if (window==1) window = 4;
                break;
        }
    }
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




    // Shutdown our program
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        return GAME_TERMINATE;

    return 0;
}

int game_run() {

    int error = 0;
    // First window(Menu)
    main_menu;
    if(window == 1){
        main_menu();
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
            if(judge_next_window) {
                window = 2;
                // Setting Character
                character1.x = WIDTH / 2;
                character1.y = HEIGHT / 2 + 150;
                character2.x = WIDTH + 100;
                character2.y = HEIGHT / 2 - 280;
                character1.image_path = al_load_bitmap("tower.png");
                character2.image_path = al_load_bitmap("teemo_left.png");
                character3.image_path = al_load_bitmap("teemo_right.png");
                bullet.image_path = al_load_bitmap("bullet.png");
                bomb.image_path = al_load_bitmap("bullet.png");
                background = al_load_bitmap("stage.jpg");


                //Initialize Timer
                timer  = al_create_timer(1.0/15.0);
                timer2  = al_create_timer(1.0);
                timer3  = al_create_timer(1.0/10.0);
                bullet_timer = al_create_timer(1.0/15.0);
                bomb_shoot_timer = al_create_timer(1.0/15.0);
                bomb_start_timer = al_create_timer(1.0/1.0);
                al_register_event_source(event_queue, al_get_timer_event_source(timer)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(timer2)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(timer3)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(bullet_timer)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(bomb_shoot_timer)) ;
                al_register_event_source(event_queue, al_get_timer_event_source(bomb_start_timer)) ;
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
        blood_rec_computer(len_comp);
        blood_rec_user(len_user);
        main_menu_button();
        //character
        if(ture) al_draw_bitmap(character1.image_path, character1.x, character1.y, 0);
        if(dir) al_draw_bitmap(character2.image_path, character2.x, character2.y, 0);
        else al_draw_bitmap(character3.image_path, character2.x, character2.y, 0);
        //bullet for user

        if(bullet_shoot_user) al_draw_bitmap(bullet.image_path, bullet.x, bullet.y, 0);

        //bomb for computer
        if(bomb_start) al_draw_bitmap(bomb.image_path, bomb.x, bomb.y, 0);

        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));

        // Listening for new event
        if (!al_is_event_queue_empty(event_queue)) {
            error = process_event();
            if (judge_last_window) window = 1;
        }
    }
    //about window
    else if (window==3) {
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
    else if (window==4) {
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
    judge_last_window = false;
    judge_next_window = false;

    return error;
}

void game_destroy() {
    // Make sure you destroy all things
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_timer(timer2);
    al_destroy_bitmap(image);
    al_destroy_sample(song);
}
