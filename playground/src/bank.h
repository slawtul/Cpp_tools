#ifndef BANK_STRUCT_H
#define BANK_STRUCT_H

#include <iostream>


struct Logger
{
	virtual void log()=0;
	virtual ~Logger()=default;
};

struct ConsoleLogger:Logger
{
	void log() override
	{
		std::cout<<"transaction logged in a console...\n";
	}

	~ConsoleLogger()
	{
		std::cout<<"ConsoleLogger destructor launched\n";
		std::cout<<"Cool! Correct ending...\n";
	}
};

struct FileLogger:Logger
{
	void log() override
	{
		std::cout<<"transaction logged in a file...\n";
	}

	~FileLogger()
	{
		std::cout<<"FileLogger destructor launched\n";
	}
};

struct Bank
{
	Bank(Logger* logger):logger{logger}
	{
	};

	void make_transfer()
	{
		std::cout<<"making transfer...\n";
		logger->log();
	}

	void set_logger(Logger* new_logger)
	{
		logger=new_logger;
	}

private:
	Logger* logger;
};

#endif // BANK_STRUCT_H
