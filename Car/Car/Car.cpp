#include "stdafx.h"
#include "Car.h"
#include <cstdlib>

CCar::CCar(void) : m_engineIsTurnedOn(false), m_speed(0), m_gear(NEUTRAL), m_direction(NEUTRAL)
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
	return false;
}

bool CCar::TurnOffEngine()
{
	if (m_engineIsTurnedOn && m_gear == NEUTRAL && m_speed == 0)
	{
		m_engineIsTurnedOn = false;
		return true;
	}
	return false;
}

bool CCar::CheckSpeed(int gear, int speed)
{

	if (speed == 0)//Только 1 задняя и нейтраль могут быть 0
	{
		if (gear != NEUTRAL && gear != FIRST && gear != REVERSE)
		{
			return false;
		}
		SetDir(NEUTRAL);
		return true;
	}

	if (gear == NEUTRAL)
	{
		return true;
	}
	if (speed < MIN_SPEED[gear] || speed > MAX_SPEED[gear])
	{
		return false;
	}

	if (gear == REVERSE)
	{
		SetDir(BACKWARD);
		return true;
	}
	SetDir(FORWARD);
	return true;
}

bool CCar::SetGear(int gear)
{
	int direction = 0;
	if (m_gear == gear)
		return true;

	if (!m_engineIsTurnedOn)
		return false;
	
	if (m_gear == NEUTRAL)// на нейтралке нельзя менять передачу если скорость не равна 0
	{
		if (m_speed != 0)
		{
			return false;
		}
	}
	if (m_gear == REVERSE || m_gear == FIRST)//с первой на заднюю только на 0 и наоборот
	{
		if (gear == REVERSE || gear == FIRST)
		{
			if (m_speed != 0)
			{
				return false;
			}
		}

	}
	
	if (CheckSpeed(gear, m_speed))//проверка входит ли скорость в дипозон данной передачи
	{
		direction = m_direction;
		if (CheckSpeed(m_gear, m_speed) && m_direction == direction)//можно ли переключить передачу, есть ли совпадение дипозонов
		{
			m_gear = gear;
			return true;
		}
	}
	return false;
}

bool CCar::SetSpeed(int speed)
{
	if (m_speed == speed)
		return true;

	if (m_gear == NEUTRAL)//на нейтралке только уменьшение скорости 
	{
		if (m_speed > speed && speed >= 0)
		{
			m_speed = speed;
			return true;
		}
		return false;
	}
	if (CheckSpeed(m_gear, speed))
	{
		m_speed = speed;
		return true;
	}
	return false;

}

void CCar::SetDir(int direction)
{

	m_direction = direction;
}

int CCar::GetGear() const
{
	return m_gear;
}

int CCar::GetDir() const
{
	return m_direction;
}


int CCar::GetSpeed() const
{
	return m_speed;
}

bool CCar::IsEngineTurnedOn() const
{
	return m_engineIsTurnedOn;
}
