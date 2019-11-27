#ifndef SHOW_H_INCLUDED
#define SHOW_H_INCLUDED



#endif // SHOW_H_INCLUDED
#pragma comment(lib, "variable.h")
//extern int level_time,ball_come,name_come;
//extern menus menu;
//extern scoring scor;
extern void pause_game();
extern void leader_board();
extern void highest_score_system();
void show_score()
{
    char scr[100];
    strcpy(scr,"YOUR SCORE: ");
    char ch[10];
    score.total=score.ball+score.time+score.life;
    itoa(score.total+score.previous,ch,10); ///converts integer to string
    strcat(scr,ch);
    iSetColor(0,0,0);
    iText(0,480,scr,GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,255,255);
}
void show_level_time()
{
    char mint[10],sec[10];
    char time[100]="Time : ";
    int temp=level_time/60;
   // printf("%d\n",temp);
    itoa(temp,mint,10);
    strcat(mint," min ");
    strcat(time,mint);
   // puts(mint);

    temp=level_time%60;
    itoa(temp,sec,10);
    strcat(time,sec);
    strcat(time," sec");

    iSetColor(0,0,0);
    iText(760,435,time,GLUT_BITMAP_TIMES_ROMAN_24);
   // puts(time);
    iSetColor(255,255,255);
}
void show_ball_number()
{
    char ch[10];
    itoa(ball_num,ch,10);
    char time[]="Ball Remaining: ";
    strcat(time,ch);
    iSetColor(0,0,0);
    iText(0,425,time,GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,255,255);
}

void show_menu()
{
    iShowBMP(0,0,"bgimage\\menu_final.bmp");
    iShowBMP2(drag.ball,330,"menu\\ball1.bmp",170);
    iShowBMP2(drag.game,265,"menu\\game_name_2.bmp",255);

    iShowBMP2(drag.start,380,"menu\\start_game.bmp",96);
    iShowBMP2(drag.leader,280,"menu\\leaderBoard.bmp",96);
    iShowBMP2(drag.instruction,180,"menu\\instructions.bmp",96);
    if(!sound_mode)  iShowBMP2(drag.sound,80,"menu\\sound_off.bmp",96);
    if(sound_mode) iShowBMP2(drag.sound,80,"menu\\sound_on.bmp",96);

    pause_game();
    if(menu.leader_board) leader_board();
    if(menu.credit)
    {
        iShowBMP(0,0,"bgimage\\credit.bmp");
    }
    if(menu.instruction)
    {
        iShowBMP(0,0,"bgimage\\instruction.bmp");
    }

        //iText(180,225,"new game",GLUT_BITMAP_TIMES_ROMAN_24);
}


void show_final_score()
{
        iShowBMP(0,0,"bgimage\\score_board.bmp");
        //iSetColor(255,255,255);
        //iFilledRectangle(100,100,400,400);
        int temp=410;
        iSetColor(63,72,204);
        char sc[10];

        iText(temp+50,350,"\"SCORE BOARD\"",GLUT_BITMAP_TIMES_ROMAN_24);

        itoa(score.ball,sc,10);
        iText(temp,300,"BALL SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(temp+200,300,sc,GLUT_BITMAP_TIMES_ROMAN_24);

        itoa(score.time,sc,10);
        iText(temp,270,"TIME BONUS:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(temp+200,270,sc,GLUT_BITMAP_TIMES_ROMAN_24);

        itoa(life,sc,10);
        strcat(sc,"*10");
        iText(temp,240,"LIFE BONUS: ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(temp+200,240,sc,GLUT_BITMAP_TIMES_ROMAN_24);

        itoa(score.previous,sc,10);
        iText(temp,210,"PRE SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(temp+200,210,sc,GLUT_BITMAP_TIMES_ROMAN_24);

        iLine(temp,190,700,190);

        score.final_score=score.total+score.previous;
        itoa(score.final_score,sc,10);
        iText(temp,160,"YOU SCORED:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(temp+200,160,sc,GLUT_BITMAP_TIMES_ROMAN_24);
}
void show_higest_score()
{
    highest_score_system();
    char s[10];
    itoa(scores[0].pscore,s,10);
    char hscore[]="HIGHEST SCORE :";
    strcat(hscore,s);
    iSetColor(0,0,0);
    iText(0,450,hscore,GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,255,255);
}
