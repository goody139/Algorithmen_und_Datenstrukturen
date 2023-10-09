#ifndef SPIELFELD_H
#define SPIELFELD_H

class Spielfeld
{
private:
    int width;
    int height;
    int size;
    int field[20][20];

public:
    Spielfeld();
    Spielfeld(int sz);

    int getWidth();
    int getHeight();

    void draw();
    int getField(int x, int y);
    int setField(int x, int y);
};

#endif // SPIELFELD_H
