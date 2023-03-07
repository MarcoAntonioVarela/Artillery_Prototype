/***********************************************************************
 * Header File:
 *    Velocity : Represents a velocity
 * Author:
 *    Efrain Gomez Fajardo
 * Summary:
 *    This velocity is a property of the Shell
 ************************************************************************/

#pragma once

class Angle;
class TestVelocity;

class Velocity
{
   friend TestVelocity;
private:
   double dx;
   double dy;

public:
   double getDX() { return dx; }
   double getDY() { return dy; }

   double getSpeed();
   void computeVelocity(Angle a, double s);
};