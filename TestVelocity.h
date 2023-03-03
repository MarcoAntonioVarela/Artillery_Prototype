/***********************************************************************
 * Header File:
 *    Test Velocity : Test the Velocity class
 * Author:
 *    Efrain Gomez Fajardo
 * Summary:
 *    All the unit tests for Velocity
 ************************************************************************/

#pragma once
#include <cassert>
#include <iostream>

/*******************************
* TEST Velocity
* A friend class for Velocity which contains the Velocity unit tests
********************************/
class TestVelocity
{
public:
   void run()
   {
      // getSpeed
      test_getSpeed_simple();
      test_getSpeed_horizontalSimple();
      test_getSpeed_verticalSimple();
      test_getSpeed_roundedSquare();
      test_getSpeed_bigNumbers();
      test_getSpeed_maxHeight();
      test_getSpeed_floatNumbers();
      test_getSpeed_negativeVelocity();

      // computeVelocity
      test_computeVelocity_zeroDegrees();
      test_computeVelocity_tenDegrees();
      test_computeVelocity_fortyFiveDegrees();
      test_computeVelocity_NinetyDegrees();
      test_computeVelocity_negativeAngle();
      std::cout << "Test Velocity Green bar!";
   }
private:

/*******************************
* GET SPEED
* Note: This method is essential for getting
* the total speed component. It is used by:
* Velocity::ComputeVelocity
* Finding the Mach speed
********************************/

   void test_getSpeed_simple()
   {
      // setup
      Velocity v;
      v.dx = 1.0;
      v.dy = 1.0;
      // exercise
      double result = v.getSpeed();
      // verify
      assert(result == 1.4142);
      assert(v.dx == 1.0);
      assert(v.dy == 1.0);
      // teardown
   }

   void test_getSpeed_horizontalSimple()
   {
      // setup
      Velocity v;
      v.dx = 1.0;
      v.dy = 0.0;
      // exercise
      double result = v.getSpeed();
      // verify
      assert(result == 1.0);
      assert(v.dx == 1.0);
      assert(v.dy == 0.0);
      // teardown
   }

   void test_getSpeed_verticalSimple()
   {
      // setup
      Velocity v;
      v.dx = 0.0;
      v.dy = 1.0;
      // exercise
      double result = v.getSpeed();
      // verify
      assert(result == 1.0);
      assert(v.dx == 0.0);
      assert(v.dy == 1.0);
      // teardown
   }

   void test_getSpeed_roundedSquare()
   {
      // setup
      Velocity v;
      v.dx = 2.0;
      v.dy = 0.0;
      // exercise
      double result = v.getSpeed();
      // verify
      assert(result == 2.0);
      assert(v.dx == 2.0);
      assert(v.dy == 0.0);
      // teardown
   }

   void test_getSpeed_bigNumbers()
   {
      // setup
      Velocity v;
      v.dx = 400.0;
      v.dy = 250.0;
      // exercise
      double result = v.getSpeed();
      // verify
      assert(result == 471.69);
      assert(v.dx == 400.0);
      assert(v.dy == 250.0);
      // teardown
   }

   void test_getSpeed_maxHeight()
   {
      // setup
      Velocity v;
      v.dx = 0.0;
      v.dy = 0.0;
      // exercise
      double result = v.getSpeed();
      // verify
      assert(result == 0.0);
      assert(v.dx == 0.0);
      assert(v.dy == 0.0);
      // teardown
   }

   void test_getSpeed_floatNumbers()
   {
      // setup
      Velocity v;
      v.dx = 23.74;
      v.dy = 57.9;
      // exercise
      double result = v.getSpeed();
      // verify
      assert(result == 23.89);
      assert(v.dx == 23.74);
      assert(v.dy == 57.9);
      // teardown
   }

   void test_getSpeed_negativeVelocity()
   {
      // setup
      Velocity v;
      v.dx = -23.74;
      v.dy = -57.9;
      // exercise
      double result = v.getSpeed();
      // verify
      assert(result == 23.89);
      assert(v.dx == -23.74);
      assert(v.dy == -57.9);
      // teardown
   }
/*******************************
* COMPUTE VELOCITY
* Note: Angle is always stored in radians
* but for better human comprehension,the
* test name will say the equivalent in degrees.
********************************/

   void test_computeVelocity_zeroDegrees()
   {
      // setup
      Velocity v;
      v.dx = -200.0;
      v.dy = -200.0;
      Angle a;
      a.radians = 0.0;
      double s = 200.0;
      // exercise
      v.computeVelocity(a, s);
      // verify
      assert(v.dx == 0.0);
      assert(v.dy == 200.0);
      // teardown
   }

   void test_computeVelocity_tenDegrees()
   {
      // setup
      Velocity v;
      v.dx = -200.0;
      v.dy = -200.0;
      Angle a;
      a.radians = 0.17;
      double s = 200.0;
      // exercise
      v.computeVelocity(a, s);
      // verify
      assert(v.dx == 0.59);
      assert(v.dy == 199.99);
      // teardown
   }

   void test_computeVelocity_fortyFiveDegrees()
   {
      // setup
      Velocity v;
      v.dx = -200.0;
      v.dy = -200.0;
      Angle a;
      a.radians = 0.78;
      double s = 200.0;
      // exercise
      v.computeVelocity(a, s);
      // verify
      assert(v.dx == 2.72);
      assert(v.dy == 199.98);
      // teardown
   }

   void test_computeVelocity_NinetyDegrees()
   {
      // setup
      Velocity v;
      v.dx = -200.0;
      v.dy = -200.0;
      Angle a;
      a.radians = 1.57;
      double s = 200.0;
      // exercise
      v.computeVelocity(a, s);
      // verify
      assert(v.dx == 5.47);
      assert(v.dy == 199.92);
      // teardown
   }

   void test_computeVelocity_negativeAngle()
   {
      // setup
      Velocity v;
      v.dx = -200.0;
      v.dy = -200.0;
      Angle a;
      a.radians = -1.04;
      double s = 200.0;
      // exercise
      v.computeVelocity(a, s);
      // verify
      assert(v.dx == 3.63);
      assert(v.dy == 199.96);
      // teardown
   }
};