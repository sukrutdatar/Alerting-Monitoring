#ifndef _HAWKEYE_SERVER_LOGGER_H_
#define _HAWKEYE_SERVER_LOGGER_H_
#endif

#include<string>

#include <Poco/Logger.h>
#include <Poco/SplitterChannel.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/FileChannel.h>
#include <Poco/AutoPtr.h>
#include <Poco/SharedPtr.h>
#include <Poco/PatternFormatter.h>
#include <Poco/FormattingChannel.h>
#include <Poco/Path.h>


using Poco::Logger;
using Poco::SplitterChannel;
using Poco::ConsoleChannel;
using Poco::FileChannel;
using Poco::AutoPtr;
using Poco::SharedPtr;
using Poco::PatternFormatter;
using Poco::FormattingChannel;
using Poco::Path;

class HawkEyeServerLogger
{
private:
	AutoPtr<FileChannel> m_pFileChannel;
	AutoPtr<ConsoleChannel> m_pConsoleChannel;
	AutoPtr<SplitterChannel> m_pSplitterChannel;
	AutoPtr<FormattingChannel> m_pFormattingChannel;

	std::string m_LoggerName;
	std::string m_FileName;

	static bool s_LoggerCreated;

private:
	bool CreateLogger();

public:
	HawkEyeServerLogger(std::string fileName);
	Logger& GetLogger();
	~HawkEyeServerLogger();
};

