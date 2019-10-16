#pragma once
class Water {
public:
	int PosX, PosY;
	double SpeX, SpeY, AccX, AccY;
	Water();
	Water(int PosX, int PosY);
	Water(int PosX, int PosY, double SpeX, double SpeY);
	Water(int PosX, int PosY, double SpeX, double SpeY, double AccX, double AccY);
	~Water();
};
