#ifndef SONG_H
#define SONG_H

#include <QObject>
#include <QLabel>

class song : public QObject
{
    Q_OBJECT

public:
    enum class Mod
    {
        Nomod,
        Hidden,
        DoubleTime,
        HardRock,
        FreeMod,
        TieBreaker
    };

public:
    explicit song(QObject *parent = nullptr);
    explicit song(QString osuFile, QObject *parent = nullptr);
    explicit song(QString name, float sr, float bpm, float ar, float cs, float hp, float od, QString imageFile = QString(), QObject *parent = nullptr);

// Private Members
private:
    QString *name;
    float sr;
    float bpm;
    float ar;
    float cs;
    float hp;
    float od;
    Mod mod;
    QString *notes;

    QLabel *label;
    QPixmap image;

// Private Methods
private:
    bool parseOsuFile(QString _osuFile);

signals:

public slots:
};

#endif // SONG_H
