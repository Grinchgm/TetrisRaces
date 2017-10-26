#pragma once
#include <thread>
#include <chrono>

#include "IUserInputCommand.h"
#include "IGameObj.h"
#include "Frame.h"

class Timer : public IGameObj
{
public:
	Timer() {};
	Timer(int timerValue)
		: m_timer(timerValue)
	{

	}
	virtual void calcLeft() {};
	virtual void calcRight() {};
	virtual void calcDown() {};
	virtual void calcForward() {}; // TODO:
	virtual void calcBack() {}; // TODO:

	int getTimerValue() const {
		return m_timer;
	};
private:
	int m_timer;
};

class FrameGenerator
{
	
public:
	FrameGenerator() : m_timer(TimerInitialValue) {}
	bool build()
	{
		//m_currentFrame.buildObstacles();
		return m_currentFrame.checkForCollision();
	}
	
	//void update() { m_frameVizualizer.draw(m_currentFrame); }
	
	void waitForNewCycle()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(m_timer.getTimerValue()));
	}
	
	void fireUserCommand(IUserInputCommand* command) //TODO change speed!!!
	{
		/*switch (event.type())
		{
		case Up:
			m_timer--;
			break;
		case Down:
			m_timer++;
			break;
		case Left:
			m_currentFrame.calculateLeft();
			break;
		case Right:
			m_currentFrame.calculateRight();
			break;
		}*/
		if (command)
		{
			command->proceed(m_timer);
			m_currentFrame.update(command);
		}
		delete command;
	} 
	
public:
	Frame& getCurentFrame() { return m_currentFrame; }
private:
	Timer m_timer;
	Frame m_currentFrame;

	static const int TimerInitialValue = 10;
};