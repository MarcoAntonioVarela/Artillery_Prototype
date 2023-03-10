/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich, Efrain Gomez and Marco Varela
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testGround.h"
#include "testPhysics.h"           // Unit tests created by Marco Varela
#include "TestVelocity.h"          // Unit tests created by Efrain Gomez

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   TestPosition().run();
   TestGround().run();
   TestPhysics().run();
   TestVelocity().run();
}
