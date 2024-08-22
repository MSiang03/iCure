#ifndef READER_H
#define READER_H
#include <QObject>
#include <QDebug>

class reader : public QObject
{
    Q_OBJECT
public:
    reader(){}

    void receiveNewspaper(const QString &name)
    {
        qDebug() << "Receives Newspaper: "<<name;
    }
};

#endif // READER_H
