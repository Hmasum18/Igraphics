#include "iGraphics.h"
#include<string.h>
#include<stdlib.h>
#include "gl.h"
#include<windows.h>
#include "variable.h"
#include "score.h"

#include "show.h"
#include "level.h"
#include "hit.h"
#include "win_over.h"
#include "pause_resume.h"


/*
	function iDraw() is called again and again by the system.
*/


///here p and q are the bottom left co-ordinate of the ball
void make_ball(int p,int q) ///called by all level funtion
{
    iSetColor(255, 25, 101);
	if(level_cnt==3) iShowBMP2(p,q,"ball\\ballorange.bmp",0);
	if(level_cnt==1) iShowBMP2(p,q,"ball\\ballred1.bmp",0);
	if(level_cnt==2) iShowBMP2(p,q,"ball\\ballred1.bmp",0);
}

///make the arrows
void is_shoot()  ///called by all level funtion
{
    for(int i=0;i<100;i++) ///if f is pressed
    {
        if(arw[i].is_sht) iShowBMP2(arw[i].x+18,arw[i].y+20,"char_img\\arrow.bmp",0);
    }
}

void iDraw()
{
	iClear();
	///make loading
	if(level_cnt<0)
    {
        iSetColor(255,255,255);

        iShowBMP(0,0,"bgimage\\loading.bmp");
        //iText(400,300,"LOADING...",GLUT_BITMAP_TIMES_ROMAN_24);
        iShowBMP2(340,240,"bgimage\\load.bmp",170);
        iSetColor(220,0,36);
        if(level_cnt>=-3) iFilledCircle(430,250,10);
        if(level_cnt>=-2) iFilledCircle(490,250,10);
        if(level_cnt>=-1) iFilledCircle(550,250,10);
    }
    if(level_cnt==0)
    {
        show_menu();
    }
    if(level_cnt==1)
    {
        resume_game();
        iPauseTimer(2);
        level1();
            show_score();
            show_higest_score();
            show_level_time();
            show_ball_number();
        if(gameover())
        {
            after_gameover();
        }
       // pause_resume();
    }
    if(level_cnt==2)
    {
        resume_game();
        iPauseTimer(1);
        level2();
        if(!gameover()||!you_won(2))
        {
            show_score();
            show_higest_score();
            show_level_time();
            show_ball_number();
        }
        if(gameover())
        {
            after_gameover();
        }
       // pause_resume();

    }
    if(level_cnt==3)
    {
        resume_game();
        level3();
        if(!gameover()||!you_won(3))
        {
            show_score();
            show_higest_score();
            show_level_time();
            show_ball_number();
        }
        if(gameover())
        {
            after_gameover();
        }
       // pause_resume();
    }
    pause_resume();

    //iRectangle(19,19,127,58);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	    if(level_cnt==0) ///when we are in menu
        {
            if(mx>=521&&mx<=521+290&&my>=255&&my<=255+74) ///click start game
            {
              // level_cnt=1;
                level_cnt=3;
               //level1_initial();
               level3_initial();
                life=7;
                score.total=0;
                score.life=0;
                score.time=0;
                score.final_score=0;
                score.previous=0;
                score.ball=0;
                return ;
            }
             //iRectangle(521,146,290,74);
             if(mx>=521&&mx<=521+290&&my>=146&&my<=146+74) ///click leader board;
             {
                 menu.leader_board=1;
             }
             if(menu.leader_board)
             {
                // iRectangle(14,24,127,58);
                 if(mx>=19&&mx<=19+127&&my>=19&&my<=19+58) ///click back in leader board
                 {

                       menu.leader_board=0;
                       level_cnt==0;
                       if(sound_mode) PlaySound("sounds\\sherlock_home.wav", NULL,SND_LOOP | SND_ASYNC);


                 }
             }
            ///852,28,101,58
            if(mx>=852&&mx<=852+101&&my>=28&&my<=28+58) ///click exit
                    exit(1);

        }

          ///for level 2
        if(level_cnt==1&&you_won(1))
            if(mx>=970-150&&mx<=970-150+117&&my>=30&&my<=30+40) ///click next
            {
                level_cnt=2;
                 score.total=score.previous+score.total;
                level2_initial();

                return ; ///return if level 2 starts
            }
                ///for level 3
        if(level_cnt==2&&you_won(2))
            if(mx>=970-150&&mx<=970-150+117&&my>=30&&my<=30+40) ///click next
            {
                level_cnt=3;
                score.total=score.previous+score.total;
                level3_initial();

            }
        if(gameover()||you_won(level_cnt))
        {
           // printf("%d\n",level_cnt);

        if(mx>=970-200&&mx<=970-200+185&&my>=30&&my<=30+50) ///home button
        {
            pause_game();
           // printf("%d\n",score.total);
            if(score.final_score>scores[4].pscore)
                   nameinput=1;
            if(!nameinput)
            {
                level_cnt=0;
                if(sound_mode) PlaySound("sounds\\sherlock_home.wav", NULL,SND_LOOP | SND_ASYNC);
                mission_accomplished=0;
            }
        }
        }

        if(pause)
        {
            if(mx>=350&&mx<=350+123&&my>=200&&my<=200+120) ///click resume
                     pause=0;
            if(mx>=455&&mx<=455+127&&my>=195&&my<=195+120) ///click home
            {
                pause_game();
                level_cnt=0;
                PlaySound("sounds\\sherlock_home.wav", NULL,SND_LOOP | SND_ASYNC);
                pause=0;
            }
        }

        if(level_cnt>0&&!pause&&!gameover()&&!you_won(level_cnt))
        if(mx>=455&&mx<=455+69&&my>=1&&my<=1+70) ///click pause
        {
            pause=1;
        }

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	     ///take the co-ordinate of man's current positoin
        arw[arw_tracker].x=man_x;
        arw[arw_tracker].y=man_y;

        arw[arw_tracker].is_sht=1; ///indicate to show the arrow
        arw_tracker++; ///go to next arrow
        arw_tracker%=100; ///as we have 100 arrow at maxa
	}

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
 /// move the man when we press a (right) and d (left)
	if(key=='a'||key=='A')
    {
        if(man_idx==4) man_idx=3;
        man_x-=5,man_idx--;
        if(man_idx==-1) man_idx=1;

    }
    if(key=='d'||key=='D')
    {
        if(man_idx==0) man_idx=1;
        man_x+=5,man_idx++;
        if(man_idx==5) man_idx=3;
    }
    if(key=='w'||key=='W')
    {
        ///take the co-ordinate of man's current positoin
        arw[arw_tracker].x=man_x;
        arw[arw_tracker].y=man_y;

        arw[arw_tracker].is_sht=1; ///indicate to show the arrow
        arw_tracker++; ///go to next arrow
        arw_tracker%=100; ///as we have 100 arrow at max
    }
    ///take name input after gameover or win
    if(nameinput==1)
    {
        if(key=='\r')
        {
            FILE *fp;
            fp=fopen("highest_score.txt","a");
            fprintf(fp,"%s %d\n",playername,score.final_score);
          //  fflush(fp);
            fclose(fp);

            menu.leader_board=1;
            //highest_score_system();
            nameinput=0;
            level_cnt=0;
            drag.new_highest_score=970; ///will drag again
            drag.enter_name=970;
            if(sound_mode) PlaySound("sounds\\sherlock_home.wav", NULL,SND_LOOP | SND_ASYNC);
            mission_accomplished=0;
            for(int i=strlen(playername)-1;i>=0;i--) playername[i]=0;
            len=0;
        }
        ///new code
        else if(key=='\b') ///if press backspace
        {
            if(len<=0) len=0;
            else len--;
            playername[len]=0;
        }
        else
        {
            playername[len++]=key;
        }
    }
}

/*a
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(1);
	}
	if(key== GLUT_KEY_RIGHT)
    {
        if(man_idx==0) man_idx=1;
        if(man_x<=970-36)
            man_x+=7;
        man_idx++;
        if(man_idx==5) man_idx=3;
    }
	if(key== GLUT_KEY_LEFT)
    {
        if(man_idx==4) man_idx=3;
        if(man_x>=7)
            man_x-=7;
        man_idx--;
        if(man_idx==-1) man_idx=1;
    }
    if(key==GLUT_KEY_UP) man_idx=2;
}

void ballChange(){
    if(if_hit_man(0)==1) {life--;printf("ball\n");}
	ball[0].x =ball[0].x+ ball[0].dx;
	ball[0].y =(150*sin(ball[0].x/50+5)+line[level_cnt]);

	if(ball[0].x > scr_x-30|| ball[0].x < 0)
    {
        ball[0].dx = -ball[0].dx;
    }
	if(ball[0].y <line[level_cnt])
    {
        ball[0].y = (ball[0].y+2*(line[level_cnt]-ball[0].y));

    }

}
void ballChange1()
{
    if(if_hit_man(1)==1) {life--;printf("ball11111\n");}
    ball[1].x+=ball[1].dx;
    ball[1].y=150*sin(ball[1].x/50)+line[level_cnt];
    if(ball[1].x>scr_x-30||ball[1].x<0)
    {
        ball[1].dx=-ball[1].dx;
    }

    if(ball[1].y<line[level_cnt])
    {
        ball[1].y=(ball[1].y+2*(line[level_cnt]-ball[1].y));

    }

}

void ballChange2()
{
    if(if_hit_man(2)) {life--;printf("ball2222\n");}
    ball[2].x+=ball[2].dx;
    ball[2].y=150*sin(ball[2].x/50)+line[level_cnt];
    if(ball[2].x>scr_x-30||ball[2].x<0)
    {
        ball[2].dx=-ball[2].dx;
    }

    if(ball[2].y<line[level_cnt])
    {
        ball[2].y=(ball[2].y+2*(line[level_cnt]-ball[2].y));

    }
}

void arrowChange()
{
    for(int i=0;i<100;i++)
    {
        arw[i].y+=5; ///=10
        if(arw[i].y>scr_y) arw[i].is_sht=0;
    }
    if(level_cnt==0) ///for menu;
    {
        if(drag.ball>25) drag.ball-=35;
        if(drag.ball<=25&&drag.game>20) drag.game-=30;
        //if(start>521) start-=20;
       // if(start==521&&leader>521) leader-=20;
    }
    if(nameinput)
    {
        if(drag.new_highest_score>=240) drag.new_highest_score-=50;
        //if(drag.new_highest_score<=220) drag.enter_name-=35;
    }
}
void levelTimer()
{
        level_time++;
}
void load_page()
{
    if(level_cnt<0) level_cnt++;
    ///for after game show
    if(gameover()&&after_over<2) after_over++;
    if(you_won(level_cnt)&&after_won<5) after_won++;
}

int main()
{
    sound_mode=0;
    drag.ball=970,drag.game=970,drag.start=970,drag.instruction=970,drag.leader=970,drag.sound=970,drag.new_highest_score=970,drag.enter_name=970;

    iSetTimer(ball_speed, ballChange);
    iSetTimer(ball_speed,ballChange1);
    iSetTimer(ball_speed,ballChange2);
    iSetTimer(1,arrowChange);
    iSetTimer(1000,levelTimer);
    iSetTimer(1000,load_page);

    if(sound_mode) PlaySound("sounds\\sherlock_home.wav", NULL,SND_LOOP | SND_ASYNC);
	iInitialize(scr_x, scr_y, "SHOOT THE BALL");

	return 0;
}

