#pragma once

#include "Application.h"

#ifdef AL_PLATFORM_WINDOWS

extern Almond::Application* Almond::CreateApplication();

int main(int argc, char** argv)
{
	printf("Almond Engine");

	auto app = Almond::CreateApplication();
	app -> Run();
	delete app;
}

#endif // HZ_PLATFORM_WINDOWS
