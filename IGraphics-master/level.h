#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED



#endif // LEVEL_H_INCLUDED
#pragma comment(lib, "variable.h")
extern void make_ball(int ,int);
extern void is_shoot();
extern void is_hit_ball(int);
extern int is_hit_man(int);
void level1_initial()
{
    drag.new_highest_score=970,drag.enter_name=-448;
    nameinput=0;
    score.previous=0;
    score.total=0;
    score.ball=0,score.time=0,score.life=0;
    ball_num=10;
    level_time=0,chk_score=0;
    time_bonus=150;

    after_over=0;
    after_won=0;

    life=7;

    ball[1].show=1;
    ball[0].show=1;
    ball[2].show=1;

    ball[0].dx=1.5; //2
	ball[1].dx=1.6; //2.5
	//ball[2].dx=-2;
	ball[1].x=0,ball[1].y=line[level_cnt];
	ball[0].x=0,ball[0].y=line[level_cnt];
   //ball[2].x=970-30,ball[2].y=line[2];
	man_x=473,man_y=line[1];
	man_idx=2;
    if(sound_mode) PlaySound(sound[1], NULL,SND_LOOP | SND_ASYNC);

}
void level1()
{

    iShowBMP(0,0,level_pic[1]);
    ///show life
    if(life) ///show the lifes
    {
        ///iShowBMP2(scr_x-150,scr_y-50,life_pic[life],170);
        for(int i=0,j=scr_x-215;i<life;i++,j+=30)
        {
            iShowBMP2(j,scr_y-50,"life\\life.bmp",170);
        }
    }
	iShowBMP2(man_x,man_y,man[man_idx],0);/// show the man
	iLine(0,line[level_cnt],971,line[level_cnt]); ///show the line
	iShowBMP2(210,405,"menu\\level_1_name.bmp",0); ///show the levels name
	iShowBMP2(455,1,"menu\\pause.bmp",0);/// show the pause button

    is_shoot(); /// show the arrow if 'w' or space key is press or we right click the mouse

	is_hit_ball(1); ///if the arrow hits the ball number 1
	if(!ball[1].show) iPauseTimer(1);///we have to pause the ball as it will kept moving after being hit
                                     ///otherwise life will be gone
    else make_ball(ball[1].x,ball[1].y);

    is_hit_ball(0); ///if the arrow hits the ball number 2
    if(!ball[0].show) iPauseTimer(0);
	else make_ball(ball[0].x,ball[0].y);

    iSetColor(255, 255, 255);

    gameover();
    you_won(1);
}
void level2_initial()
{
    after_won=0;
    pro=0;
    score.previous=score.total;
    score.total=0;
    score.ball=0,score.time=0,score.life=0;
    ball_num=10;
    level_time=0,chk_score=0;
    time_bonus=150;
    man_idx=2;
    man_x=473,man_y=line[level_cnt];
    ball[0].show=1;
    ball[2].show=1;
    ball[0].dx=2.5,ball[2].dx=2.5; ///3.5
    ball[0].x=100,ball[0].y=line[level_cnt];
    ball[2].x=scr_x-30,ball[2].y=line[level_cnt];
    if(sound_mode) PlaySound(sound[2], NULL,SND_LOOP | SND_ASYNC);
}
void level2()
{
    iShowBMP(0,0,level_pic[2]);
   ///show life
    if(life)
    {
        ///iShowBMP2(scr_x-150,scr_y-50,life_pic[life],170);
        for(int i=0,j=scr_x-215;i<life;i++,j+=30)
        {
            iShowBMP2(j,scr_y-50,"life\\life.bmp",170);
        }
    }
	iShowBMP2(man_x,man_y,man[man_idx],0);
	//iSetColor(0,0,0); //for pic4
	iSetColor(0,0,200);
	iLine(0,line[level_cnt],1600,line[level_cnt]);
    iSetColor(255,255,255);
    iShowBMP2(455,1,"menu\\pause.bmp",0);

	is_hit_ball(2);
    if(ball[2].show) make_ball(ball[2].x,ball[2].y); ///if not hit by arrow
    else iPauseTimer(2);

    is_hit_ball(0);
	if(ball[0].show) make_ball(ball[0].x,ball[0].y);
	else iPauseTimer(0);

    iSetColor(255, 255, 255);
    is_shoot();


    gameover();
    you_won(2);
}
void level3_initial()
{
    after_won=0;
    after_over=0;
    pro=0;
    score.previous=score.total;
    score.total=0;
    score.ball=0,score.time=0,score.life=0;
    ball_num=10;
    level_time=0,chk_score=0;
    time_bonus=150;
    man_x=473,man_y=line[level_cnt];
    ball[0].show=1;
    ball[1].show=1;
    ball[2].show=1;

    ball[0].dx=3.3,ball[2].dx=3.3,ball[1].dx=3; ///4.5,4.5,4

    ball[0].x=0,ball[0].y=line[level_cnt];
    ball[1].x=50,ball[1].y=line[level_cnt];
    ball[2].x=scr_x-30,ball[2].y=line[level_cnt];

    if(sound_mode) PlaySound(sound[3], NULL,SND_LOOP | SND_ASYNC);
}
void level3()
{
    iShowBMP(0,0,level_pic[3]);
    ///show life
    if(life)
    {
        ///iShowBMP2(scr_x-150,scr_y-50,life_pic[life],170);
        for(int i=0,j=scr_x-215;i<life;i++,j+=30)
        {
            iShowBMP2(j,scr_y-50,"life\\life.bmp",170);
        }
    }
	iShowBMP2(man_x,man_y,man[man_idx],0);
	//iSetColor(0,0,0); //for pic4
	iLine(0,line[level_cnt],scr_x,line[level_cnt]);
	iShowBMP2(455,1,"menu\\pause.bmp",0);

	is_hit_ball(2);
    if(ball[2].show) make_ball(ball[2].x,ball[2].y); ///if not hit by arrow
    else iPauseTimer(2);

    is_hit_ball(1);
    if(ball[1].show) make_ball(ball[1].x,ball[1].y); ///if not hit by arrow
    else iPauseTimer(1);

    is_hit_ball(0);
	if(ball[0].show) make_ball(ball[0].x,ball[0].y);
	else iPauseTimer(0);

    iSetColor(255, 255, 255);
    is_shoot();
    gameover();
    you_won(3);
}


