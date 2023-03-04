/***********************************************************************
 * Header File:
 *    Test Position : Test the Physics file
 * Author:
 *    Marco Varela
 * Summary:
 *    All the unit tests for Physics
 ************************************************************************/

#pragma once

#include <iostream>
#include "physics.h"
#include <cassert>

using namespace std;

/*****************************************************
 * TEST Physics
 * A class that contains the Physics file unit tests
 *****************************************************/
class TestPhysics
{
public:
   void run()
   {
      test_linearInterpolation_upper_table();
      test_linearInterpolation_lower_table();
      test_linearInterpolation_middle_table();
      test_linearInterpolation_normal_interpolation();
      test_linearInterpolation_outside_upper_table();
      test_linearInterpolation_outside_lower_table();
      test_calculateLinearInterpolation_3();
      test_calculateLinearInterpolation_11();
      test_calculateLinearInterpolation_64();
      test_calculateLinearInterpolation_9802();
      test_calculateDragForce_initial();
      test_calculateDragForce_peak();
      
      
   }
private:
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }


/*****************************************************
 * TESTING LINEAR INTERPOLATION FUNCTION
 *****************************************************/

   void test_linearInterpolation_upper_table()
   {
      // setup
      double mach = 0.300;
      // exercise
      double test = linearInterpolation(dragCoefecients, mach);
      // verify
      assert(closeEnough((test, 0.1629, 0.0001));
      // teardown
   }


   void test_linearInterpolation_lower_table()
   {
      // setup
      double altitude = 80000;
      // exercise
      double test = linearInterpolation(densities, altitude);
      // verify
      assert(closeEnough((test, 0.0000185, 0.00000001));
      // teardown
   }
 
   void test_linearInterpolation_middle_table()
   {
      // setup
      double altitude = 5000;
      // exercise
      double test = linearInterpolation(gravities, altitude);
      // verify
      assert(closeEnough((test, 9.797, 0.0001));
      // teardown
   }


   void test_linearInterpolation_normal_interpolation()
   {
      // setup
      double altitude = 9500;
      // exercise
      double test = linearInterpolation(speedsOfSound, altitude);
      // verify
      assert(closeEnough((test, 301, 0.0001));
      // teardown
   }


   void test_linearInterpolation_outside_upper_table()
   {
      // setup
      double altitude = -50;
      // exercise
      double test = linearInterpolation(gravities, altitude);
      // verify
      assert(closeEnough((test, 9.8069, 0.0001));
      // teardown
   }



   void test_linearInterpolation_outside_lower_table()
   {
      // setup
      double mach = 0.550;
      // exercise
      double test = linearInterpolation(dragCoefecients, mach);
      // verify
      assert(closeEnough((test, 0.2664, 0.0001));
      // teardown
   }


/*****************************************************
* TESTING CALCULATE LINEAR INTERPOLATION FUNCTION
*****************************************************/

   void test_calculateLinearInterpolation_3()
   {
      // setup
      double x = 3;
      double x0 = 0;
      double x1 = 5;
      double y0 = 0;
      double y1 = 5;
      // exercise
      double test = calculateLinearInterpolation(x0,y0,x1,y1,x);
      // verify
      assert(closeEnough((test, 3, 0.001));
      // teardown
   }


   void test_calculateLinearInterpolation_11()
   {
      // setup
      double x = 5;
      double x0 = -1;
      double x1 = 8;
      double y0 = 15;
      double y1 = 10;
      // exercise
      double test = calculateLinearInterpolation(x0, y0, x1, y1, x);
      // verify
      assert(closeEnough((test, 11.666, 0.00001));
      // teardown
   }


   void test_calculateLinearInterpolation_64()
   {
      // setup
      double x = 14;
      double x0 = 10;
      double x1 = 20;
      double y0 = 80;
      double y1 = 40;
      // exercise
      double test = calculateLinearInterpolation(x0, y0, x1, y1, x);
      // verify
      assert(closeEnough((test, 64, 0.001));
      // teardown
   }


   void test_calculateLinearInterpolation_9802()
   {
      // setup
      double x = 1385;
      double x0 = 1000;
      double x1 = 2000;
      double y0 = 9.804;
      double y1 = 0.801;
      // exercise
      double test = calculateLinearInterpolation(x0, y0, x1, y1, x);
      // verify
      assert(closeEnough((test, 9.802, 0.000001));
      // teardown
   }



/*****************************************************
 * TESTING DRAGFORCE FUNCTION
 *****************************************************/

   void test_calculateDragForce_initial()
   {
      // setup
      double drag = 0.2595;
      double airDensity = 1.2250000;
      double velocity = 827;
      double shellArea = 0.018842;

      // exercise
      double test = calculateDragForce(drag, airDensity, velocity, shellArea);
      // verify
      assert(closeEnough((test, 2048.243, 0.0001));
      // teardown
   }

   void test_calculateDragForce_peak()
   {
      // setup
      double drag = 0.212;
      double airDensity = 0.9093000;
      double velocity = 240;
      double shellArea = 0.018842;

      // exercise
      double test = calculateDragForce(drag, airDensity, velocity, shellArea);
      // verify
      assert(closeEnough((test, 104.607, 0.0001));
      // teardown
   }
};