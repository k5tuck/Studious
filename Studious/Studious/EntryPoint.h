#pragma once

#ifdef ST_PLATFORM_WINDOWS

extern Studious::Application* Studious::CreateApplication();

int main(int argc, char** argv) {

	auto app = Studious::CreateApplication();
	app->Init();
	app -> Run();
	delete app;
}

#endif