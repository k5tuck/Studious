#pragma once

#include "Core.h"

namespace Studious {

	class Studious_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Init();
			void Run();
	};

	Application* CreateApplication();
}

