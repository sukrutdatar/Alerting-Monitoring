#include "RemoteAgent.h"

RemoteAgent::RemoteAgent(std::string id, std::string auth)
{
	m_Id = id;
	m_AuthKey = auth;
}

RemoteAgent::RemoteAgent(std::string id, std::string auth, std::map<AlertRuleType, AlertRule> usageLimit)
{
	m_Id = id;
	m_AuthKey = auth;
	m_UsageLimits = usageLimit;
}

void RemoteAgent::SetId(std::string id)
{
	m_Id = id;
}

void RemoteAgent::SetAuthKey(std::string key)
{
	m_AuthKey = key;
}

void RemoteAgent::SetUsageLimits(std::map<AlertRuleType, AlertRule> usageLimits)
{
	m_UsageLimits = usageLimits;
}

void RemoteAgent::AddUsageLimit(AlertRuleType type, AlertRule alertRule)
{
	m_UsageLimits[type] = alertRule;
}


RemoteAgent::~RemoteAgent()
{
}
