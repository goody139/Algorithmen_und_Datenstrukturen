#ifndef PRESENT_H
#define PRESENT_H


class Present
{
// Die Attribute
protected:
    int posX;
    int posY;
    int number;
    int size = 20;

public:
    Present();
    Present(int x, int y, int nummer);

    void drawPresent(int x, int y);
    void setPosition(int x, int y);

    void drawArrowgreen(int x, int y);
    void drawArrowRed(int x, int y);
    void setPosY(int value);
    void setPosX(int value);
    int getPosY() const;
    int getPosX() const;
    int getNumber() const;
    void setNumber(int value);
};

#endif // PRESENT_H
