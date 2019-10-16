#include "pch.h"
#include "Water.h"
#include <cstdlib>

constexpr int POOL_W = 80;
constexpr int POOL_H = 50;

Water::Water() {
	this->PosX = rand() % (POOL_H - 1);
	this->PosY = rand() % (POOL_W - 1);
	this->SpeX = 0.0;
	this->SpeY = 0.0;
	this->AccX = 0.0;
	this->AccY = 0.0;
}
Water::Water(int PosX, int PosY) {
	this->PosX = PosX;
	this->PosY = PosY;
	this->SpeX = 0.0;
	this->SpeY = 0.0;
	this->AccX = 0.0;
	this->AccY = 0.0;
}
Water::Water(int PosX, int PosY, double SpeX, double SpeY) {
	this->PosX = PosX;
	this->PosY = PosY;
	this->SpeX = SpeX;
	this->SpeY = SpeY;
	this->AccX = 0.0;
	this->AccY = 0.0;
}
Water::Water(int PosX, int PosY, double SpeX, double SpeY, double AccX, double AccY) {
	this->PosX = PosX;
	this->PosY = PosY;
	this->SpeX = SpeX;
	this->SpeY = SpeY;
	this->AccX = AccX;
	this->AccY = AccY;
}
Water::~Water() {}
