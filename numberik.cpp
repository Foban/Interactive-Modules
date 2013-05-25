
#include "numberik.h"
#include <stdlib.h>

Numberik::Numberik(Position pos, int length):
m_size(length),first(0),last(0),stap(0),m_pos(pos)
{}

Numberik::~Numberik(){
    clean_element();
}

void Numberik::draw(){
    SetCurrentPos(m_pos.x, m_pos.y);
    OutS(TOP_LEFT_CORNER);
    for(int i = 0; i <= m_size; ++i)
        OutS(HORIZONTAL);
    OutS(TOP_RIGHT_CORNER);
    SetCurrentPos(m_pos.x, m_pos.y+1);
    OutS(VERTICAL);
    for(int i = 1; i <= m_size; ++i)
        std::cout<<' ';
    OutS(UP_DOWN_ARROW);
    OutS(VERTICAL);
    SetCurrentPos(m_pos.x, m_pos.y+2);
    OutS(DOWN_LEFT_CORNER);
    for(int i = 0; i <= m_size; ++i)
        OutS(HORIZONTAL);
    OutS(DOWN_RIGHT_CORNER);
}

void Numberik::clean_window(){
    for(int i = 0; i < 3; ++i){
        SetCurrentPos(m_pos.x, m_pos.y+i);
        for(int n = 0; n <= m_size+2; ++n)
            std::cout << ' ';
    }
    SetCurrentPos(0, m_pos.y+3);
}

void Numberik::clean_element(){
    first = 0;
    last = 0;
    stap = 0;
}

void Numberik::clean_line(){
    SetCurrentPos(m_pos.x+1, m_pos.y+1);
    for(int i = 0; i < m_size; ++i)
        std::cout <<" ";
}

void Numberik::parametrs(char* inf){
    int i=0;
    char *work[3];
    if(StrTok(inf," ")) ++i;
    for(;StrTok(0," ");++i);
    if(i==3){
        for(int n = 0; n < i;++n)
            if(!n)work[n] = StrTok(inf," ");
            else work[n] = StrTok(0," ");
        first = atoi(work[0]);
        last = atoi(work[1]);
        stap = atoi(work[2]);
        current = first;
    }
}

int Numberik::work(){
	SetCurrentPos(m_pos.x+1, m_pos.y+1);
	static int m_f = 0, m_l = 0, m_s = 0;
	if(m_f!=first||m_l!=last||m_s!=stap){
		clean_line();
		SetCurrentPos(m_pos.x+1, m_pos.y+1);
	}
	std::cout << current;
    SetCurrentPos(m_pos.x+m_size+1, m_pos.y+1);
	while(1){
		switch(Arrows()){
		case 0:
			if(current+stap <= last)
				current += stap;
			else current = first;
			break;
		case 3:
			if(current-stap >= first)
				current -= stap;
			else current = last;
			break;
		case ENTER+5:
			return current;
			break;
			}
		clean_line();
		SetCurrentPos(m_pos.x+1, m_pos.y+1);
		std::cout << current;
		SetCurrentPos(m_pos.x+m_size+1, m_pos.y+1);
	}
}








