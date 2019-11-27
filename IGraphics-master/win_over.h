#ifndef WIN_OVER_H_INCLUDED
#define WIN_OVER_H_INCLUDED



#endif // WIN_OVER_H_INCLUDED
#pragma comment(lib, "variable.h")
extern void resume_game();
extern void pause_game();
extern void show_final_score();
extern void scoring_sytem_1();
extern void scoring_sytem_2();
extern void after_you_won();
int gameover() ///called by all level
{
    if(!life)     ///if we dont have any life
    {
        pause_game(); ///game is paused
        iSetColor(255,0,0);
        iSetColor(255, 255, 255);
        //score.total=score.total+score.previous;

        return 1;
    }
    else return 0;
}

///new code
void player_name_input()
{
        if(!nameinput&&gameover()) iShowBMP2(scr_x-200,30,"menu\\home.bmp",170);
        if(!nameinput&&mission_accomplished) iShowBMP2(scr_x-200,30,"menu\\home.bmp",170);
        if(nameinput==1)
        {
            iShowBMP(0,0,"bgimage\\wall.bmp");
            iShowBMP2(drag.new_highest_score,300,"bgimage\\new_highest_score.bmp",96);
            iShowBMP2(drag.enter_name,230,"bgimage\\enter_name.bmp",96);
            iSetColor(255,255,255);
            //iFilledRectangle(0,0,970,508);
            //iSetColor(0,0,0);
            if(drag.enter_name>=260) iFilledRectangle(280,150,448,50);
            iSetColor(170,0,0);
            strupr(playername);
            iText(285,165,playername,GLUT_BITMAP_TIMES_ROMAN_24);
        }
}

void after_gameover()
{
    iShowBMP2(280,120,"menu\\fail2.bmp",170); ///shows fail picture
    if(after_over==2) ///wait for 3 second
    {
        show_final_score(); ///show the final score board
        player_name_input(); ///if score is greater then lowest highest score input the player_name
    }
}
void after_you_won() ///call by you_won() function
{
    if(after_won==3)
    {
        show_final_score();
        player_name_input();
        if(level_cnt!=3) iShowBMP2(scr_x-150,30,"menu\\next1.bmp",0);
    }
}

int you_won(int lvl) ///callled by all level
{
    if(lvl==3)
    {
        if(!ball[0].show&&!ball[1].show&&!ball[2].show)
        {
            pause_game();

            mission_accomplished=1;
            if(!chk_score) scoring_sytem_2(),chk_score=1;
           // score.total=score.total+score.previous;
            iSetColor(255,0,0);
            iShowBMP2(240,130,"menu\\mission_accomplished.bmp",170);
            after_you_won();
            return 1;
        }
        else return 0;
    }
    else if(lvl==1|| lvl==2)
    {
        if(ball[lvl].show==0&&ball[0].show==0)/// if all the balls are hit
        {
            pause_game(); ///pause the game
            if(!chk_score) scoring_sytem_2(),chk_score=1; ///score on remaning time just for 1 time...as the fucntions are called recursively
            iSetColor(255,0,0);
            iShowBMP2(270,200,"menu\\levelup.bmp",170); ///shows the levelup picture
            after_you_won();

            iSetColor(255, 255, 255);
            return 1;
        }
        else return 0;
    }
}

