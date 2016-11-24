#include "stdafx.h"
#include "Car.h"


CCar::CCar(void) : m_engineIsTurnedOn(false), m_speed(0), m_gear(neutral)
{
}


CCar::~CCar(void)
{
}


bool CCar::TurnOnEngine()
{
	if (!m_engineIsTurnedOn)
	{
		m_engineIsTurnedOn = true;
		return true;
	}
	else
	{
		return false;
	}
}


bool CCar::TurnOffEngine()
{
	if (m_engineIsTurnedOn && m_gear == neutral && m_speed == 0)
	{
		m_engineIsTurnedOn = false;
		return true;
	}
	else
	{
		return false;
	}
}


bool CCar::CheckSpeed(int gear, int speed) const
{
	if (gear = 0)
	{
		return false;
	}
	if (speed < low[gear - 1] || speed > speedLimit[gear - 1])
		return false;
		

	return true;
}


bool CCar::SetGear(int gear)
{
	if (m_gear == gear)
		return true;

	if (CheckSpeed(gear, m_speed))
	{
		m_gear = gear;
		return true;
	}
	else
	{
		return false;
	}
}


bool CCar::SetSpeed(int speed)
{
	if (m_speed == speed)
		return true;

	if (CheckSpeed(m_gear, speed))
	{
		m_speed = speed;
		return true;
	}
	else
	{
		return false;
	}
}


int CCar::GetGear() const
{
	return m_gear;
}


int CCar::GetSpeed() const
{
	return m_speed;
}


bool CCar::IsEngineTurnedOn() const
{
	return m_engineIsTurnedOn;
}
