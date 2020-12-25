#pragma once

#define BRICKENGINE_ENTRYPOINT(CLASS_NAME, ...) \
	int main(int argc, char** argv) \
	{ \
		::BrickEngine::Application* app = new CLASS_NAME(__VA_ARGS__); \
		app->Run(); \
		delete app; \
		return 0; \
	}
