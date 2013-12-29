#include <QtGui/QGuiApplication>
#include <QDir>
#include "qtquick2applicationviewer.h"
#include "DataParse.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    DataParse dp;
    dp.openFile("Data.xml");
    dp.test();

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/MCBlockHelper/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
