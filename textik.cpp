
#include "textik.h"

Textik::Textik(Position pos, int length):
m_size(length),inf_size(0),m_pos(pos)
{}

Textik::~Textik(){
    clean_element();
}

void Textik::draw(){
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

void Textik::clean_window(){
    for(int i = 0; i < 3; ++i){
        SetCurrentPos(m_pos.x, m_pos.y+i);
        for(int n = 0; n <= m_size+2; ++n)
            std::cout << ' ';
    }
    SetCurrentPos(0, m_pos.y+3);
}

void Textik::clean_element(){
    for(int i = 0; i < inf_size; ++i){
        information[i] = '\0';
        delete information[i];
    }
    SetCurrentPos(m_pos.x+1, m_pos.y+1);
    for(int i = 0; i < m_size; ++i)
        std::cout<<' ';
    delete[]information;
    inf_size = 0;
    information = 0;
}

void Textik::clean_line(){
    SetCurrentPos(m_pos.x+1, m_pos.y+1);
    for(int i = 0; i < m_size; ++i)
        std::cout <<" ";
}

void Textik::parametrs(char* inf){
    clean_element();
    int i=0;
    if(StrTok(inf," ")) ++i;
    for(;StrTok(0," ");++i);
    information = new char*[i];
    for(int n = 0; n < i;++n)
        if(!n)information[n] = StrTok(inf," ");
        else information[n] = StrTok(0," ");
    inf_size = i;
}

int Textik::work(){
	SetCurrentPos(m_pos.x+1, m_pos.y+1);
	static char** mem=0;
	static int num=0;
	if(mem!=information){
        clean_line();
        SetCurrentPos(m_pos.x+1, m_pos.y+1);
        num = 0;
        mem = information;
	}
	for(int i = 0; i < m_size && information[num][i] != '\0'; i++)
        std::cout << information[num][i];
		SetCurrentPos(m_pos.x+m_size+1, m_pos.y+1);
	while(1){
		switch(Arrows()){
		case 0:
			if(num < inf_size-1)
				num++;
			else
				num = 0;
			break;
		case 3:
			if(num > 0)
				num--;
			else
				num = inf_size-1;
			break;
		case ENTER+5:
		    SetCurrentPos(0, m_pos.y+3);
			return num;
			break;
		}
		clean_line();
		SetCurrentPos(m_pos.x+1, m_pos.y+1);
		for(int i = 0; i < m_size && information[num][i] != '\0'; i++)
		std::cout << information[num][i];
		SetCurrentPos(m_pos.x+m_size+1, m_pos.y+1);
	}
}
