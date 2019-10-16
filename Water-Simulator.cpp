// Water-Simulator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Water.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#define MSGA

constexpr int POOL_W = 80;
constexpr int POOL_H = 50;
constexpr int POOL_W_LIMIT = POOL_W - 1;
constexpr int POOL_H_LIMIT = POOL_H - 1;
constexpr double G = 1.0;

using namespace std;

vector<Water> v;
int pool[POOL_H][POOL_W] = { 0 };
double t = 0.0;

void init();
void setPool();
void printView();
void waterFallTest();
void initWater(int x, int y, int x1, int y1);
void joinWater();
void clearWater();
void setPoolMeta_s(int x, int y, int m_Id);
void movement(Water &w);
void phys(Water &w);
void printWaterMsg();
string getPrintModule(int id);

int main() {
	init();
	printView();
	while (true) {
		system("cls");
		clearWater();
		waterFallTest();
		joinWater();
		printView();
		printWaterMsg();
		t += 0.02;
	}
	return 0;
}

void printView() {
	for (int itor0 = 0; itor0 < POOL_H; ++itor0) {
		for (int itor1 = 0; itor1 < POOL_W; ++itor1) {
			cout << getPrintModule(pool[itor0][itor1]);
		}
		cout << '\n';
	}
}

void waterFallTest()
{
	int s = v.size();
	for (int i = 0; i < s; ++i) {
		// 遍历所有水元并计算t时刻的位移
		movement(v[i]);
		phys(v[i]);
	}
#ifdef MSG
	cout << "t=" << t << v[0].SpeY << "&" << v[0].SpeX << "&" << v[0].PosY << "&" << v[0].PosX << endl;
#endif // !MSG
}

void phys(Water & w)
{
	if (w.PosX > POOL_H_LIMIT && w.PosY < POOL_W_LIMIT) {
		w.SpeX = -0.9 * w.SpeX;
		w.SpeY = -1 * (((double)rand() / 100000.0) - 0.0075) * w.SpeX;
	}
	else if (w.PosX < POOL_H_LIMIT && w.PosY > POOL_W_LIMIT) {
		w.SpeX = -0.9 * w.SpeX;
		w.SpeY = -1 * (((double) rand() / 100000.0) - 0.0075)  * w.SpeX;
	}
}

void printWaterMsg()
{

}

void movement(Water & w)
{
	w.SpeY += w.AccY * t;
	w.SpeX += w.AccX * t + G * t;
	w.PosY += (int)w.SpeY * t;
	w.PosX += (int)w.SpeX * t;
}

void init() {
	setPool();
	initWater(0, 1, 19, 40);
	joinWater();
}

void initWater(int x, int y, int x1, int y1) {
	v.reserve((x1-x)*(y1-y));
	Water * w;
	for (int i = x; i <= x1; ++i) {
		for (int j = y; j <= y1; ++j) {
			w = new Water(i, j, 0, 3.0);
			v.push_back(*w);
		}
	}
}

void joinWater() {
	int s = v.size();
	for (int i = 0; i < s; ++i) {
		setPoolMeta_s(v[i].PosX, v[i].PosY, 2);
	}
}

void clearWater()
{
	int s = v.size();
	for (int i = 0; i < s; ++i) {
		setPoolMeta_s(v[i].PosX, v[i].PosY, 0);
	}
}

void setPoolMeta_s(int x, int y, int m_Id)
{
	if ((x >= 0 && x < POOL_H_LIMIT) && (y > 0 && y < POOL_W_LIMIT)) {
		pool[x][y] = m_Id;
	}
}

void setPool() {
	int ax = POOL_W - 1;
	int bx = POOL_H - 1;
	for (int itor0 = 0; itor0 <= bx; ++itor0) {
		// 竖壁
		pool[itor0][0] = 1;
		pool[itor0][ax] = 1;
	}
	for (int itor0 = 0; itor0 <= ax; ++itor0) {
		// 底部
		pool[bx][itor0] = 1;
	}
}

string getPrintModule(int id) {
	switch (id) {
		case 0:
			return "  ";
		case 1:
			return "█";
		case 2:
			return "※";
		default:
			return "ER";
	}
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
