#ifndef NEWSPAPER_H
#define NEWSPAPER_H
#include <QObject>

class newspaper : public QObject
{
    Q_OBJECT
public:
    newspaper(const QString &name):
        m_name(name)
        {
        }

        void send()
        {
            emit newPaper(m_name);
        }
signals:
        void newPaper(const QString &name);

private:
        QString m_name;
};

#endif // NEWSPAPER_H
