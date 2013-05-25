#ifndef TEXTIK_H
#define	TEXTIK_H

#include "common.h"

class Textik: public Interactive_Modules{
public:
    Textik(Position pos, int length);
    ~Textik();
    void parametrs(char*);
    void draw();
    int work();
    void clean_element();
    void clean_window();
    void clean_line();
protected:
    int m_size, inf_size,current;
    char **information;
    Position m_pos;
};



#endif	/* TEXTIK_H */

