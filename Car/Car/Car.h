#pragma once

const int REVERSE = 6, NEUTRAL = 0, FIRST = 1, SECOND = 2, THIRD = 3, FOUTH = 4, FIFTH = 5;
const int MAX_SPEED[7] = {0, 30, 50, 60, 90, 150 , 20};
const int MIN_SPEED[7] = {0,  0, 20, 30, 40,  50 ,  0};
const int FORWARD = 1, BACKWARD = -1, INFO = 1, TURNED_ON = 2, TURNED_OFF = 3, SET_GEAR = 4, SET_SPEED = 5, PROG_EXIT = 6;

class CCar
{
public:
	CCar(void);
	~CCar(void);

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	void SetDir(int dir);

	int GetGear() const;
	int  GetSpeed() const;
	int GetDir() const;
	bool IsEngineTurnedOn() const;

private:
	bool CheckSpeed(int gear, int speed);
	bool m_engineIsTurnedOn;
	int m_speed;
	int m_gear;
	int m_direction;
};
