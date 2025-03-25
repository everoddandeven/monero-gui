#ifndef VIRTUALBOX_H
#define VIRTUALBOX_H

#include <QApplication>


class VirtualBox
{
public:
    VirtualBox();
    static bool detect();
    static bool detect3DAcceleration();
};

#endif // VIRTUALBOX_H
