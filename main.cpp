#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile source("./source.txt");
    if (!source.open(QIODevice::ReadOnly | QIODevice::Text))
        return 1;

    QFile Dictionary("./Dictionary.txt");
    if (!Dictionary.open(QIODevice::WriteOnly | QIODevice::Text))
        return 2;

    QString fline = "";
    QString sline;

    QTextStream in(&source);
    QTextStream out(&Dictionary);

    while (!in.atEnd()) {
        sline = in.readLine();

        QString lcfline = fline.toLower();
        QString lcsline = sline.toLower();

        if (fline != "" && lcfline != lcsline)
        {
            out << '\"' << lcfline << '\"' << '=' << '\"' << fline << '\"' << endl;
        }
        fline = sline;
    }

    source.close();
    Dictionary.close();

    return a.exec();
}
