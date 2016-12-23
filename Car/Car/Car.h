#pragma once


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
