#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <iostream>
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

int reading_(QString file_name)
{
    int i=0;
//    QString * list = (QString *)calloc(i+1,sizeof(QString));
//    QString * list = new QString[i+1];

    QFile file(file_name);

    if (!file.exists())
    {
        cout<<"file not found"<<endl;
        return 0;
    }
    if (!file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        cout<<"couldn't open the file"<<endl;
        return 0;
    };

    QTextStream in(&file);
    QString line = in.readAll();
    qInfo() << line;

    QString * list=new QString [line.count("\n")+1];
//QString
    for(i=0;line.indexOf("\n")>=0 && i<15;i++)
    {
        list[i]=line.mid(0, line.toStdString().find("\n"));

//        qInfo()<<i<<line.mid(0, line.toStdString().find("\n"))<<"and"<<list[i];


//        if(  (list=(QString *)realloc(list,(i+1)*(sizeof(QString))))==NULL )
//            cout<<"realloc unsuccessful";

        line=line.mid(line.toStdString().find("\n")+1);

//        qInfo()<<line<<"\n";
        qInfo()<<list[i];
//        <<"and"<<line;
    };

    list[i]=(QString)line;
        qInfo()<<list[i];
    return i;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


//    test();
//    if (writing_("line 3", "C:/Users/inter/projects_a/qt_name_list/namelist/test.txt")==true)
//        if (writing_("line 4", "C:/Users/inter/projects_a/qt_name_list/namelist/test.txt")==true)
//            cout<<"done"<<endl;
       if(reading_("C:/Users/inter/projects_a/qt_name_list/namelist/test.txt")>0) cout<<"reading compelete";



    return a.exec();
}
