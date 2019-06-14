#include <iostream>
#include <exception>

#ifndef _HAWKEYE_SERVER_LOGGER_H_
#include "HawkEyeServerLogger.h"
#include "HawkEyeServer.h"
#endif


int main()
{
	Logger& logger = HawkEyeServerLogger(__FILE__).GetLogger();
	try
	{
		
	}
	catch (std::exception& ex)
	{
		logger.fatal("Exception: ", ex.what());
	}

	return 0;
}

HawkEyeServer::HawkEyeServer()
{
}


HawkEyeServer::~HawkEyeServer()
{
}
