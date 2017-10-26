#pragma once

class IGameObj;

class IUserInputCommand
{
public:

	virtual void proceed(IGameObj& gameObj) = 0;
};
