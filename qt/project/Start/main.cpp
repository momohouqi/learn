#include <QCoreApplication>
#include <qapplication.h>
#include <qlabel.h>
#include <qstring.h>


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();
    QApplication app(argc, argv);
    QLabel *label = new QLabel(NULL);
    QString string("Hello world");
    label->setText(string);
    //label->setAlignment(QT::AlignVCenter | QT::AlignHCenter);
    label->setGeometry(0, 0, 180, 75);
    label->show();
    app.setMainWidget(label);
    app.set
    return app.exec();
}

