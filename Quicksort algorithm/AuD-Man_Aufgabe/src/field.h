#ifndef FIELD_H
#define FIELD_H


class Field {
    private:
        int x;
        int y;
        int value;

    public:
        Field();
        Field(int x, int y, int value);

        int getX();
        int getY();
        int getValue();

        void setX(int x);
        void setY(int y);
        void setValue(int value);
};

#endif // FIELD_H
