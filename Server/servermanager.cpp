#include "servermanager.h"

ServerManager::ServerManager(QObject *parent) : QObject(parent)
{
    setupServer(port);
}
