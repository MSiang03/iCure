#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QObject>
#include <QTcpServer>

class ServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(ushort port = 4500, QObject *parent = nullptr);

signals:

private: //field
    QTcpServer *_server;

private: //method
    void setupServer();

};

#endif // SERVERMANAGER_H
