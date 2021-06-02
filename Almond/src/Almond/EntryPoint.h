#pragma once

#ifdef AL_PLATFORM_WINDOWS

extern Almond::Application* Almond::CreateApplication();

int main(int argc, char** argv)
{
	Almond::Log::Init();
	AL_CORE_WARN("Initialized Log!");

	int a = 5;
	AL_CLIENT_INFO("Hello! Var = {0}", a);

	auto app = Almond::CreateApplication();
	app -> Run();
	delete app;
}

#endif // HZ_PLATFORM_WINDOWS
