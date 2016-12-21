// CarTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\Car\Car.h"

struct CarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture);

BOOST_AUTO_TEST_CASE(CheckAllGears)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(!car.SetSpeed(5));
	BOOST_CHECK(car.SetGear(REVERSE));
	BOOST_CHECK(car.SetSpeed(2));
	BOOST_CHECK(!car.SetGear(FIRST));
	BOOST_CHECK(car.SetGear(NEUTRAL));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(FIRST));
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK(car.SetGear(SECOND));
	BOOST_CHECK(!car.SetGear(REVERSE));
	BOOST_CHECK(car.SetSpeed(30));
	BOOST_CHECK(car.SetGear(SECOND));
	BOOST_CHECK(car.SetGear(THIRD));
	BOOST_CHECK(car.SetSpeed(60));
	BOOST_CHECK(car.SetGear(FOUTH));
	BOOST_CHECK(car.SetGear(FIFTH));
	BOOST_CHECK(car.SetGear(NEUTRAL));
	


}


BOOST_AUTO_TEST_CASE(CheckDefaultState)
{
	BOOST_CHECK(!car.IsEngineTurnedOn());
	BOOST_CHECK(car.GetSpeed() == 0);
	BOOST_CHECK(car.GetGear() == NEUTRAL);
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

BOOST_AUTO_TEST_CASE(CanChangeToItself)
{
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(NEUTRAL));
}


BOOST_AUTO_TEST_SUITE_END();
