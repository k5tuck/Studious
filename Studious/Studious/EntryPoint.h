#pragma once

#ifdef ST_PLATFORM_WINDOWS

extern Studious::Application* Studious::CreateApplication();

int main(int argc, char** argv) {

	Studious::Log::Init();

	auto msg = "Welcome to Studious Engine!";
	ST_CORE_WARN(msg);
	ST_INFO("This is just a Test!");

	auto app = Studious::CreateApplication();
	app->Init();
	app -> Run();
	delete app;
}

#endif