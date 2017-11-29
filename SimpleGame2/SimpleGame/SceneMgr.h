#pragma once
#include "newObject.h"
#include "Renderer.h"

const int Max = 11;

class Scene
{
public:
	void InitRenderer() { my_renderer = new Renderer(500, 800); }
	Scene()
	{
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < Max; ++j)
			my_opject[i][j] = nullptr;
		}

		this->InitRenderer();
		if (!my_renderer->IsInitialized())
		{
			std::cout << "Renderer could not be initialized.. \n";
		}

		my_opject[RED][0] = new Object(RED, OBJECT_BUILDING, -500 / 4, 500 / 4, 0, BUILDING_SIZE, 1, 0, 0, 1);
		my_opject[RED][1] = new Object(RED, OBJECT_BUILDING, -500 / 4 + BUILDING_SIZE * 1.5, 500 / 4, 0, BUILDING_SIZE, 1, 0, 0, 1);
		my_opject[RED][2] = new Object(RED, OBJECT_BUILDING, 250 - BUILDING_SIZE, 500 / 4, 0, BUILDING_SIZE, 1, 0, 0, 1);

		my_opject[BLUE][0] = new Object(BLUE, OBJECT_BUILDING, -500 / 4, -500 / 4, 0, BUILDING_SIZE, 0, 0, 1, 1);
		my_opject[BLUE][1] = new Object(BLUE, OBJECT_BUILDING, -500 / 4 + BUILDING_SIZE * 1.5, -500 / 4, 0, BUILDING_SIZE, 0, 0, 1, 1);
		my_opject[BLUE][2] = new Object(BLUE, OBJECT_BUILDING, 250 - BUILDING_SIZE, -500 / 4, 0, BUILDING_SIZE, 0, 0, 1, 1);


		count += 1;
		my_buildingImg[0] = my_renderer->CreatePngTexture("Resource\\cube.png");

		my_redCharacterTime = GetTickCount();
		my_blueCharacterTime = 0;
		

	}	
	~Scene() { delete my_renderer; } // 할당한 메모리 해제
	void Collion();
	void addObj(TEAM team, float x, float y, float z, float s);
	void update(float elapsedTime);
	void Render();
	void DeleteObject();
private:
	Object *my_opject[2][Max];
	int count = 0;
	int my_lifetest;
	Renderer* my_renderer;
	vector<Object> my_bullet; // 총알을 담을 객체
	vector<Object> my_arrow; // 화살을 담을 객체
	int my_buildingImg[2];
	DWORD my_redCharacterTime;
	DWORD my_blueCharacterTime;
};
