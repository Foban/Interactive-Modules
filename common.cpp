#include "common.h"

Interactive_Modules::Interactive_Modules():
name('\0')
{
}

Interactive_Modules::Interactive_Modules(char *n_name):
name(n_name)
{}

char* Interactive_Modules::get_name(){
    return name;
}

Position::Position():
x(0),y(0)
{}

Position::Position(const Position &n_pos):
x(n_pos.x),y(n_pos.y)
{}

const char *symbols[] = {"\342\225\220", "\342\224\217", "\342\224\223", "\342\224\233", "\342\224\227", "\342\224\203", "\342\224\201", "\342\225\213", "\342\224\263", "\342\224\253", "\342\224\273", "\342\224\243", "\342\226\221", "\342\226\222", "\342\226\223", "\342\226\266", "\342\230\272", "\302\244", "\342\216\210", "\342\231\245", "\342\226\262", "\342\226\210", "\xe2\xAC\x8D"};
const char comands[] = {'\177', '\12', '\11', '\40'};
const char *arrows[] = {"\33\133\101", "\33\133\104", "\33\133\103", "\33\133\102"};

bool Equality_Test_For_String(const char *first, const char *second)
{
   for(int i = 0; first[i] != '\0' || second[i] != '\0'; i++)
   {
      if(first[i] != second[i]) return false;
   }

   return true;
}

 int GetKey()
 {
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
 }


 int kbhit()
   {
      struct termios oldt, newt;
      int ch;
      int oldf;

      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
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

 void OutS(symbol sm)
   {
      std::cout << symbols[sm];
   }

   int Arrows()
   {
      char ch[] = "\0\0\0";
      ch[0] = GetKey();



      for(int i = 1; kbhit() && (i < 3); ++i)
         ch[i] = GetKey();


      for(int i = UP; i < 4; i++)
      {
         if(Equality_Test_For_String(ch, arrows[i])) return i;
      }

      for(int i = BACKSPACE; i <= SPACE; i++)
         if(ch[0] == comands[i]) return i + 5;

      return (int)ELSE;
   }

   void SetCurrentPos(int x, int y)
   {
      std::cout << "\033[0;0H";

      for(; y; y--)
         std::cout << "\033[1B";

      for(; x; x--)
         std::cout << "\033[1C";

  }

  char *StrTok(char* str, char* stis){
    static char *work = 0;
    static int i,n,l;
    if(str){
        work = str;
        i = 0;
        n = 0;
        l = 0;
        for(; str[l] != '\0';++l);
    }
    char *Tokker = 0;
    bool fl = true;
    if(work && l-i){
    for(; i < l && fl ; ++i)
        for(int p = 0; stis[p] != '\0' && fl; ++p){
            if(work[i]==stis[p]) fl = false;
        }

    Tokker = new char[i-n];
    int p=0;
    for(; n < i-1; ++n,++p)
        Tokker[p] = work[n];
    if(i==l) Tokker[p] = work[l-1];
    ++n;
    }
    return Tokker;
}
