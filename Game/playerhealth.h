#ifndef PLAYERHEALTH_H
#define PLAYERHEALTH_H

#include <QObject>

class playerHealth : public QObject
{
    Q_OBJECT
public:
    explicit playerHealth(QObject *parent = nullptr);
    ~playerHealth();

    void increaseHealth() {playerHealtPoints += 1;};
    void decreaseHealth();

    int getPlayerHealth() {return playerHealtPoints;};

    int playerHealtPoints;

signals:

};

#endif // PLAYERHEALTH_H
