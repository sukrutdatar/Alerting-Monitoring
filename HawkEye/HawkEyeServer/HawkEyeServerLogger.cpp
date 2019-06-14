#ifndef _HAWKEYE_SERVER_LOGGER_H_
#include "HawkEyeServerLogger.h"
#endif


bool HawkEyeServerLogger::s_LoggerCreated = false;

HawkEyeServerLogger::HawkEyeServerLogger(std::string fileName)
{
	Path p(fileName);
	m_FileName = p.getFileName();

	m_LoggerName = "HawkEyeServerLogger";

	if (s_LoggerCreated == false)
	{
		if (CreateLogger())
		{
			s_LoggerCreated = true;
		}
	}
}

HawkEyeServerLogger::~HawkEyeServerLogger()
{
}

bool HawkEyeServerLogger::CreateLogger()
{
	bool success = true;
	try
	{
		AutoPtr<PatternFormatter> patternFormatter(new PatternFormatter());
		patternFormatter->setProperty("pattern", "[%p] [(%U : %u)] [%d-%m-%Y %H:%M:%S]:	%t");


		m_pConsoleChannel = new ConsoleChannel();
		m_pFileChannel = new FileChannel();

		m_pFileChannel->setProperty("path", "HawkEyeServerLog.log");
		m_pFileChannel->setProperty("rotation", "daily");
		m_pFileChannel->setProperty("archive", "timestamp");
		m_pFileChannel->setProperty("compress", "true");


		m_pFormattingChannel = new FormattingChannel(patternFormatter, m_pFileChannel);

		m_pSplitterChannel = new SplitterChannel();
		m_pSplitterChannel->addChannel(m_pConsoleChannel);
		m_pSplitterChannel->addChannel(m_pFormattingChannel);

		Logger::get(m_LoggerName).setLevel(Poco::Message::Priority::PRIO_INFORMATION);

		Logger::get(m_LoggerName).setChannel(m_pSplitterChannel);

		Logger::get(m_LoggerName).trace("Logger created.");
	}
	catch (std::exception& ex)
	{
		success = false;
	}
	return success;
}

Logger& HawkEyeServerLogger::GetLogger()
{
	return Logger::get(m_LoggerName);
}