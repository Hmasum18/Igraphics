#ifndef HIT_H_INCLUDED
#define HIT_H_INCLUDED



#endif // HIT_H_INCLUDED
#pragma comment(lib, "variable.h")
#pragma comment(lib, "win_over.h"
extern void make_ball(int ,int);
extern void is_shoot();

int if_hit_man(int i) ///called by all ball changer to count and show life
{
    if(!you_won(level_cnt)||!gameover())
    if(ball[i].x>man_x-30&&ball[i].x<man_x+36&&ball[i].y<=line[level_cnt]+56)
    {
        if(i==2) ball[i].x=scr_x-30,ball[i].y=man_y;
        else ball[i].x=0,ball[i].y=man_y;
        return 1;
    }
     return 0;
}
void is_hit_ball(int n) ///called by all level funtion to check is the ball is hit by an arrow
{
    for(int i=0;i<100;i++)
    {
        if(gameover()) continue; ///when game is over then don't allow to hit the ball
        if(arw[i].is_sht&&ball[n].show) ///if arrow is shot and ball is still in the game
        {
            if(arw[i].x>=ball[n].x-15&&arw[i].x<=ball[n].x+10&&arw[i].y+86>=ball[n].y&&arw[i].y<=ball[n].y+30)
            {
                scoring_sytem_1(); ///udate score

                ///if else just fixing the direction of the ball movement
                if(ball_num&1)   ///BALL NUMBER IS ODD
                {
                    if(n==0) ball[0].x=0,ball[0].y=line[level_cnt];
                    else if(n==1) ball[1].x=0,ball[1].y=line[level_cnt];
                    else if(n==2)  ball[2].x=scr_x-30,ball[2].y=line[level_cnt];
                }
                else
                {
                    if(n==0) ball[0].x=scr_x-30,ball[0].y=line[level_cnt];
                    else if(n==1) ball[1].x=scr_x-30,ball[1].y=line[level_cnt];
                    else if(n==2)  ball[2].x=0,ball[2].y=line[level_cnt];
                }



                if(level_cnt!=3) if(ball_num<3) ball[n].show=0; ///vanish the balls
                if(level_cnt==3) if(ball_num<4) ball[n].show=0; ///hide the ball after being hit by the arrow
                ball_num--;

            }
               // iPauseTimer(n);
        }
    }
}

