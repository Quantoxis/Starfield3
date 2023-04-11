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

	float fWorldSpeed = 100.0f;
	float fStarSpeedMultiplier = 2.0f;
	
	std::array<olc::vf2d, 1000> arrayStarsClose;
	std::array<olc::vf2d, 800> arrayStarsMid;
	std::array<olc::vf2d, 500> arrayStarsFar;

	//olc::Pixel p = 0xFFFFFFFF;
	//olc::Pixel p2 = 0xFFFFFF70;
	olc::Pixel pStarClose = olc::PixelF(1.0f, 1.0f, 1.0f, 1.0f);
	olc::Pixel pStarMid = olc::PixelF(1.0f, 1.0f, 1.0f, 0.6f);
	olc::Pixel pStarFar = olc::PixelF(1.0f, 1.0f, 1.0f, 0.4f);
public:
	bool OnUserCreate() override
	{


		for (auto& s : arrayStarsClose) s = { (float)(rand() % ScreenWidth()), (float)(rand() % ScreenHeight()) };
		for (auto& s2 : arrayStarsMid) s2 = { (float)(rand() % ScreenWidth()), (float)(rand() % ScreenHeight()) };
		for (auto& s3 : arrayStarsFar) s3 = { (float)(rand() % ScreenWidth()), (float)(rand() % ScreenHeight()) };
		return true;
	}

public:
	bool OnUserUpdate(float fElapsedTime) override
	{

		std::mt19937 mt{};
		for (int count{ 1 }; count <= 50; ++count) {
			
		}

		 
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

		//vertical scrolling version
		//Clear(olc::BLACK);
		//for (auto& s : arrayStars)
		//{
		//	s.y += fWorldSpeed * fElapsedTime;
		//	if (s.y > (float)ScreenHeight()) {
		//		s = { (float)(rand() % ScreenWidth()), 0.0f };
		//	}
		//	Draw(s);
		//}
		return true;
		
	}
};

int main()
{
	StarField demo;
	if (demo.Construct(400, 400, 1, 1)) {
		demo.Start();
	}
	return 0;
}

