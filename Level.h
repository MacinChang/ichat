#ifndef LEVEL_H
#define LEVEL_H

#include <QString>
#include <QListWidget>
#include <QListWidgetItem>
#include <QImage>
#include <QPixmap>

class Level:public QListWidget
{
public:
    Level();
    void LoadLevel(QString level);

public:
     int sun,moon,star;

private:
    int usrLevel;

};

#endif // LEVEL_H
