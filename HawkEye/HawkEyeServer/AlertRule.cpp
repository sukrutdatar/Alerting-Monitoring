#ifndef _HAWKEYE_ALERT_RULE_H_
#include "AlertRule.h"
#endif

AlertRule::AlertRule()
{
}

AlertRule::AlertRule(int limit = -1, AlertRuleType type = AlertRuleType::Undefined)
{
	m_Limit = limit;
	m_RuleType = type;
}

void AlertRule::Set(int limit, AlertRuleType type)
{
	m_Limit = limit;
	m_RuleType = type;
}

void AlertRule::SetLimit(int limit)
{
	m_Limit = limit;
}

void AlertRule::SetType(AlertRuleType type)
{
	m_RuleType = type;
}

int AlertRule::GetLimit()
{
	return m_Limit;
}

AlertRuleType AlertRule::GetType()
{
	return m_RuleType;
}

AlertRule::~AlertRule()
{
}
