// StarField3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>
#include <array>
#include <random>
class StarField : public olc::PixelGameEngine
{
public:
	StarField()
	{
		sAppName = "Star Field";
	}
	
	//set world speed
	float fWorldSpeed = 100.0f;
	
	//declare 2D vectors for each layer of stars which get progressively smaller
	std::array<olc::vf2d, 1000> arrayStarsClose;
	std::array<olc::vf2d, 800> arrayStarsMid;
	std::array<olc::vf2d, 500> arrayStarsFar;
	
	//set colours and progressively fading intensities of pixels for stars so they appear further away.
	olc::Pixel pStarClose = olc::PixelF(1.0f, 1.0f, 1.0f, 1.0f);
	olc::Pixel pStarMid = olc::PixelF(1.0f, 1.0f, 1.0f, 0.6f);
	olc::Pixel pStarFar = olc::PixelF(1.0f, 1.0f, 1.0f, 0.4f);
public:
	bool OnUserCreate() override
	{

		//create enhanced for loops to initialise star vectors
		for (auto& s : arrayStarsClose) s = { (float)(rand() % ScreenWidth()), (float)(rand() % ScreenHeight()) };
		for (auto& s2 : arrayStarsMid) s2 = { (float)(rand() % ScreenWidth()), (float)(rand() % ScreenHeight()) };
		for (auto& s3 : arrayStarsFar) s3 = { (float)(rand() % ScreenWidth()), (float)(rand() % ScreenHeight()) };
		return true;
	}

public:
	bool OnUserUpdate(float fElapsedTime) override
	{
		//generates mersenne twister random numbers
		std::mt19937 mt{};
		
		//three loops that draw stars for different layers of stars moving at slower speeds to give illusion of distance
		Clear(olc::BLACK);
		for (auto& s : arrayStarsClose)
		{
			
			s.x -= fWorldSpeed * fElapsedTime * 2.0f;
			if (s.x <  0) {
				s.x = 0;
				s = { (float)ScreenWidth() + (float)(mt() % 50), (float)(rand() % ScreenHeight())};
			}

			Draw(s, pStarClose);
		}

		for(auto& s2 : arrayStarsMid)
		{
			s2.x -= fWorldSpeed * fElapsedTime * 1.5f;
			if (s2.x < 0) {
				s2.x = 0;
				s2 = { (float)ScreenWidth() + (float)(mt() % 50), (float)(rand() % ScreenHeight()) };
			}

			Draw(s2, pStarMid);
		}

		for (auto& s3 : arrayStarsFar)
		{
			s3.x -= fWorldSpeed * fElapsedTime * 1.0f;
			if (s3.x < 0) {
				s3.x = 0;
				s3 = { (float)ScreenWidth() + (float)(mt() % 50), (float)(rand() % ScreenHeight()) };
			}

			Draw(s3, pStarFar);
		}

		return true;
		
	}
};
//main function creates window with resolution and scaling
int main()
{
	StarField demo;
	if (demo.Construct(400, 400, 1, 1)) {
		demo.Start();
	}
	return 0;
}

