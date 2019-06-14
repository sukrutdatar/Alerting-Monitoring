#ifndef _HAWKEYE_SERVER_H_
#define _HAWKEYE_SERVER_H_
#endif

#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/ServerSocketImpl.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>

#include <vector>

using namespace Poco::Net;
using namespace Poco::Util;

class HawkEyeServer : public ServerApplication
{
public:
	HawkEyeServer();
	~HawkEyeServer();

	int main(const std::vector<std::string>& args);
};

class ServerSocketImpl : public Poco::Net::ServerSocketImpl
{

};