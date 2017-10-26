#pragma once
#include "FrameGenerator.h"
#include "FrameVizualizer.h"
#include "UserInputController.h"
class Game
{
public:
	Game() 
		: m_frameGenerator(), m_userInputCtrl() {}

	void start()
	{
		while (true)
		{
			m_userInputCtrl.updateUserInput(m_frameGenerator);
			if (!m_frameGenerator.build())
			{
				// TODO: GAME OVER
				break;
			}
			m_frameVizualizer.draw(m_frameGenerator.getCurentFrame());
			m_frameGenerator.waitForNewCycle();
		}
	}

private:
	UserInputController m_userInputCtrl;
	FrameGenerator m_frameGenerator;
	FrameVizualizer m_frameVizualizer;
};