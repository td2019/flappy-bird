#include "scoreboard.h"
#include"widget.h"
ScoreBoard::ScoreBoard()
{
    auto & p=Res::User;
    layer=LAYER_TOP-1;
    over=p->res->nullimg;
    board=&p->res->score_board;
    x_over=p->width()/2;
    y_over=p->height()/2-185;
    x_board=x_over;
    x_play=x_board;
    y_play=p->height()-230;
    y_board=p->height()+35;
    p->AddToSubThread(layer,this);

}

void ScoreBoard::frame()
{
    if(timer>=30&&timer<40)
    {
        over=Res::User->tools->SetAlgha(Res::User->res->game_over,15+24*(timer-30));
        y_over=Res::User->height()/2-150+(timer-35)*(timer-35)*0.5;
    }
    else if(timer>60&&timer<=102)
    {
         y_board-=10;
    }
    else if(timer>130&&timer<=170)
    {
        play=Res::User->tools->SetAlgha(Res::User->res->button_play,15+6*(timer-130));
    }
    else if(timer>170)
        task=false;
    if(timer>110&&timer2<30)
    {
        timer2++;
    }
    timer++;
}

void ScoreBoard::show(QPainter & p)
{
    if(timer>30)
    {
        Res::User->tools->DrawPixmapAtCenter(x_over,y_over,over,p);
    }
    if(timer>60)
    {
        Res::User->tools->DrawPixmapAtCenter(x_board,y_board,*board,p);
    }
    if(timer>130)
    {
        Res::User->tools->DrawPixmapAtCenter(x_play,y_play,play,p);
    }
    if(timer>110)
    {
        Res::User->socre->ShowResult(p);
    }
}

void ScoreBoard::gameover()
{
    return;
}

void ScoreBoard::restart()
{
    del_flag=true;
}