#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include "iGraphics.h"
#pragma comment(lib, "winmm.lib")

int current;
int gamestep;
int block1;
int block2;
int block3;
int block4;
int block5;
int block6;
int block7;
int block8;
int block9;
int gamedone = 0;
int winner = 0;
int turn;
bool sound = true;
int difficulty;
int tossvariable = -1;
int auxilary = 0;
int data = 0;
int match;
int win;
double percentage;

char string[3];

void feature()
{

       FILE *ptr;
       ptr = fopen("match.txt", "r");
       fscanf(ptr, "%d", &match);
       fclose(ptr);
       FILE *ptr2;
       ptr2 = fopen("win.txt", "r");
       fscanf(ptr2, "%d", &win);
       fclose(ptr2);
       percentage = ((win * 100.0) / match);
       if (gamedone == 0)
              sprintf(string, "%lf", percentage);
       // itoa(percentage, string, 10);
       if (gamedone != 0)
       {
              ptr = fopen("match.txt", "w");
              match++;
              fprintf(ptr, "%d", match);
              fclose(ptr);
              if (winner == 2)
              {
                     ptr2 = fopen("win.txt", "w");
                     win++;
                     percentage = ((win * 100.0) / match);
                     fprintf(ptr2, "%d", win);
                     fclose(ptr2);
              }
              percentage = ((win * 100.0) / match);
              sprintf(string, "%lf", percentage);
       }
}

void toss()
{

       if (tossvariable == 0)
       {
              tossvariable = 1;
       }
       else if (tossvariable == 1)
       {
              tossvariable = 2;
       }
       else if (tossvariable == 2)
       {
              tossvariable = 3;
       }
       else if (tossvariable == 3)
       {
              tossvariable = 4;
       }
       else if (tossvariable == 4)
       {
              tossvariable = 5;
       }
       else if (tossvariable == 5)
       {
              tossvariable = 6;
       }
       else if (tossvariable == 6)
       {
              tossvariable = 9;
       }
       else if (tossvariable == 9)
       {
              tossvariable = 10;
       }
       else if (tossvariable == 10)
       {
              tossvariable = 11;
       }
       else if (tossvariable == 11)
       {
              tossvariable = 12;
       }
       else if (tossvariable == 12)
       {
              tossvariable = 13;
       }
       else if (tossvariable == 13)
       {
              tossvariable = 14;
       }
       else if (tossvariable == 14)
       {
              tossvariable = 15;
       }
       else if (tossvariable == 15)
       {
              tossvariable = 16;
       }
       else if (tossvariable == 16)
       {
              tossvariable = 17;
       }
       else if (tossvariable == 17)
       {
              tossvariable = 18;
       }
       else if (tossvariable == 18)
       {
              tossvariable = 19;
       }
       else if (tossvariable == 19)
       {
              tossvariable = 20;
       }
       else if (tossvariable == 20 && auxilary == 1)
       {
              tossvariable = 7;
       }
       else if (tossvariable == 20 && auxilary == 2)
       {
              tossvariable = 8;
       }
       else if (tossvariable == 7)
       {
              sleep(2);
              tossvariable = -1;
              current = 2;
              turn = 1;
       }
       else if (tossvariable == 8)
       {
              sleep(2);
              tossvariable = -1;
              current = 2;
              turn = 2;
              data = 1;
       }
}

void music()
{

       if (sound == true)
       {
              PlaySound("home.wav", NULL, SND_LOOP | SND_ASYNC);
       }
       else
       {
              PlaySound(0, 0, 0);
       }
}

void iDraw()
{

       // printf("match=%d win=%d percentage=%s\n",match,win,string);

       iClear();

       if (sound == true && data == 1)
       {
              PlaySound("move.wav", NULL, SND_ASYNC);
              data = 0;
       }

       // printf("%d", current); // printf ("gamedone=%d gamestep=%d\n", gamedone, gamestep);

       if (current == 0)
       {

              iShowBMP(0, 0, "tictactoe3options.bmp");
              iShowBMP2(600, 75, "settings.bmp", 0);
       }

       else if (current == 333 && (tossvariable == 1 || tossvariable == 9 || tossvariable == 15))
       {

              iShowBMP(0, 0, "maintoss.bmp");
              if (auxilary == 1)
              {

                     if (tossvariable == 1 || tossvariable == 15)
                     {
                            iShowBMP2(0, 0, "aitoss.bmp", 0);
                     }
                     else
                     {
                            iShowBMP2(0, 0, "youtoss.bmp", 0);
                     }
              }

              else
              {

                     if (tossvariable == 1 || tossvariable == 15)
                     {
                            iShowBMP2(0, 0, "youtoss.bmp", 0);
                     }
                     else
                     {
                            iShowBMP2(0, 0, "aitoss.bmp", 0);
                     }
              }
       }
       else if (current == 333 && (tossvariable == 2 || tossvariable == 10 || tossvariable == 16))
       {
              iShowBMP(0, 0, "maintoss.bmp");
              iShowBMP2(0, 0, "2.bmp", 0);
       }
       else if (current == 333 && (tossvariable == 3 || tossvariable == 11 || tossvariable == 17))
       {
              iShowBMP(0, 0, "maintoss.bmp");
              iShowBMP2(0, 0, "3.bmp", 0);
       }
       else if (current == 333 && (tossvariable == 4 || tossvariable == 12 || tossvariable == 18))
       {
              iShowBMP(0, 0, "maintoss.bmp");
              iShowBMP2(0, 0, "4.bmp", 0);
       }
       else if (current == 333 && (tossvariable == 5 || tossvariable == 13 || tossvariable == 19))
       {
              iShowBMP(0, 0, "maintoss.bmp");
              iShowBMP2(0, 0, "5.bmp", 0);
       }
       else if (current == 333 && (tossvariable == 6 || tossvariable == 14 || tossvariable == 20))
       {
              iShowBMP(0, 0, "maintoss.bmp");
              iShowBMP2(0, 0, "6.bmp", 0);
       }
       else if (current == 333 && tossvariable == 7)
       {
              iShowBMP(0, 0, "maintoss.bmp");
              iShowBMP2(0, 0, "youtoss.bmp", 0);
       }
       else if (current == 333 && tossvariable == 8)
       {
              iShowBMP(0, 0, "maintoss.bmp");
              iShowBMP2(0, 0, "aitoss.bmp", 0);
       }

       else if (current == 333)
       {
              iShowBMP(0, 0, "blur.bmp");
       }

       else if (current == 4)
       {

              if (sound)
              {
                     iShowBMP(0, 0, "settingspageon.bmp");
              }
              else
              {
                     iShowBMP(0, 0, "settingspageoff.bmp");
              }
              if (difficulty == 1)
              {
                     iShowBMP(920, 200, "easy.bmp");
              }
              if (difficulty == 2)
              {
                     iShowBMP(920, 200, "medium.bmp");
              }
              if (difficulty == 3)
              {
                     iShowBMP(922, 202, "hard.bmp");
              }
       }

       else if (current == 1)
       {
              iSetColor(255, 255, 255);
              iShowBMP(0, 0, "game.bmp");
              iShowBMP(0, 0, "back.bmp");
              iShowBMP(960, 0, "exit.bmp");

              if (block1 == 1)
              {
                     iShowBMP2(375, 490, "cross.bmp", 0);
              }
              if (block2 == 1)
              {
                     iShowBMP2(560, 490, "cross.bmp", 0);
              }
              if (block3 == 1)
              {
                     iShowBMP2(740, 490, "cross.bmp", 0);
              }
              if (block4 == 1)
              {
                     iShowBMP2(375, 310, "cross.bmp", 0);
              }
              if (block5 == 1)
              {
                     iShowBMP2(560, 310, "cross.bmp", 0);
              }
              if (block6 == 1)
              {
                     iShowBMP2(745, 310, "cross.bmp", 0);
              }
              if (block7 == 1)
              {
                     iShowBMP2(380, 125, "cross.bmp", 0);
              }
              if (block8 == 1)
              {
                     iShowBMP2(560, 125, "cross.bmp", 0);
              }
              if (block9 == 1)
              {
                     iShowBMP2(745, 125, "cross.bmp", 0);
              }
              if (block1 == 2)
              {
                     iShowBMP2(375, 490, "circle.bmp", 0);
              }
              if (block2 == 2)
              {
                     iShowBMP2(560, 490, "circle.bmp", 0);
              }
              if (block3 == 2)
              {
                     iShowBMP2(745, 490, "circle.bmp", 0);
              }
              if (block4 == 2)
              {
                     iShowBMP2(375, 310, "circle.bmp", 0);
              }
              if (block5 == 2)
              {
                     iShowBMP2(560, 310, "circle.bmp", 0);
              }
              if (block6 == 2)
              {
                     iShowBMP2(745, 310, "circle.bmp", 0);
              }
              if (block7 == 2)
              {
                     iShowBMP2(375, 125, "circle.bmp", 0);
              }
              if (block8 == 2)
              {
                     iShowBMP2(560, 125, "circle.bmp", 0);
              }
              if (block9 == 2)
              {
                     iShowBMP2(745, 125, "circle.bmp", 0);
              }

              if (gamedone == 0 && gamestep % 2 == 0)
              {
                     iShowBMP(565, 0, "x'sturn.bmp");
              }
              if (gamedone == 0 && gamestep % 2 == 1)
              {
                     iShowBMP(565, 0, "o'sturn.bmp");
              }

              if (gamedone == 1 && gamestep % 2 == 1)
              {
                     iShowBMP2(355, 130, "vertical.bmp", 0);
                     iShowBMP(478, 20, "xwon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 2 && gamestep % 2 == 1)
              {
                     iShowBMP2(540, 130, "vertical.bmp", 0);
                     iShowBMP(478, 20, "xwon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 3 && gamestep % 2 == 1)
              {
                     iShowBMP2(725, 130, "vertical.bmp", 0);
                     iShowBMP(478, 20, "xwon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 1 && gamestep % 2 == 0)
              {
                     iShowBMP2(370, 129, "vertical.bmp", 0);
                     iShowBMP(478, 20, "owon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 2 && gamestep % 2 == 0)
              {
                     iShowBMP2(555, 129, "vertical.bmp", 0);
                     iShowBMP(478, 20, "owon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 3 && gamestep % 2 == 0)
              {
                     iShowBMP2(740, 129, "vertical.bmp", 0);
                     iShowBMP(478, 20, "owon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 4 && gamestep % 2 == 1)
              {
                     iShowBMP2(370, 490, "horizontal.bmp", 0);
                     iShowBMP(513, 20, "xwon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 5 && gamestep % 2 == 1)
              {
                     iShowBMP2(370, 310, "horizontal.bmp", 0);
                     iShowBMP(478, 20, "xwon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 6 && gamestep % 2 == 1)
              {
                     iShowBMP2(370, 130, "horizontal.bmp", 0);
                     iShowBMP(478, 20, "xwon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 4 && gamestep % 2 == 0)
              {
                     iShowBMP2(379, 495, "horizontal.bmp", 0);
                     iShowBMP(478, 20, "owon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 5 && gamestep % 2 == 0)
              {
                     iShowBMP2(379, 315, "horizontal.bmp", 0);
                     iShowBMP(478, 20, "owon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 6 && gamestep % 2 == 0)
              {
                     iShowBMP2(379, 135, "horizontal.bmp", 0);
                     iShowBMP(478, 20, "owon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 7 && gamestep % 2 == 1)
              {
                     iShowBMP2(380, 115, "oblique.bmp", 0);
                     iShowBMP(478, 20, "xwon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 7 && gamestep % 2 == 0)
              {
                     iShowBMP2(385, 115, "oblique.bmp", 0);
                     iShowBMP(478, 20, "owon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 8 && gamestep % 2 == 1)
              {
                     iShowBMP2(377, 115, "oblique2.bmp", 0);
                     iShowBMP(478, 20, "xwon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
              if (gamedone == 8 && gamestep % 2 == 0)
              {
                     iShowBMP2(390, 125, "oblique2.bmp", 0);
                     iShowBMP(478, 20, "owon.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }

              if (gamedone == 10)
              {
                     iShowBMP(513, 20, "draw.bmp");
                     iShowBMP(738, 20, "replay.bmp");
              }
       }

       else if (current == 2)
       {

              if (turn == 1)
              {

                     iSetColor(255, 255, 255);
                     iShowBMP(0, 0, "game.bmp");
                     iShowBMP(0, 0, "back.bmp");
                     iShowBMP(960, 0, "exit.bmp");

                     if (block1 == 1)
                     {
                            iShowBMP2(375, 490, "cross.bmp", 0);
                     }
                     if (block2 == 1)
                     {
                            iShowBMP2(560, 490, "cross.bmp", 0);
                     }
                     if (block3 == 1)
                     {
                            iShowBMP2(740, 490, "cross.bmp", 0);
                     }
                     if (block4 == 1)
                     {
                            iShowBMP2(375, 310, "cross.bmp", 0);
                     }
                     if (block5 == 1)
                     {
                            iShowBMP2(560, 310, "cross.bmp", 0);
                     }
                     if (block6 == 1)
                     {
                            iShowBMP2(745, 310, "cross.bmp", 0);
                     }
                     if (block7 == 1)
                     {
                            iShowBMP2(380, 125, "cross.bmp", 0);
                     }
                     if (block8 == 1)
                     {
                            iShowBMP2(560, 125, "cross.bmp", 0);
                     }
                     if (block9 == 1)
                     {
                            iShowBMP2(745, 125, "cross.bmp", 0);
                     }

                     if (block1 == 2)
                     {
                            iShowBMP2(375, 490, "circle.bmp", 0);
                     }
                     if (block2 == 2)
                     {
                            iShowBMP2(560, 490, "circle.bmp", 0);
                     }
                     if (block3 == 2)
                     {
                            iShowBMP2(745, 490, "circle.bmp", 0);
                     }
                     if (block4 == 2)
                     {
                            iShowBMP2(375, 310, "circle.bmp", 0);
                     }
                     if (block5 == 2)
                     {
                            iShowBMP2(560, 310, "circle.bmp", 0);
                     }
                     if (block6 == 2)
                     {
                            iShowBMP2(745, 310, "circle.bmp", 0);
                     }
                     if (block7 == 2)
                     {
                            iShowBMP2(375, 125, "circle.bmp", 0);
                     }
                     if (block8 == 2)
                     {
                            iShowBMP2(560, 125, "circle.bmp", 0);
                     }
                     if (block9 == 2)
                     {
                            iShowBMP2(745, 125, "circle.bmp", 0);
                     }

                     if (gamedone == 0)
                     {
                            iShowBMP(565, 0, "youvsai.bmp");
                     }

                     if (gamedone == 1 && winner == 2)
                     {
                            iShowBMP2(355, 130, "vertical.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 2 && winner == 2)
                     {
                            iShowBMP2(540, 130, "vertical.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 3 && winner == 2)
                     {
                            iShowBMP2(725, 130, "vertical.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 4 && winner == 2)
                     {
                            iShowBMP2(379, 495, "horizontal.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 5 && winner == 2)
                     {
                            iShowBMP2(379, 315, "horizontal.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 6 && winner == 2)
                     {
                            iShowBMP2(379, 135, "horizontal.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 7 && winner == 2)
                     {
                            iShowBMP2(385, 115, "oblique.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 8 && winner == 2)
                     {
                            iShowBMP2(379, 125, "oblique2.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 10)
                     {
                           // printf("winner=%d\n", winner);
                            iShowBMP(478, 20, "draw.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 1 && winner == 1)
                     {
                            iShowBMP2(355, 130, "vertical.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 2 && winner == 1)
                     {
                            iShowBMP2(540, 130, "vertical.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 3 && winner == 1)
                     {
                            iShowBMP2(725, 130, "vertical.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 4 && winner == 1)
                     {
                            iShowBMP2(370, 490, "horizontal.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 5 && winner == 1)
                     {
                            iShowBMP2(370, 310, "horizontal.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 6 && winner == 1)
                     {
                            iShowBMP2(370, 130, "horizontal.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 7 && winner == 1)
                     {
                            iShowBMP2(380, 115, "oblique.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 8 && winner == 1)
                     {
                            iShowBMP2(377, 115, "oblique2.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
              }

              else if (turn == 2)
              {

                     iSetColor(255, 255, 255);
                     iShowBMP(0, 0, "game.bmp");
                     iShowBMP(0, 0, "back.bmp");
                     iShowBMP(960, 0, "exit.bmp");

                     if (block1 == 1)
                     {
                            iShowBMP2(375, 490, "cross.bmp", 0);
                     }
                     if (block2 == 1)
                     {
                            iShowBMP2(560, 490, "cross.bmp", 0);
                     }
                     if (block3 == 1)
                     {
                            iShowBMP2(740, 490, "cross.bmp", 0);
                     }
                     if (block4 == 1)
                     {
                            iShowBMP2(375, 310, "cross.bmp", 0);
                     }
                     if (block5 == 1)
                     {
                            iShowBMP2(560, 310, "cross.bmp", 0);
                     }
                     if (block6 == 1)
                     {
                            iShowBMP2(745, 310, "cross.bmp", 0);
                     }
                     if (block7 == 1)
                     {
                            iShowBMP2(380, 125, "cross.bmp", 0);
                     }
                     if (block8 == 1)
                     {
                            iShowBMP2(560, 125, "cross.bmp", 0);
                     }
                     if (block9 == 1)
                     {
                            iShowBMP2(745, 125, "cross.bmp", 0);
                     }

                     if (block1 == 2)
                     {
                            iShowBMP2(375, 490, "circle.bmp", 0);
                     }
                     if (block2 == 2)
                     {
                            iShowBMP2(560, 490, "circle.bmp", 0);
                     }
                     if (block3 == 2)
                     {
                            iShowBMP2(745, 490, "circle.bmp", 0);
                     }
                     if (block4 == 2)
                     {
                            iShowBMP2(375, 310, "circle.bmp", 0);
                     }
                     if (block5 == 2)
                     {
                            iShowBMP2(560, 310, "circle.bmp", 0);
                     }
                     if (block6 == 2)
                     {
                            iShowBMP2(745, 310, "circle.bmp", 0);
                     }
                     if (block7 == 2)
                     {
                            iShowBMP2(375, 125, "circle.bmp", 0);
                     }
                     if (block8 == 2)
                     {
                            iShowBMP2(560, 125, "circle.bmp", 0);
                     }
                     if (block9 == 2)
                     {
                            iShowBMP2(745, 125, "circle.bmp", 0);
                     }

                     if (gamedone == 0)
                     {
                            iShowBMP(565, 0, "youvsai.bmp");
                     }

                     if (gamedone == 1 && winner == 2)
                     {
                            iShowBMP2(355, 130, "vertical.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 2 && winner == 2)
                     {
                            iShowBMP2(540, 130, "vertical.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 3 && winner == 2)
                     {
                            iShowBMP2(725, 130, "vertical.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 4 && winner == 2)
                     {
                            iShowBMP2(379, 495, "horizontal.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 5 && winner == 2)
                     {
                            iShowBMP2(379, 315, "horizontal.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 6 && winner == 2)
                     {
                            iShowBMP2(379, 135, "horizontal.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 7 && winner == 2)
                     {
                            iShowBMP2(385, 115, "oblique.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 8 && winner == 2)
                     {
                            iShowBMP2(379, 125, "oblique2.bmp", 0);
                            iShowBMP(478, 20, "aiwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 10)
                     {
                            iShowBMP(478, 20, "draw.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 1 && winner == 1)
                     {
                            iShowBMP2(340, 130, "vertical.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 2 && winner == 1)
                     {
                            iShowBMP2(540, 130, "vertical.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 3 && winner == 1)
                     {
                            iShowBMP2(725, 130, "vertical.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 4 && winner == 1)
                     {
                            iShowBMP2(370, 490, "horizontal.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 5 && winner == 1)
                     {
                            iShowBMP2(370, 310, "horizontal.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 6 && winner == 1)
                     {
                            iShowBMP2(370, 130, "horizontal.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 7 && winner == 1)
                     {
                            iShowBMP2(380, 115, "oblique.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
                     if (gamedone == 8 && winner == 1)
                     {
                            iShowBMP2(377, 115, "oblique2.bmp", 0);
                            iShowBMP(478, 20, "youwon.bmp");
                            iShowBMP(738, 20, "replay.bmp");
                     }
              }

              iSetColor(0, 0, 0);
              iText(490, 700, "AI has won ", GLUT_BITMAP_TIMES_ROMAN_24);
              iText(610, 700, string, GLUT_BITMAP_TIMES_ROMAN_24);
              iText(655, 700, "% times till now", GLUT_BITMAP_TIMES_ROMAN_24);
       }
       else if (current == 3)
       {

              exit(0);
       }
}

void iMouseMove(int mx, int my)
{

       ;
}

void iMouse(int button, int state, int mx, int my)
{

       //printf("x=%d y=%d\n", mx, my);

       if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
       {

              if (current == 0)
              {

                     if (mx >= 320 && mx <= 520 && my >= 230 && my <= 270)
                     {
                            current = 1;
                            PlaySound(0, 0, 0);
                     }
                     else if (mx >= 540 && mx <= 740 && my >= 230 && my <= 270)
                     {
                            current = 333;
                            PlaySound(0, 0, 0);
                     }
                     else if (mx >= 760 && mx <= 960 && my >= 230 && my <= 270)
                     {
                            current = 3;
                     }
                     else if (mx >= 600 && mx <= 655 && my >= 95 && my <= 140)
                     {
                            current = 4;
                     }
              }

              else if (current == 333)
              {

                     if (mx >= 400 && mx <= 420 && my >= 370 && my <= 385)
                     {
                            current = 2;
                            turn = 1;
                     }
                     else if (mx >= 620 && mx <= 635 && my >= 370 && my <= 385)
                     {
                            current = 2;
                            turn = 2;

                            int numbergenerator = (rand() % 9) + 1;

                            usleep(300000);

                            if (numbergenerator == 1)
                            {
                                   block1 = 1;
                                   gamestep = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (numbergenerator == 2)
                            {
                                   block2 = 1;
                                   gamestep = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (numbergenerator == 3)
                            {
                                   block3 = 1;
                                   gamestep = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (numbergenerator == 4)
                            {
                                   block4 = 1;
                                   gamestep = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (numbergenerator == 5)
                            {
                                   block5 = 1;
                                   gamestep = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (numbergenerator == 6)
                            {
                                   block6 = 1;
                                   gamestep = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (numbergenerator == 7)
                            {
                                   block7 = 1;
                                   gamestep = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (numbergenerator == 8)
                            {
                                   block8 = 1;
                                   gamestep = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (numbergenerator == 9)
                            {
                                   block9 = 1;
                                   gamestep = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                     }
                     else if (mx >= 805 && mx <= 825 && my >= 370 && my <= 385)
                     {

                            int num = rand() % 2 + 1;

                            if (sound == true)
                            {
                                   PlaySound("toss.wav", NULL, SND_ASYNC);
                            }

                            if (num == 1)
                            {
                                   auxilary = 1;
                                   tossvariable = 0;
                            }

                            else
                            {

                                   auxilary = 2;
                                   tossvariable = 0;
                                   int numbergenerator = (rand() % 9) + 1;

                                   if (numbergenerator == 1)
                                   {
                                          block1 = 1;
                                          gamestep = 1;
                                   }
                                   else if (numbergenerator == 2)
                                   {
                                          block2 = 1;
                                          gamestep = 1;
                                   }
                                   else if (numbergenerator == 3)
                                   {
                                          block3 = 1;
                                          gamestep = 1;
                                   }
                                   else if (numbergenerator == 4)
                                   {
                                          block4 = 1;
                                          gamestep = 1;
                                   }
                                   else if (numbergenerator == 5)
                                   {
                                          block5 = 1;
                                          gamestep = 1;
                                   }
                                   else if (numbergenerator == 6)
                                   {
                                          block6 = 1;
                                          gamestep = 1;
                                   }
                                   else if (numbergenerator == 7)
                                   {
                                          block7 = 1;
                                          gamestep = 1;
                                   }
                                   else if (numbergenerator == 8)
                                   {
                                          block8 = 1;
                                          gamestep = 1;
                                   }
                                   else if (numbergenerator == 9)
                                   {
                                          block9 = 1;
                                          gamestep = 1;
                                   }
                            }
                     }
              }
              else if (current == 1)
              {

                     if (mx >= 0 && mx <= 120 && my >= 685 && my <= 718)
                     {
                            current = 0;

                            gamestep = 0;
                            block1 = 0;
                            block2 = 0;
                            block3 = 0;
                            block4 = 0;
                            block5 = 0;
                            block6 = 0;
                            block7 = 0;
                            block8 = 0;
                            block9 = 0;
                            gamedone = 0;
                            if (sound == true)
                            {
                                   PlaySound("home.wav", NULL, SND_LOOP | SND_ASYNC);
                            }
                     }

                     if (gamedone != 0 && mx >= 738 && mx <= 808 && my >= 20 && my <= 90)
                     {

                            gamestep = 0;
                            block1 = 0;
                            block2 = 0;
                            block3 = 0;
                            block4 = 0;
                            block5 = 0;
                            block6 = 0;
                            block7 = 0;
                            block8 = 0;
                            block9 = 0;
                            gamedone = 0;
                     }
                     if (mx >= 1190 && mx <= 1280 && my >= 685 && my <= 718)
                     {
                            exit(0);
                     }

                     if (gamestep == 0)
                     {

                            if (mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block7 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block8 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block9 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block4 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block5 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block6 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block1 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block2 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block3 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                     }

                     else if (gamestep == 1)
                     {

                            if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block7 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block8 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block9 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block4 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block5 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block6 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block1 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block2 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block3 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                     }

                     else if (gamestep == 2)
                     {

                            if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block7 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block8 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block9 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block4 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block5 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block6 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block1 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block2 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block3 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                     }

                     else if (gamestep == 3)
                     {

                            if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block7 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block8 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block9 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block4 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block5 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block6 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block1 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block2 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block3 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                     }

                     else if (gamestep == 4)
                     {

                            if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block7 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block8 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block9 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block4 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block5 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block6 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block1 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block2 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block3 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }

                            if (block1 != 0 && block1 == block4 && block4 == block7)
                            {
                                   gamedone = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 != 0 && block2 == block5 && block5 == block8)
                            {
                                   gamedone = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 != 0 && block3 == block6 && block6 == block9)
                            {
                                   gamedone = 3;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 != 0 && block1 == block2 && block2 == block3)
                            {
                                   gamedone = 4;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 != 0 && block4 == block5 && block5 == block6)
                            {
                                   gamedone = 5;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block7 != 0 && block7 == block8 && block8 == block9)
                            {
                                   gamedone = 6;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 != 0 && block1 == block5 && block5 == block9)
                            {
                                   gamedone = 7;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 != 0 && block3 == block5 && block5 == block7)
                            {
                                   gamedone = 8;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                     }

                     else if (gamestep == 5 && gamedone == 0)
                     {

                            if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block7 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block8 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block9 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block4 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block5 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block6 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block1 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block2 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block3 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }

                            if (block1 != 0 && block1 == block4 && block4 == block7)
                            {
                                   gamedone = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 != 0 && block2 == block5 && block5 == block8)
                            {
                                   gamedone = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 != 0 && block3 == block6 && block6 == block9)
                            {
                                   gamedone = 3;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 != 0 && block1 == block2 && block2 == block3)
                            {
                                   gamedone = 4;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 != 0 && block4 == block5 && block5 == block6)
                            {
                                   gamedone = 5;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block7 != 0 && block7 == block8 && block8 == block9)
                            {
                                   gamedone = 6;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 != 0 && block1 == block5 && block5 == block9)
                            {
                                   gamedone = 7;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 != 0 && block3 == block5 && block5 == block7)
                            {
                                   gamedone = 8;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                     }

                     else if (gamestep == 6 && gamedone == 0)
                     {

                            if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block7 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block8 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block9 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block4 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block5 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block6 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block1 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block2 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block3 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }

                            if (block1 != 0 && block1 == block4 && block4 == block7)
                            {
                                   gamedone = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 != 0 && block2 == block5 && block5 == block8)
                            {
                                   gamedone = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 != 0 && block3 == block6 && block6 == block9)
                            {
                                   gamedone = 3;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 != 0 && block1 == block2 && block2 == block3)
                            {
                                   gamedone = 4;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 != 0 && block4 == block5 && block5 == block6)
                            {
                                   gamedone = 5;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block7 != 0 && block7 == block8 && block8 == block9)
                            {
                                   gamedone = 6;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 != 0 && block1 == block5 && block5 == block9)
                            {
                                   gamedone = 7;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 != 0 && block3 == block5 && block5 == block7)
                            {
                                   gamedone = 8;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                     }

                     else if (gamestep == 7 && gamedone == 0)
                     {

                            if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block7 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block8 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block9 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block4 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block5 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block6 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block1 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block2 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block3 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }

                            if (block1 != 0 && block1 == block4 && block4 == block7)
                            {
                                   gamedone = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 != 0 && block2 == block5 && block5 == block8)
                            {
                                   gamedone = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 != 0 && block3 == block6 && block6 == block9)
                            {
                                   gamedone = 3;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 != 0 && block1 == block2 && block2 == block3)
                            {
                                   gamedone = 4;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 != 0 && block4 == block5 && block5 == block6)
                            {
                                   gamedone = 5;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block7 != 0 && block7 == block8 && block8 == block9)
                            {
                                   gamedone = 6;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 != 0 && block1 == block5 && block5 == block9)
                            {
                                   gamedone = 7;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 != 0 && block3 == block5 && block5 == block7)
                            {
                                   gamedone = 8;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                     }

                     else if (gamestep == 8 && gamedone == 0)
                     {

                            if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block7 = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block8 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                            {
                                   gamestep++;
                                   block9 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block4 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block5 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                            {
                                   gamestep++;
                                   block6 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block1 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block2 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                            {
                                   gamestep++;
                                   block3 = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("move.wav", NULL, SND_ASYNC);
                                   }
                            }

                            if (block1 != 0 && block1 == block4 && block4 == block7)
                            {
                                   gamedone = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block2 != 0 && block2 == block5 && block5 == block8)
                            {
                                   gamedone = 2;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 != 0 && block3 == block6 && block6 == block9)
                            {
                                   gamedone = 3;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 != 0 && block1 == block2 && block2 == block3)
                            {
                                   gamedone = 4;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block4 != 0 && block4 == block5 && block5 == block6)
                            {
                                   gamedone = 5;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block7 != 0 && block7 == block8 && block8 == block9)
                            {
                                   gamedone = 6;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block1 != 0 && block1 == block5 && block5 == block9)
                            {
                                   gamedone = 7;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }
                            else if (block3 != 0 && block3 == block5 && block5 == block7)
                            {
                                   gamedone = 8;
                                   if (sound == true)
                                   {
                                          PlaySound("win.wav", NULL, SND_ASYNC);
                                   }
                            }

                            if (gamestep == 9 && gamedone == 0)
                            {
                                   gamedone = 10;
                                   if (sound == true)
                                   {
                                          PlaySound("tie.wav", NULL, SND_ASYNC);
                                   }
                            }
                     }
              }

              else if (current == 2)
              {

                     if (difficulty == 3)
                     {

                            if (mx >= 0 && mx <= 120 && my >= 685 && my <= 718)
                            {
                                   current = 0;

                                   gamestep = 0;
                                   block1 = 0;
                                   block2 = 0;
                                   block3 = 0;
                                   block4 = 0;
                                   block5 = 0;
                                   block6 = 0;
                                   block7 = 0;
                                   block8 = 0;
                                   block9 = 0;
                                   gamedone = 0;
                                   winner = 0;
                                   turn = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("home.wav", NULL, SND_LOOP | SND_ASYNC);
                                   }
                            }

                            if (gamedone != 0 && mx >= 738 && mx <= 808 && my >= 20 && my <= 90)
                            {

                                   gamestep = 0;
                                   block1 = 0;
                                   block2 = 0;
                                   block3 = 0;
                                   block4 = 0;
                                   block5 = 0;
                                   block6 = 0;
                                   block7 = 0;
                                   block8 = 0;
                                   block9 = 0;
                                   gamedone = 0;
                                   winner = 0;
                                   if (turn == 1)
                                   {
                                          turn = 2;

                                          int numbergenerator = (rand() % 9) + 1;

                                          usleep(300000);

                                          if (numbergenerator == 1)
                                          {
                                                 block1 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 2)
                                          {
                                                 block2 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 3)
                                          {
                                                 block3 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 4)
                                          {
                                                 block4 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 5)
                                          {
                                                 block5 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 6)
                                          {
                                                 block6 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 7)
                                          {
                                                 block7 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 8)
                                          {
                                                 block8 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 9)
                                          {
                                                 block9 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                   }
                                   else
                                   {
                                          turn = 1;
                                   }
                            }

                            if (mx >= 1190 && mx <= 1280 && my >= 685 && my <= 718)
                            {
                                   exit(0);
                            }

                            if (gamestep == 0 && gamedone == 0 && turn == 1)
                            {

                                   if (mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   //  sleep(1);

                                   if (gamestep == 1 && block1 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }

                                   else if (gamestep == 1 && block2 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block3 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block4 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block5 == 1)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block6 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block7 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block8 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block9 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                            }

                            else if (gamestep == 2 && gamedone == 0 && turn == 1)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (gamestep == 3 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block4 == 1 && block2 == 1 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block4 == 1 && block8 == 1 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block2 == 1 && block6 == 1 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block6 == 1 && block8 == 1 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }

                                   else if (gamestep == 3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                            }

                            else if (gamestep == 4 && gamedone == 0 && turn == 1)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   else if (gamestep == 5 && block1 == 2 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block4 == 2 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block2 == 2 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block2 == 2 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block5 == 2 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block3 == 2 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block3 == 2 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block6 == 2 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block2 == 2 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block4 == 2 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block4 == 2 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block5 == 2 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block7 == 2 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block7 == 2 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block8 == 2 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block5 == 2 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block3 == 2 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block3 == 2 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block5 == 2 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                            }

                            else if (gamestep == 6 && gamedone == 0 && turn == 1)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   else if (gamestep == 7 && block1 == 2 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block1 == 2 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block4 == 2 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block2 == 2 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block2 == 2 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block5 == 2 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block3 == 2 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block3 == 2 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block6 == 2 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block1 == 2 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block1 == 2 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block2 == 2 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block4 == 2 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block4 == 2 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block5 == 2 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block7 == 2 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block7 == 2 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block8 == 2 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block1 == 2 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block1 == 2 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block5 == 2 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block3 == 2 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block3 == 2 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block5 == 2 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 7 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                            }

                            else if (gamestep == 8 && gamedone == 0 && turn == 1)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (gamestep == 9 && block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9)
                                   {
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                            }

                            else if (gamestep == 1 && gamedone == 0 && turn == 2)

                            {
                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (gamestep == 2 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 2 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 2 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 2 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 2 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                   }
                            }

                            else if (gamestep == 3 && gamedone == 0 && turn == 2)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   if (gamestep == 4 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block1 == 2 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block1 == 2 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block4 == 2 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block2 == 2 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block2 == 2 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block5 == 2 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block3 == 2 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block3 == 2 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block6 == 2 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block1 == 2 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block1 == 2 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block2 == 2 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block4 == 2 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block4 == 2 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block5 == 2 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block7 == 2 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block7 == 2 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block8 == 2 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block1 == 2 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block1 == 2 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block5 == 2 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block3 == 2 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block3 == 2 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block5 == 2 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                            }

                            else if (gamestep == 5 && gamedone == 0 && turn == 2)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   if (gamestep == 6 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block1 == 2 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block1 == 2 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block4 == 2 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block2 == 2 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block2 == 2 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block5 == 2 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block3 == 2 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block3 == 2 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block6 == 2 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block1 == 2 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block1 == 2 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block2 == 2 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block4 == 2 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block4 == 2 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block5 == 2 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block7 == 2 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block7 == 2 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block8 == 2 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block1 == 2 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block1 == 2 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block5 == 2 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block3 == 2 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block3 == 2 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block5 == 2 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                            }

                            else if (gamestep == 7 && gamedone == 0 && turn == 2)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   else if (gamedone == 0 && gamestep == 8 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                            }
                     }

                     else if (difficulty == 2)
                     {

                            if (mx >= 0 && mx <= 120 && my >= 685 && my <= 718)
                            {
                                   current = 0;

                                   gamestep = 0;
                                   block1 = 0;
                                   block2 = 0;
                                   block3 = 0;
                                   block4 = 0;
                                   block5 = 0;
                                   block6 = 0;
                                   block7 = 0;
                                   block8 = 0;
                                   block9 = 0;
                                   gamedone = 0;
                                   winner = 0;
                                   turn = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("home.wav", NULL, SND_LOOP | SND_ASYNC);
                                   }
                            }

                            if (gamedone != 0 && mx >= 738 && mx <= 808 && my >= 20 && my <= 90)
                            {

                                   gamestep = 0;
                                   block1 = 0;
                                   block2 = 0;
                                   block3 = 0;
                                   block4 = 0;
                                   block5 = 0;
                                   block6 = 0;
                                   block7 = 0;
                                   block8 = 0;
                                   block9 = 0;
                                   gamedone = 0;
                                   winner = 0;
                                   if (turn == 1)
                                   {
                                          turn = 2;

                                          int numbergenerator = (rand() % 9) + 1;

                                          usleep(300000);

                                          if (numbergenerator == 1)
                                          {
                                                 block1 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 2)
                                          {
                                                 block2 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 3)
                                          {
                                                 block3 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 4)
                                          {
                                                 block4 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 5)
                                          {
                                                 block5 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 6)
                                          {
                                                 block6 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 7)
                                          {
                                                 block7 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 8)
                                          {
                                                 block8 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 9)
                                          {
                                                 block9 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                   }
                                   else
                                   {
                                          turn = 1;
                                   }
                            }

                            if (mx >= 1190 && mx <= 1280 && my >= 685 && my <= 718)
                            {
                                   exit(0);
                            }

                            if (gamestep == 0 && gamedone == 0 && turn == 1)
                            {

                                   if (mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   //  sleep(1);

                                   if (gamestep == 1)
                                   {

                                          int done = 0;
                                          while (done == 0)
                                          {

                                                 int move = rand() % 9 + 1;
                                                 if (move == 1 && block1 == 0)
                                                 {
                                                        block1 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 2 && block2 == 0)
                                                 {
                                                        block2 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 3 && block3 == 0)
                                                 {
                                                        block3 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 4 && block4 == 0)
                                                 {
                                                        block4 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 5 && block5 == 0)
                                                 {
                                                        block5 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 6 && block6 == 0)
                                                 {
                                                        block6 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 7 && block7 == 0)
                                                 {
                                                        block7 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 8 && block8 == 0)
                                                 {
                                                        block8 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 9 && block9 == 0)
                                                 {
                                                        block9 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                          }
                                   }
                            }

                            else if (gamestep == 2 && gamedone == 0 && turn == 1)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (gamestep == 3 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 3 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 3)

                                   {
                                          int done = 0;
                                          while (done == 0)
                                          {

                                                 int move = rand() % 9 + 1;
                                                 if (move == 1 && block1 == 0)
                                                 {
                                                        block1 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 2 && block2 == 0)
                                                 {
                                                        block2 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 3 && block3 == 0)
                                                 {
                                                        block3 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 4 && block4 == 0)
                                                 {
                                                        block4 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 5 && block5 == 0)
                                                 {
                                                        block5 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 6 && block6 == 0)
                                                 {
                                                        block6 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 7 && block7 == 0)
                                                 {
                                                        block7 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 8 && block8 == 0)
                                                 {
                                                        block8 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 9 && block9 == 0)
                                                 {
                                                        block9 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                          }
                                   }
                            }

                            else if (gamestep == 4 && gamedone == 0 && turn == 1)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   else if (gamestep == 5 && block1 == 2 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block4 == 2 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block2 == 2 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block2 == 2 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block5 == 2 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block3 == 2 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block3 == 2 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block6 == 2 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block2 == 2 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block4 == 2 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block4 == 2 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block5 == 2 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block7 == 2 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block7 == 2 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block8 == 2 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block5 == 2 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block3 == 2 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block3 == 2 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block5 == 2 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 5 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 5)

                                   {
                                          int done = 0;
                                          while (done == 0)
                                          {

                                                 int move = rand() % 9 + 1;
                                                 if (move == 1 && block1 == 0)
                                                 {
                                                        block1 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 2 && block2 == 0)
                                                 {
                                                        block2 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 3 && block3 == 0)
                                                 {
                                                        block3 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 4 && block4 == 0)
                                                 {
                                                        block4 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 5 && block5 == 0)
                                                 {
                                                        block5 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 6 && block6 == 0)
                                                 {
                                                        block6 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 7 && block7 == 0)
                                                 {
                                                        block7 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 8 && block8 == 0)
                                                 {
                                                        block8 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 9 && block9 == 0)
                                                 {
                                                        block9 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                          }
                                   }
                            }

                            else if (gamestep == 6 && gamedone == 0 && turn == 1)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   if (gamedone == 0 && gamestep == 7 && block1 == 2 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block1 == 2 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block4 == 2 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block2 == 2 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block2 == 2 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block5 == 2 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block3 == 2 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block3 == 2 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block6 == 2 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block1 == 2 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block1 == 2 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block2 == 2 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block4 == 2 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block4 == 2 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block5 == 2 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block7 == 2 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block7 == 2 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block8 == 2 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block1 == 2 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block1 == 2 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block5 == 2 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block3 == 2 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block3 == 2 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block5 == 2 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 7)

                                   {
                                          int done = 0;
                                          while (done == 0)
                                          {

                                                 int move = rand() % 9 + 1;
                                                 if (move == 1 && block1 == 0)
                                                 {
                                                        block1 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 2 && block2 == 0)
                                                 {
                                                        block2 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 3 && block3 == 0)
                                                 {
                                                        block3 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 4 && block4 == 0)
                                                 {
                                                        block4 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 5 && block5 == 0)
                                                 {
                                                        block5 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 6 && block6 == 0)
                                                 {
                                                        block6 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 7 && block7 == 0)
                                                 {
                                                        block7 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 8 && block8 == 0)
                                                 {
                                                        block8 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 9 && block9 == 0)
                                                 {
                                                        block9 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                          }
                                   }
                            }

                            else if (gamestep == 8 && gamedone == 0 && turn == 1)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (gamestep == 9 && block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9)
                                   {
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                            }

                            else if (gamestep == 1 && gamedone == 0 && turn == 2)

                            {
                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (gamedone == 0 && gamestep == 2)

                                   {
                                          int done = 0;
                                          while (done == 0)
                                          {

                                                 int move = rand() % 9 + 1;
                                                 if (move == 1 && block1 == 0)
                                                 {
                                                        block1 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 2 && block2 == 0)
                                                 {
                                                        block2 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 3 && block3 == 0)
                                                 {
                                                        block3 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 4 && block4 == 0)
                                                 {
                                                        block4 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 5 && block5 == 0)
                                                 {
                                                        block5 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 6 && block6 == 0)
                                                 {
                                                        block6 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 7 && block7 == 0)
                                                 {
                                                        block7 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 8 && block8 == 0)
                                                 {
                                                        block8 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 9 && block9 == 0)
                                                 {
                                                        block9 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                          }
                                   }
                            }

                            else if (gamestep == 3 && gamedone == 0 && turn == 2)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   if (gamestep == 4 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 4 && block1 == 2 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block1 == 2 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block4 == 2 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block2 == 2 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block2 == 2 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block5 == 2 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block3 == 2 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block3 == 2 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block6 == 2 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block1 == 2 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block1 == 2 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block2 == 2 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block4 == 2 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block4 == 2 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block5 == 2 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block7 == 2 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block7 == 2 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block8 == 2 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block1 == 2 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block1 == 2 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block5 == 2 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block3 == 2 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block3 == 2 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 4 && block5 == 2 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 4)

                                   {
                                          int done = 0;
                                          while (done == 0)
                                          {

                                                 int move = rand() % 9 + 1;
                                                 if (move == 1 && block1 == 0)
                                                 {
                                                        block1 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 2 && block2 == 0)
                                                 {
                                                        block2 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 3 && block3 == 0)
                                                 {
                                                        block3 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 4 && block4 == 0)
                                                 {
                                                        block4 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 5 && block5 == 0)
                                                 {
                                                        block5 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 6 && block6 == 0)
                                                 {
                                                        block6 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 7 && block7 == 0)
                                                 {
                                                        block7 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 8 && block8 == 0)
                                                 {
                                                        block8 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 9 && block9 == 0)
                                                 {
                                                        block9 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                          }
                                   }
                            }

                            else if (gamestep == 5 && gamedone == 0 && turn == 2)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   if (gamestep == 6 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 6 && block1 == 2 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block1 == 2 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block4 == 2 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block2 == 2 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block2 == 2 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block5 == 2 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block3 == 2 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block3 == 2 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block6 == 2 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block1 == 2 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block1 == 2 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block2 == 2 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block4 == 2 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block4 == 2 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block5 == 2 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block7 == 2 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block7 == 2 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block8 == 2 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block1 == 2 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block1 == 2 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block5 == 2 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block3 == 2 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block3 == 2 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 6 && block5 == 2 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamedone == 0 && gamestep == 6)

                                   {
                                          int done = 0;
                                          while (done == 0)
                                          {

                                                 int move = rand() % 9 + 1;
                                                 if (move == 1 && block1 == 0)
                                                 {
                                                        block1 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 2 && block2 == 0)
                                                 {
                                                        block2 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 3 && block3 == 0)
                                                 {
                                                        block3 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 4 && block4 == 0)
                                                 {
                                                        block4 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 5 && block5 == 0)
                                                 {
                                                        block5 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 6 && block6 == 0)
                                                 {
                                                        block6 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 7 && block7 == 0)
                                                 {
                                                        block7 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 8 && block8 == 0)
                                                 {
                                                        block8 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 9 && block9 == 0)
                                                 {
                                                        block9 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                          }
                                   }
                            }

                            else if (gamestep == 7 && gamedone == 0 && turn == 2)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 == 2 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 == 2 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 == 2 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 == 2 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 == 2 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 == 2 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 == 2 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 == 2 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   else if (gamedone == 0 && gamestep == 8 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                            }
                     }
                     else if (difficulty == 1)

                     {

                            if (mx >= 0 && mx <= 120 && my >= 685 && my <= 718)
                            {
                                   current = 0;

                                   gamestep = 0;
                                   block1 = 0;
                                   block2 = 0;
                                   block3 = 0;
                                   block4 = 0;
                                   block5 = 0;
                                   block6 = 0;
                                   block7 = 0;
                                   block8 = 0;
                                   block9 = 0;
                                   gamedone = 0;
                                   winner = 0;
                                   turn = 1;
                                   if (sound == true)
                                   {
                                          PlaySound("home.wav", NULL, SND_LOOP | SND_ASYNC);
                                   }
                            }

                            if (gamedone != 0 && mx >= 738 && mx <= 808 && my >= 20 && my <= 90)
                            {

                                   gamestep = 0;
                                   block1 = 0;
                                   block2 = 0;
                                   block3 = 0;
                                   block4 = 0;
                                   block5 = 0;
                                   block6 = 0;
                                   block7 = 0;
                                   block8 = 0;
                                   block9 = 0;
                                   gamedone = 0;
                                   winner = 0;
                                   if (turn == 1)
                                   {
                                          turn = 2;

                                          int numbergenerator = (rand() % 9) + 1;

                                          usleep(300000);

                                          if (numbergenerator == 1)
                                          {
                                                 block1 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 2)
                                          {
                                                 block2 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 3)
                                          {
                                                 block3 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 4)
                                          {
                                                 block4 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 5)
                                          {
                                                 block5 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 6)
                                          {
                                                 block6 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 7)
                                          {
                                                 block7 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 8)
                                          {
                                                 block8 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                          else if (numbergenerator == 9)
                                          {
                                                 block9 = 1;
                                                 gamestep = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("move.wav", NULL, SND_ASYNC);
                                                 }
                                          }
                                   }
                                   else
                                   {
                                          turn = 1;
                                   }
                            }

                            if (mx >= 1190 && mx <= 1280 && my >= 685 && my <= 718)
                            {
                                   exit(0);
                            }

                            if (gamestep == 0 && gamedone == 0 && turn == 1)
                            {

                                   if (mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   //  sleep(1);

                                   if (gamestep == 1 && block1 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block1 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block2 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block3 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block4 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block5 == 1)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block6 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block7 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block8 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                                   else if (gamestep == 1 && block9 == 1)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                   }
                            }

                            else if (gamestep == 2 && gamedone == 0 && turn == 1)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (gamestep == 3)
                                   {
                                          int done = 0;
                                          while (done == 0)
                                          {

                                                 int move = rand() % 9 + 1;
                                                 if (move == 1 && block1 == 0)
                                                 {
                                                        block1 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 2 && block2 == 0)
                                                 {
                                                        block2 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 3 && block3 == 0)
                                                 {
                                                        block3 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 4 && block4 == 0)
                                                 {
                                                        block4 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 5 && block5 == 0)
                                                 {
                                                        block5 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 6 && block6 == 0)
                                                 {
                                                        block6 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 7 && block7 == 0)
                                                 {
                                                        block7 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 8 && block8 == 0)
                                                 {
                                                        block8 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 9 && block9 == 0)
                                                 {
                                                        block9 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                          }

                                          if (block1 != 0 && block1 == block4 && block4 == block7)
                                          {
                                                 gamedone = 1;
                                                 winner = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("win.wav", NULL, SND_ASYNC);
                                                 }
                                                 feature();
                                          }
                                          else if (block2 != 0 && block2 == block5 && block5 == block8)
                                          {
                                                 gamedone = 2;
                                                 winner = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("win.wav", NULL, SND_ASYNC);
                                                 }
                                                 feature();
                                          }
                                          else if (block3 != 0 && block3 == block6 && block6 == block9)
                                          {
                                                 gamedone = 3;
                                                 winner = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("win.wav", NULL, SND_ASYNC);
                                                 }
                                                 feature();
                                          }
                                          else if (block1 != 0 && block1 == block2 && block2 == block3)
                                          {
                                                 gamedone = 4;
                                                 winner = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("win.wav", NULL, SND_ASYNC);
                                                 }
                                                 feature();
                                          }
                                          else if (block4 != 0 && block4 == block5 && block5 == block6)
                                          {
                                                 gamedone = 5;
                                                 winner = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("win.wav", NULL, SND_ASYNC);
                                                 }
                                                 feature();
                                          }
                                          else if (block7 != 0 && block7 == block8 && block8 == block9)
                                          {
                                                 gamedone = 6;
                                                 winner = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("win.wav", NULL, SND_ASYNC);
                                                 }
                                                 feature();
                                          }
                                          else if (block1 != 0 && block1 == block5 && block5 == block9)
                                          {
                                                 gamedone = 7;
                                                 winner = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("win.wav", NULL, SND_ASYNC);
                                                 }
                                                 feature();
                                          }
                                          else if (block3 != 0 && block3 == block5 && block5 == block7)
                                          {
                                                 gamedone = 8;
                                                 winner = 1;
                                                 if (sound == true)
                                                 {
                                                        PlaySound("win.wav", NULL, SND_ASYNC);
                                                 }
                                                 feature();
                                          }
                                   }
                            }

                            else if (gamestep == 4 && gamedone == 0 && turn == 1)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   else if (gamestep == 5 && block1 == 2 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block4 == 2 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block2 == 2 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block2 == 2 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block5 == 2 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block3 == 2 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block3 == 2 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block6 == 2 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block2 == 2 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block4 == 2 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block4 == 2 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block5 == 2 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block7 == 2 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block7 == 2 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block8 == 2 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block1 == 2 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block5 == 2 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block3 == 2 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block3 == 2 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5 && block5 == 2 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 5)
                                   {

                                          int done = 0;
                                          while (done == 0)
                                          {

                                                 int move = rand() % 9 + 1;
                                                 if (move == 1 && block1 == 0)
                                                 {
                                                        block1 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 2 && block2 == 0)
                                                 {
                                                        block2 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 3 && block3 == 0)
                                                 {
                                                        block3 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 4 && block4 == 0)
                                                 {
                                                        block4 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 5 && block5 == 0)
                                                 {
                                                        block5 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 6 && block6 == 0)
                                                 {
                                                        block6 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 7 && block7 == 0)
                                                 {
                                                        block7 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 8 && block8 == 0)
                                                 {
                                                        block8 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 9 && block9 == 0)
                                                 {
                                                        block9 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                          }
                                   }
                            }

                            else if (gamestep == 6 && gamedone == 0 && turn == 1)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 != 0 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 != 0 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 != 0 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 != 0 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 != 0 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 != 0 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   else if (gamestep == 7 && block1 == 2 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block1 == 2 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block4 == 2 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block2 == 2 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block2 == 2 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block5 == 2 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block3 == 2 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block3 == 2 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block6 == 2 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block1 == 2 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block1 == 2 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block2 == 2 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block4 == 2 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block4 == 2 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block5 == 2 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 2;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block7 == 2 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block7 == 2 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block8 == 2 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block1 == 2 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block1 == 2 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block5 == 2 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 2;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block3 == 2 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block3 == 2 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7 && block5 == 2 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 2;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 7)
                                   {

                                          int done = 0;
                                          while (done == 0)
                                          {

                                                 int move = rand() % 9 + 1;
                                                 if (move == 1 && block1 == 0)
                                                 {
                                                        block1 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 2 && block2 == 0)
                                                 {
                                                        block2 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 3 && block3 == 0)
                                                 {
                                                        block3 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 4 && block4 == 0)
                                                 {
                                                        block4 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 5 && block5 == 0)
                                                 {
                                                        block5 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 6 && block6 == 0)
                                                 {
                                                        block6 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 7 && block7 == 0)
                                                 {
                                                        block7 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 8 && block8 == 0)
                                                 {
                                                        block8 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 9 && block9 == 0)
                                                 {
                                                        block9 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                          }
                                   }
                            }

                            else if (gamestep == 8 && gamedone == 0 && turn == 1)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (gamestep == 9 && block1 == 1 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block2 == 1 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block3 == 1 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block1 == 1 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block4 == 1 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block7 == 1 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block1 == 1 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9 && block3 == 1 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamestep == 9)
                                   {
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                            }

                            else if (gamestep == 1 && gamedone == 0 && turn == 2)

                            {
                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (gamestep == 2 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 2 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 2 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 2 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                   }
                                   else if (gamestep == 2 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                   }
                            }

                            else if (gamestep == 3 && gamedone == 0 && turn == 2)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 == 2 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 == 2 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 == 2 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 == 2 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 == 2 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 == 2 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 == 2 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 == 2 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   if (gamedone == 0 && gamestep == 4 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 4)

                                   {
                                          int done = 0;
                                          while (done == 0)
                                          {

                                                 int move = rand() % 9 + 1;
                                                 if (move == 1 && block1 == 0)
                                                 {
                                                        block1 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 2 && block2 == 0)
                                                 {
                                                        block2 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 3 && block3 == 0)
                                                 {
                                                        block3 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 4 && block4 == 0)
                                                 {
                                                        block4 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 5 && block5 == 0)
                                                 {
                                                        block5 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 6 && block6 == 0)
                                                 {
                                                        block6 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 7 && block7 == 0)
                                                 {
                                                        block7 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 8 && block8 == 0)
                                                 {
                                                        block8 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 9 && block9 == 0)
                                                 {
                                                        block9 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                          }
                                   }
                            }

                            else if (gamestep == 5 && gamedone == 0 && turn == 2)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 == 2 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 == 2 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 == 2 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 == 2 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 == 2 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 == 2 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 == 2 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 == 2 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   if (gamedone == 0 && gamestep == 6 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 6)
                                   {

                                          int done = 0;
                                          while (done == 0)
                                          {

                                                 int move = rand() % 9 + 1;
                                                 if (move == 1 && block1 == 0)
                                                 {
                                                        block1 = 2;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 2 && block2 == 0)
                                                 {
                                                        block2 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 3 && block3 == 0)
                                                 {
                                                        block3 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 4 && block4 == 0)
                                                 {
                                                        block4 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 5 && block5 == 0)
                                                 {
                                                        block5 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 6 && block6 == 0)
                                                 {
                                                        block6 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 7 && block7 == 0)
                                                 {
                                                        block7 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 8 && block8 == 0)
                                                 {
                                                        block8 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                                 else if (move == 9 && block9 == 0)
                                                 {
                                                        block9 = 1;
                                                        done = 1;
                                                        gamestep++;
                                                 }
                                          }
                                   }
                            }

                            else if (gamestep == 7 && gamedone == 0 && turn == 2)
                            {

                                   if (block7 == 0 && mx >= 375 && mx <= 565 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block7 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block8 == 0 && mx >= 565 && mx <= 745 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block8 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block9 == 0 && mx >= 745 && mx <= 915 && my >= 130 && my <= 310)
                                   {
                                          gamestep++;
                                          block9 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block4 == 0 && mx >= 375 && mx <= 565 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block4 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block5 == 0 && mx >= 565 && mx <= 745 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block5 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block6 == 0 && mx >= 745 && mx <= 915 && my >= 310 && my <= 490)
                                   {
                                          gamestep++;
                                          block6 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block1 == 0 && mx >= 375 && mx <= 565 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block1 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block2 == 0 && mx >= 565 && mx <= 745 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block2 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }
                                   else if (block3 == 0 && mx >= 745 && mx <= 915 && my >= 490 && my <= 670)
                                   {
                                          gamestep++;
                                          block3 = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("move.wav", NULL, SND_ASYNC);
                                          }
                                   }

                                   if (block1 == 2 && block1 == block4 && block4 == block7)
                                   {
                                          gamedone = 1;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block2 == 2 && block2 == block5 && block5 == block8)
                                   {
                                          gamedone = 2;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 == 2 && block3 == block6 && block6 == block9)
                                   {
                                          gamedone = 3;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 == 2 && block1 == block2 && block2 == block3)
                                   {
                                          gamedone = 4;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block4 == 2 && block4 == block5 && block5 == block6)
                                   {
                                          gamedone = 5;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block7 == 2 && block7 == block8 && block8 == block9)
                                   {
                                          gamedone = 6;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block1 == 2 && block1 == block5 && block5 == block9)
                                   {
                                          gamedone = 7;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (block3 == 2 && block3 == block5 && block5 == block7)
                                   {
                                          gamedone = 8;
                                          winner = 1;
                                          if (sound == true)
                                          {
                                                 PlaySound("win.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }

                                   if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block4 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block7 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block4 == 1 && block4 == block7 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 1;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block2 == 1 && block2 == block5 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block2 == 1 && block2 == block8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 1 && block5 == block8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 2;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 1 && block3 == block6 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 1 && block3 == block9 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block6 == 1 && block6 == block9 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 3;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block2 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block3 == block1 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block2 == 1 && block2 == block3 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 4;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block4 == 1 && block4 == block5 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block4 == 1 && block4 == block6 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 1 && block5 == block6 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 5;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block7 == 1 && block7 == block8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block7 == 1 && block7 == block9 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block8 == 1 && block8 == block9 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 6;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block5 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 1 && block1 == block9 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 1 && block5 == block9 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 7;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 1 && block5 == block3 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 1 && block3 == block7 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 1 && block5 == block7 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 8;
                                          winner = 2;
                                          if (sound == true)
                                          {
                                                 PlaySound("loose.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block1 == 0)
                                   {
                                          block1 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block2 == 0)
                                   {
                                          block2 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block3 == 0)
                                   {
                                          block3 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block4 == 0)
                                   {
                                          block4 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block5 == 0)
                                   {
                                          block5 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block6 == 0)
                                   {
                                          block6 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block7 == 0)
                                   {
                                          block7 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block8 == 0)
                                   {
                                          block8 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                                   else if (gamedone == 0 && gamestep == 8 && block9 == 0)
                                   {
                                          block9 = 1;
                                          gamestep++;
                                          gamedone = 10;
                                          if (sound == true)
                                          {
                                                 PlaySound("tie.wav", NULL, SND_ASYNC);
                                          }
                                          feature();
                                   }
                            }
                     }
              }

              else if (current == 4)
              {

                     if (mx >= 0 && mx <= 120 && my >= 685 && my <= 718)
                     {
                            current = 0;
                     }
                     if (mx >= 1190 && mx <= 1280 && my >= 685 && my <= 718)
                     {
                            exit(0);
                     }
                     if (mx >= 860 && mx <= 975 && my >= 60 && my <= 190)
                     {
                            sound = false;
                            music();
                     }
                     if (mx >= 1025 && mx <= 1150 && my >= 60 && my <= 190)
                     {
                            sound = true;
                            music();
                     }
                     if (mx >= 920 && mx <= 1075 && my >= 200 && my <= 330)
                     {

                            if (difficulty == 3)
                            {
                                   difficulty = 1;
                            }
                            else if (difficulty == 1)
                            {
                                   difficulty = 2;
                            }
                            else if (difficulty == 2)
                            {
                                   difficulty = 3;
                            }
                     }
              }

              // printf("x = %d, y= %d\n",mx,my);
       }
}

void iKeyboard(unsigned char key)
{
       if (key == 'q')
       {
              exit(0);
       }
}

void iSpecialKeyboard(unsigned char key)
{

       if (key == GLUT_KEY_END)
       {
              exit(0);
       }
}

int main()
{

       PlaySound("home.wav", NULL, SND_LOOP | SND_ASYNC);

       iSetTimer(42, toss);

       current = 0;
       gamestep = 0;
       block1 = 0;
       block2 = 0;
       block3 = 0;
       block4 = 0;
       block5 = 0;
       block6 = 0;
       block7 = 0;
       block8 = 0;
       block9 = 0;
       gamedone = 0;
       turn = 1;
       difficulty = 2;
       feature();
       iInitialize(1280, 718, "Tic-Tac-Toe");

       return 0;
}