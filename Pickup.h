#ifndef PICKUP_H
#define PICKUP_H


class Pickup : public QObject
{
    Q_OBJECT
public:
    explicit Pickup(QObject *parent = 0);
    ~Pickup();

signals:

public slots:
};

#endif // PICKUP_H
