#ifndef _HAWKEYE_REMOTE_AGENT_H_
#define _HAWKEYE_REMOTE_AGENT_H_
#endif

#ifndef _HAWKEYE_ALERT_RULE_H_
#include "AlertRule.h"
#endif

#ifndef _HAWKEYE_SERVER_LOGGER_H_
#include "HawkEyeServerLogger.h"
#endif

#include <iostream>
#include <map>
#include <memory>

class RemoteAgent
{
private:
	std::string m_Id;
	std::string m_AuthKey;

	std::map<AlertRuleType, AlertRule> m_UsageLimits;

public:
	RemoteAgent(std::string, std::string);
	RemoteAgent(std::string, std::string, std::map<AlertRuleType, AlertRule>);
	~RemoteAgent();

	void SetId(std::string);
	void SetAuthKey(std::string);
	void SetUsageLimits(std::map<AlertRuleType, AlertRule>);
	void AddUsageLimit(AlertRuleType, AlertRule);
};

