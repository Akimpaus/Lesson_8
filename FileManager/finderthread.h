#ifndef FINDERTHREAD_H
#define FINDERTHREAD_H
#include <QThread>
#include <QListWidget>

class FinderThread : public QThread
{
    Q_OBJECT

public:

    QString search_string;
    explicit FinderThread(QObject* parent = nullptr);
    void run() override; 

signals:

    void findedFile(const QString&);

};

#endif // FINDERTHREAD_H
