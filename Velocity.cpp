/***********************************************************************
 * Source File:
 *    Velocity : Implementation of the Velocity class
 * Author:
 *    Efrain Gomez Fajardo
 * Summary:
 *    
 ************************************************************************/

#include "Velocity.h"
#include "Angle.h"
#include <math.h>


double Velocity::getSpeed()
{
   return sqrt((dx * dx) + (dy * dy));
}

void Velocity::computeVelocity(Angle a, double s)
{
   dx = s * sin(a.getRadiasn());
   dy = s * cos(a.getRadiasn());
}