#ifndef NUMBERIK_H_INCLUDED
#define NUMBERIK_H_INCLUDED

#include "common.h"

class Numberik: public Interactive_Modules{
public:
    Numberik(Position pos, int length);
    ~Numberik();
    void parametrs(char*);
    void draw();
    int work();
    void clean_element();
    void clean_window();
    void clean_line();
protected:
    int max_num();
    int m_size, first, last, stap, current;
    Position m_pos;
};

#endif // NUMBERIK_H_INCLUDED
