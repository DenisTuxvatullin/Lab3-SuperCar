#pragma once

const int reverse = 6, neutral = 0, first = 1, second = 2, third = 3, fourth = 4, fifth = 5;
const int maxSpeed[7] = {0, 30, 50, 60, 90, 150 , 20};
const int minSpeed[7] = {0,  0, 20, 30, 40,  50 ,  0};
const int forward = 1, backward = -1;

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
