#include "Menu.h"
#include "Gra.h"
#include<time.h>



int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Gra gra;
    Menu menu;

    gra.run();


    return 0;
}