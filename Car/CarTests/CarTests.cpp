// CarTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\Car\Car.h"
#include <boost/test/unit_test.hpp>
const int REVERSE = 6, NEUTRAL = 0, FIRST = 1, SECOND = 2, THIRD = 3, FOUTH = 4, FIFTH = 5, FORWARD = 1, BACKWARD = -1;

struct CarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture);

BOOST_AUTO_TEST_CASE(CheckDefaultState)
{
	BOOST_CHECK(!car.IsEngineTurnedOn());
	BOOST_CHECK(car.GetSpeed() == 0);
	BOOST_CHECK(car.GetGear() == NEUTRAL);
	BOOST_CHECK(car.GetDir() == NEUTRAL);
}

BOOST_AUTO_TEST_CASE(TurningOnAndOff)
{
	BOOST_CHECK(!car.TurnOffEngine());
	BOOST_CHECK(!car.IsEngineTurnedOn());

	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.IsEngineTurnedOn());

	BOOST_CHECK(!car.TurnOnEngine());
	BOOST_CHECK(car.IsEngineTurnedOn());

	BOOST_CHECK(car.TurnOffEngine());
	BOOST_CHECK(!car.IsEngineTurnedOn());
}

BOOST_AUTO_TEST_CASE(CantChangeIfTurnedOff)
{
	BOOST_CHECK(!car.SetGear(FIRST));
	BOOST_CHECK(!car.SetSpeed(1));
	BOOST_CHECK(!car.SetGear(REVERSE));
	BOOST_CHECK(!car.SetSpeed(1));
}

BOOST_AUTO_TEST_CASE(CantIncSpeedAndChangeGearOnNeurtal)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(FIRST));
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK(car.SetGear(NEUTRAL));
	BOOST_CHECK(!car.SetSpeed(21));
	BOOST_CHECK(car.GetSpeed() == 20);
	BOOST_CHECK(car.SetSpeed(10));
	BOOST_CHECK(car.GetSpeed() == 10);
	BOOST_CHECK(!car.SetGear(FIRST));
	BOOST_CHECK(car.GetGear() == NEUTRAL);

}

BOOST_AUTO_TEST_CASE(CantIncSpeed)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(FIRST));
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK(car.GetSpeed() == 20);
	BOOST_CHECK(!car.SetSpeed(35));
	BOOST_CHECK(car.GetSpeed() == 20);

}

BOOST_AUTO_TEST_CASE(CanChangeToItself)
{
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(NEUTRAL));
}

BOOST_AUTO_TEST_CASE(SimpleMoveCar)
{
	BOOST_CHECK(!car.SetGear(1));

	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(!car.SetGear(111));
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(30));
	BOOST_CHECK(car.GetDir() == FORWARD);

	BOOST_CHECK(!car.SetSpeed(60));
	BOOST_CHECK(car.SetGear(3));
	BOOST_CHECK(car.SetSpeed(60));
	BOOST_CHECK(car.GetDir() == FORWARD);

	BOOST_CHECK(!car.TurnOffEngine());
}

BOOST_AUTO_TEST_CASE(MovingBackwardAndForward)
{
	car.TurnOnEngine();
	BOOST_CHECK(car.SetGear(6));

	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.SetGear(6));

	BOOST_CHECK(car.SetGear(6));
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK(car.GetDir() == BACKWARD);

	BOOST_CHECK(!car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.GetDir() == NEUTRAL);

	BOOST_CHECK(car.SetSpeed(10));
	BOOST_CHECK(car.GetDir() == FORWARD);
}

BOOST_AUTO_TEST_CASE(MovingBackwardToNeutralOnSpeed)
{
	car.TurnOnEngine();
	BOOST_CHECK(car.SetGear(6));
	BOOST_CHECK(car.SetSpeed(20));

	BOOST_CHECK(!car.SetGear(1));
	BOOST_CHECK(car.SetGear(0));

	BOOST_CHECK(!car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(1));

	BOOST_CHECK(car.SetSpeed(10));
	BOOST_CHECK(!car.SetGear(6));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(6));
}


BOOST_AUTO_TEST_SUITE_END();
