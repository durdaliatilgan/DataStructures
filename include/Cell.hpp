#ifndef CELL
#define CELL

class Cell
{
    private:
    public:
        Cell(int cellMainNumber,int *cellArray, int totalSize);
        int cellMainNumber;
        int *cellArray;
        int size;
        ~Cell();
};
#endif