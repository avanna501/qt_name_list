#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QList>
using namespace std;

void test()
{
    QFile file ("C:/Users/inter/projects_a/qt_name_list/namelist/test.txt");
    if (!file.open(QIODevice::OpenModeFlag::ReadWrite))
    {
        cout<<"couldn't open the file"<<endl;
        return;
    }

    cout<<"the file is opened"<<endl;

    file.write(QByteArray("new line and number 125"));
    file.flush();

    file.seek(0);//to go to the very beginning in case some work was done
    file.readAll();

    cout<<"the file is now going to be closed"<<endl;
    file.close();
}

bool writing_(QString l, QString file_name)
{
    int i;

    QFile file(file_name);
    if (!file.open(QIODevice::OpenModeFlag::ReadWrite))
    {
        cout<<"couldn't open the file"<<endl;
        return false;
    };

    for(i=0;i<1000;i++)
    {
        file.seek(i);
        if (file.atEnd()==true)
            break;
    };

    QTextStream stream(&file);
    stream<<l<<"\n";

    file.close();
    return true;
}

QList<QString> reading_(QString file_name)
{
    QString line;
    QFile file(file_name);
    QList<QString> list={};

    if (!file.exists())
    {
        cout<<"file not found"<<endl;
        return list;
    }
    if (!file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        cout<<"couldn't open the file"<<endl;
        return list;
    };

//    line = file.readLine();
//    !line.isNull()

    while(!file.atEnd())
    {
        line = file.readLine();
        list.append(line);

        qInfo()<<line<<list.last();
    } ;

    return list;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


//    test();
//    if (writing_("line 3", "C:/Users/inter/projects_a/qt_name_list/namelist/test.txt")==true)
//        if (writing_("line 4", "C:/Users/inter/projects_a/qt_name_list/namelist/test.txt")==true)
//            cout<<"done"<<endl;
    QList<QString> list;
    list=reading_("C:/Users/inter/projects_a/qt_name_list/namelist/test.txt");
    qInfo()<<list.size();

    return a.exec();
}
