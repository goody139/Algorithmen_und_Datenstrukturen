#ifndef OFAUDTURTLE_H
#define OFAUDTURTLE_H

#include "ofAuDApp.h"

/**
 * Die Klasse ofAuDTurtle ermöglicht es eine Turtle-Grafik
 * zu zeichnen.
 *
 * @brief The ofAuDTurtle class
 */
class ofAuDTurtle {
   protected:
      double x;         // The position
      double y;
      double dir;       // The angle in degree
      ofPolyline *lines;
      ofColor color;

   public:
      ofAuDTurtle();

      void reset();
      void reset (int sx, int sy);

      void moveTo(int tx, int ty);
      void move(double dist);

      void setDirection(double angle);
      void turn(double angle);

      void setColor(int r, int g, int b);
      void setColor(ofColor col);

      void draw();
};

#endif // OFAUDTURTLE_H
