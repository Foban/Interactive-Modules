#include <cstdlib>
#include "common.h"
#include "textik.h"
#include "numberik.h"
#include "passwordik.h"

using namespace std;

int main() {
    Interactive_Modules *mod[2];
    Position pos[2];
    pos[0].x = 0;
    pos[0].y = 19;
    pos[1].x = 5;
    pos[1].y = 10;
    mod[0] = new Textik(pos[0],25);
    mod[0]->draw();
    mod[1] = new Numberik(pos[1],10);
    mod[1]->draw();
    mod[1]->parametrs("12 278 3");
    mod[0]->parametrs("abra kadabra tritonusiui obachkus");
    mod[0]->work();
    mod[1]->work();
    mod[0]->work();
    mod[1]->work();
    mod[0]->parametrs("zornic foban fobeus kilneri");
    mod[0]->work();
    mod[1]->parametrs("12 878 13");
    mod[1]->work();
    mod[0]->clean_window();
    mod[1]->clean_window();

    return 0;
}

