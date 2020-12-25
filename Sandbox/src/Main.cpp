#include "pch.hpp"

#include <BrickEngine.hpp>

using namespace BrickEngine;

int main(int argc, char** argv)
{
	Window* window = Window::Create(640, 480, "This is a window!");
	while (true)
	{
		window->PollEvents();
	}
	return 0;
}
