#pragma once

#include <string>

class Player
{
public:
	std::string name;
	void SetName(std::string s);
	void SetJob(int jobIndex);
private:
	std::string id;
};


