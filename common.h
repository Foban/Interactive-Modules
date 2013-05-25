#ifndef COMMON_H
#define COMMON_H

#include <wchar.h>

enum type {CHAR, BOOL, INT, STRING};

struct Position{
    int x,y;
    Position();
    Position(const Position &n_pos);
};

class Interactive_Modules{
public:
    Interactive_Modules();
    Interactive_Modules(const Interactive_Modules &n_mod);
    Interactive_Modules(char *n_name);
    virtual ~Interactive_Modules(){};
    virtual void parametrs(char*){};
    virtual void draw(){};
    virtual int work()=0;
    virtual void clean_element(){};
    virtual void clean_window(){};
    virtual void clean_line(){};
    char* get_name();
private:
    char* name;
    type m_type;
};

#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>

enum comand {BACKSPACE, ENTER, TAB, SPACE};
enum arrow {UP, LEFT, RIGHT, DOWN, ELSE};
enum symbol {DOUBLE_HORIZONTAL, TOP_LEFT_CORNER, TOP_RIGHT_CORNER, DOWN_RIGHT_CORNER, DOWN_LEFT_CORNER,
VERTICAL, HORIZONTAL, VERTICAL_AND_HORIZONTAL, DOWN_AND_HORIZONTAL, LEFT_AND_VERTICAL,
UP_AND_HORIZONTAL, RIGHT_AND_VERTICAL, LIGHT_SHADE, MEDIUM_SHADE, DARK_SHADE, RIGHT_POINTER,
SMILING_FACE, CURRENCY_SIGN, ASTERISK, HEART, UP_POINTER, FULL_BLOCK, UP_DOWN_ARROW};

int GetKey();
void SetCurrentPos(int, int);
void OutS(symbol sm);
int Arrows();
 char *StrTok(char* str, char* stis);

#endif
