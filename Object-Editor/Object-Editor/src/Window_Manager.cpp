#include "Window_Manager.h"



Window_Manager::Window_Manager()
{
}


Window_Manager::~Window_Manager()
{
}

int Window_Manager::GetState()
{
	return m_state;
}

void Window_Manager::SetState(int state)
{
	m_state = state;
}
