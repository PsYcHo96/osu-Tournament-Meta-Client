#include "song.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QPixmap>

song::song(QObject *parent) : QObject(parent)
{
    name = new QString();
    notes = new QString();
    label = new QLabel();
}

song::song(QString _osuFile, float _sr, float _bpm, Mod _mod, QObject *parent)
{
    name = new QString();
    notes = new QString();
    label = new QLabel();

    mod = _mod;
    sr = _sr;

    parseOsuFile(_osuFile);

}

song::song(QString _name, float _sr, float _bpm, float _ar, float _cs, float _hp, float _od, QString _imageFile, Mod _mod, QObject *parent)
{
    name = new QString(_name);
    sr = _sr;
    bpm = _bpm;
    ar = _ar;
    cs = _cs;
    hp = _hp;
    od = _od;
    mod = _mod;

    notes = new QString();
    label = new QLabel();

    // Load map image from file
    image.load(_imageFile);
    label->setPixmap(image.scaledToHeight(300));
}

bool song::parseOsuFile(QString _osuFile)
{
    // Parse .osu file for map data
    QFile file(_osuFile);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(0, "Error", file.errorString());
    }
    else
    {
        QTextStream in(&file);

        while(!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(":");

            if (fields.at(0) == "Title:")
                name = fields.at(1);

            else if (fields.at(0) == "HPDrainRate")
                hp = int(fields.at(1));

            else if (fields.at(0) == "CircleSize")
                cs = int(fields.at(1));

            else if (fields.at(0) == "OverallDifficulty")
                od = int(fields.at(1));

            else if (fields.at(0) == "ApproachRate")
                ar = int(fields.at(1));
        }
    }
}
