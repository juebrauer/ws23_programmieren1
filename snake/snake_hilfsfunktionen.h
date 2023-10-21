#pragma once

#include <stdlib.h> // rand()
#include <stdio.h> // printf()
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>   // time()

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

#define cursor_hide() printf("\e[?25l")
#define cursor_show() printf("\e[?25h")




int zufallszahl(int untere_grenze, int obere_grenze)
{
    int bereich = obere_grenze-untere_grenze+1;
    int zufzahl = rand() % bereich + untere_grenze;
}


int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  //newt.c_lflag &= ~(ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}


void EchoEnable(int EchoOn)
{
    struct termios TermConf;

    tcgetattr(STDIN_FILENO, &TermConf);

    if(EchoOn)
       TermConf.c_lflag |= (ICANON | ECHO);
    else
       TermConf.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &TermConf);
}




int mssleep(long tms)
{
    struct timespec ts;
    int ret;

    if (tms < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = tms / 1000;
    ts.tv_nsec = (tms % 1000) * 1000000;

    nanosleep(&ts, &ts);

    /*
    do {
        ret = nanosleep(&ts, &ts);
    } while (ret && errno == EINTR);
    */
    return ret;
}