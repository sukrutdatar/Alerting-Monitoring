#ifndef _HAWKEYE_ALERT_RULE_H_
#define _HAWKEYE_ALERT_RULE_H_
#endif

#ifndef _HAWKEYE_SERVER_LOGGER_H_
#include "HawkEyeServerLogger.h"
#endif

enum AlertRuleType
{
	Undefined = 0,
	Process,
	Memory,
	Cpu
};

class AlertRule
{
private:
	int m_Limit;
	AlertRuleType m_RuleType;

public:
	AlertRule();
	AlertRule(int, AlertRuleType);
	~AlertRule();

	void Set(int, AlertRuleType);
	void SetLimit(int);
	int GetLimit();
	void SetType(AlertRuleType);
	AlertRuleType GetType();
};

