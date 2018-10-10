#include "map.h"

Map::Map(unsigned w, unsigned h, QObject *parent) :
    width(w), height(h), QObject(parent)
{
    mCells = std::vector<Cell>(width * height, Cell());
}

std::vector<Cell> Map::cells() const
{
    return mCells;
}

bool Map::setCellAt(unsigned index, const Cell &cell)
{
    if (index >= mCells.size())
        return false;

    // TODO: find out if there need to check cells for equality
    mCells[index] = cell;
    return true;
}

void Map::executeNextStep()
{
    for (auto cell: mCells) {
        if (cell.grassLevel < 3)
            cell.grassLevel++;
    }
}

void Map::nextStepButtonPressed()
{
    executeNextStep();
    emit postNextStepExecution();
}
