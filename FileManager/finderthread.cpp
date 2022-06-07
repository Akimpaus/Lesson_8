#include "finderthread.h"
#include <stdexcept>
#include <QFileInfoList>
#include <QDir>
#include <QDirIterator>

FinderThread::FinderThread(QObject* parent) :
    QThread(parent)
{
    setTerminationEnabled();
}

void FinderThread::run()
{
    if(search_string.isEmpty())
        return;
    QFileInfoList all_drivers = QDir::drives();
    for(const auto& driver : all_drivers)
    {
        QDirIterator it(driver.path(), QStringList(search_string), QDir::NoFilter, QDirIterator::Subdirectories);
        while (it.hasNext())
        {
            QFile file(it.next());
            emit findedFile(file.fileName());
        }
    }
}
