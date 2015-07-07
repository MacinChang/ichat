#include "Level.h"

Level::Level()
{


}

void Level::LoadLevel(QString level)
{
    usrLevel = level.toInt();
     sun = usrLevel/16;
     usrLevel = usrLevel%16;
     moon = usrLevel/4;
     star = usrLevel%4;

}





