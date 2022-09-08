#include "pch.h"
#include "Juego.h"
#include<time.h>
int main()
{
    srand(time(0));
    Console::SetWindowSize(80, 40);
    Console::CursorVisible = false;
    CJuego* objJuego = new CJuego(); 
    objJuego->jugar(); 
    _getch(); 
    return 0;
}
