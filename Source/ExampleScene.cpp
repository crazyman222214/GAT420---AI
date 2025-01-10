#include "ExampleScene.h"

bool ExampleScene::Initialize()
{
	m_renderer.Initialize();
	m_renderer.CreateWindow("Example", 800, 600);

	m_input.Initialize();
	m_input.Update();

	m_framebuffer = std::make_unique<Framebuffer>(m_renderer, m_renderer.m_width, m_renderer.m_height);

	return true;
}

void ExampleScene::Draw()
{
	m_framebuffer->Clear(color_t{ 0, 0, 0, 255});

	for (int i = 0; i < 10000000; i++)
	{
		color_t randColor = {rand() % 255, rand() % 255, rand() % 255, 255};
		m_framebuffer->DrawPoint(rand() % 800, rand() % 600, randColor);
	}

	// update framebuffer
	m_framebuffer->Update();

	// show screen
	m_renderer = *m_framebuffer;
	SDL_RenderPresent(m_renderer.m_renderer);
}
