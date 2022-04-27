#include "Studious.h"

class Sandbox : public Studious::Application {

public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Studious::Application* Studious::CreateApplication() {
	return new Sandbox();
}