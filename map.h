#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <vector>
#include "cell.h"

class Map : public QObject
{
    Q_OBJECT
public:
    explicit Map(unsigned w, unsigned h, QObject *parent = nullptr);

    std::vector<Cell> cells() const;

    bool setCellAt(unsigned index, const Cell &cell);
    void executeNextStep();

signals:
    void postNextStepExecution();

public slots:
    void nextStepButtonPressed();

private:
    const unsigned width;
    const unsigned height;
    std::vector<Cell> mCells;
};

#endif // MAP_H
