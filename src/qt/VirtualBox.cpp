#include "VirtualBox.h"
#include <QProcess>

bool VirtualBox::detect() {
    QProcess process;
    process.start("systemd-detect-virt", QStringList());
    process.waitForFinished();
    
    QString output = process.readAllStandardOutput().trimmed();
    bool found = output == "oracle";

#ifdef QT_DEBUG
    if (found)
        qDebug() << "VirtualBox VM detected";
#endif

    return found;
}

bool VirtualBox::detect3DAcceleration() {
    if (!detect()) return false;

    QProcess process;
    process.start("sh", QStringList() << "-c" << "glxinfo | grep 'OpenGL renderer'");
    process.waitForFinished();

    bool found = process.readAllStandardOutput().trimmed().contains("SVGA3D");

#ifdef QT_DEBUG
    if (found)
        qDebug() << "VirtualBox 3D acceleration detected";
#endif

    return found;
}
