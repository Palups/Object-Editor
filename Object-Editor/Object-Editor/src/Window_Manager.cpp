#include "Window_Manager.h"


Window_Manager::Window_Manager(int state)
{
	m_state = state;
	/*m_file.open("qualquercoisa.txt", ofFile::Mode::WriteOnly, false);
	string frase;
	frase = "boa mulke";
	m_file.write(frase,frase.length);
	m_file.writeFromBuffer()*/

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

