#pragma once

//class UserInputEvent
//{
//protected:
//	enum InputType
//	{
//		Up = 72,
//		Down = 80,
//		Left = 75,
//		Right = 77
//	};
//
//public:
//	UserInputEvent(int UserInput = 0) {
//		switch (UserInput)
//		{
//		case Up:
//			m_inputType = Up;
//			break;
//		case Down:
//			m_inputType = Down;
//			break;
//		case Left:
//			m_inputType = Left;
//			break;
//		case Right:
//			m_inputType = Right;
//			break;
//		}
//	}
//
//	enum InputType type() { return m_inputType; }
//
//private:
//	InputType m_inputType;
//};


#include "IGameObj.h"

class NoInput : public IUserInputCommand
{
public:
	virtual void proceed(IGameObj& gameObj)
	{
		gameObj.calcDown();
	}
};

class Left : public IUserInputCommand
{
public:
	virtual void proceed(IGameObj& gameObj)
	{
		gameObj.calcLeft();
	}
};

class Right : public IUserInputCommand
{
public:
	virtual void proceed(IGameObj& gameObj)
	{
		gameObj.calcRight();
	}
};

class Forward : public IUserInputCommand
{
public:
	virtual void proceed(IGameObj& gameObj)
	{
		gameObj.calcForward();
	}
};

class Back : public IUserInputCommand
{
public:
	virtual void proceed(IGameObj& gameObj)
	{
		gameObj.calcBack();
	}
};