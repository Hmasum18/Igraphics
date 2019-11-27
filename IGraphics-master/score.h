#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED



#endif // SCORE_H_INCLUDED
//extern int time_bonus,level_time,life,level_cnt;
#pragma comment(lib, "variable.h")
//extern scoring score;
extern int gameover();
extern int you_won(int );


void scoring_sytem_1() ///called by is_hit_ball()
{
    score.ball+=20;///update score
}
void scoring_sytem_2() ///called by you_won()
{
     score.time=(time_bonus-level_time)>0 ? (time_bonus-level_time):0;
    ///score on remaning time
    if(gameover()) score.time=0;
    score.life=life*10;
}
void highest_score_system()
{
     int num=0;
    FILE *fp;
    fp=fopen("highest_score.txt","r");
    while(fscanf(fp,"%s %d",&scores[num].pname,&scores[num].pscore)!=EOF)
        num++;
    fclose(fp);
    //printf("%d\n",num);
   /* for(int i=0;i<num;i++)
    {
            printf("%s %d\n",scores[i].pname,scores[i].pscore);
    }*/
    for(int i=0;i<num-1;i++)
    {
        for(int j=0;j<num-i-1;j++)
        {
            player temp;
            if(scores[j].pscore<scores[j+1].pscore)
            {
                temp=scores[j];
                scores[j]=scores[j+1];
                scores[j+1]=temp;
            }

        }
    }
   /* for(int i=0;i<num;i++)
    {
            printf("%s %d\n",scores[i].pname,scores[i].pscore);
    }*/
    fp=fopen("highest_score.txt","w");
    for(int i=0;i<5;i++)
    {
        fprintf(fp,"%s %d\n",scores[i].pname,scores[i].pscore);
    }
    fclose(fp);
}

void leader_board()
{
    highest_score_system();
    iShowBMP(0,0,"bgimage\\leaderBoard.bmp");
    int h=400;
    char num[20],ch[20];
    iSetColor(255,0,0);
    int y[5]={347,273,197,122,49};
    ///new codeg
    ///show grandmaster name
    iRectangle(28,298,250,50);
    strupr(scores[0].pname);
    iText(32,312,scores[0].pname,GLUT_BITMAP_TIMES_ROMAN_24);
    ///show the leader board
    for(int i=0;i<5;i++)
    {
        strupr(scores[i].pname); ///printf the playername in upercase
        iText(600,y[i],scores[i].pname,GLUT_BITMAP_TIMES_ROMAN_24);
        char score[20];
        itoa(scores[i].pscore,score,10);
        if(scores[i].pscore) iText(850,y[i],score,GLUT_BITMAP_TIMES_ROMAN_24);
    }
   // iRectangle()
}
