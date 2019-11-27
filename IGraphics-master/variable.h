#ifndef VARIABLE_H_INCLUDED
#define VARIABLE_H_INCLUDED



#endif // VARIABLE_H_INCLUDED
///properties of the ball
typedef struct
{
    float x;
    float y;
    float dx,dy;
    int show; ///determine weather to show the ball after being hit by the arrow
}point;
point ball[3];
int ball_count=2;
int ball_num;
int ball_speed=1;


///properties of the arrow
typedef struct
{
    int x,y,is_sht;
}arrow;
arrow arw[100];
int arw_tracker=0;

///properties of menu
typedef struct
{
    int mode;
    int leader_board;
    int save_game;
    int instruction;
    int credit;
}menus;
menus menu;
int leader=970,start=970,ball_come=970,name_come=970;



///properties of game screen
int line[4]={0,90,70,70};
int scr_x=970,scr_y=508;

///properties of the man
int man_x=473,man_y=line[1];
char man[6][20]={"char_img\\left2.bmp","char_img\\left1.bmp","char_img\\man.bmp","char_img\\right1.bmp","char_img\\right2.bmp"};
int man_idx=2;

///properties of life
int life=7;
char life_pic[6][20]={"\0","life\\life1.bmp","life\\life11.bmp","life\\life2.bmp","life\\life3.bmp","life\\life4.bmp"};

///properties of level change
char level_pic[4][20]={"\0","bgimage\\pic1.bmp","bgimage\\pic2.bmp","bgimage\\pic3.bmp"};
int level_cnt=-4;
int mission_accomplished;

///properties of score
typedef struct
{
    int ball;
    int time;
    int total;
    int highest;
    int life;
    int previous;
    int final_score;
}scoring;
scoring score;
//int score=0;
//int score;
int highest_score;
int time_bonus=150;

///level time
int level_time=0,chk_score=1;
///pause game
int pause=0;
int pause_temp=0; ///for showing the leaderboard in the level
int click_leader=0;
int after_over; ///for after gameover delay
int after_won; ///for after level up delay


typedef struct
{
    char pname[20];
    int pscore;
}player;

player scores[80];
char playername[80];
int nameinput,len;

int pro=0;

///SOUND ON OFF
int sound_mode=0;
char sound[4][80]={"sounds\\sherlock_home.wav","sounds\\harry_potter_1.wav","sounds\\pirates_of_carabian_2.wav","sounds\\mission_impossible_3.wav"};

///FOR THE DRAG THE TEXT IN MENU AND NAMEINPUTJ
typedef struct
{
    int ball;
    int game;
    int start;
    int instruction;
    int leader;
    int sound;
    int new_highest_score;
    int enter_name;
}move_text;

move_text drag;

