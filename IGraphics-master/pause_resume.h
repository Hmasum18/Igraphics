#ifndef PAUSE_RESUME_H_INCLUDED
#define PAUSE_RESUME_H_INCLUDED



#endif // PAUSE_RESUME_H_INCLUDED
#pragma comment(lib, "variable.h")
//extern int gameover();
//extern int you_won(int);
void pause_game()
{
    iPauseTimer(0); ///ball_0
    iPauseTimer(1); ///ball_1
    iPauseTimer(2); ///ball_2
    iPauseTimer(4); ///level_time
}
void resume_game()
{
    iResumeTimer(0); ///ball_0
    iResumeTimer(1); ///ball_1
    iResumeTimer(2); ///ball_2
    iResumeTimer(4);///level_time
}
void pause_resume()
{
        if(pause&&!gameover()&&!you_won(level_cnt))
        {
           // printf("ok\n");
            pause_game();
            //iShowBMP2(350,200,"menu\\resume1.bmp",170);
            //iShowBMP2(455,195,"menu\\sweethome.bmp",170);
           if(!click_leader)
           {
               if(sound_mode) ///if sound is on
                    iShowBMP2(300,205,"menu\\pause_ball.bmp",170);
               if(!sound_mode)
                    iShowBMP2(300,205,"menu\\pause_ball1.bmp",170);
           }
        }
        else if(level_cnt>0&&!pause&&!gameover()&&!you_won(level_cnt))
        {
             //printf("ok\n");
            resume_game();
            if(level_cnt==1)
            {
                iPauseTimer(2);
              iSetColor(255,255,255);  if(!ball[0].show) iPauseTimer(0);
                if(!ball[1].show) iPauseTimer(1);
            }
            if(level_cnt==2)
            {
                iPauseTimer(1);
                if(!ball[0].show) iPauseTimer(0);
                if(!ball[2].show) iPauseTimer(2);
            }
             if(level_cnt==3)
            {
               // pause_game();
                if(!ball[0].show) iPauseTimer(0);
                if(!ball[1].show) iPauseTimer(1);
                if(!ball[2].show) iPauseTimer(2);
            }
        }
        //iText(10, 10, "Press p for pause, r for resume, END for exit.");
}
