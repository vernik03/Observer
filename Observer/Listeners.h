#pragma once
#include <Windows.h>
#include <fstream>
#include <time.h>
#include <iostream>
#include <set>


class Listener
{
public:
	Listener() {};
	virtual ~Listener() {};

	virtual void GetFlag(bool flag) {};

private:
};

class ChangeColor : public Listener
{
public:
	ChangeColor(std::string in_output_text) : output_text(in_output_text) {};
	~ChangeColor() {};

	void GetFlag(bool flag) override;

private:
	const std::string output_text;
};

class WriteLog : public Listener
{
public:
	WriteLog() : filename("log.txt") {
		time_in = time(0);
		time_out = time(0);
	};
	~WriteLog() {};

	void GetFlag(bool flag) override;

private:
	time_t time_in;
	time_t time_out;
	std::ofstream log_file;
	const std::string filename;

};