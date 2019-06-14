#ifndef _HAWKEYE_ENGINE_H_
#define _HAWKEYE_ENGINE_H_
#endif

#ifndef  _HAWKEYE_REMOTE_AGENT_H_
#include "RemoteAgent.h"
#endif

#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/Document.h>
#include <Poco/DOM/Node.h>
#include <Poco/DOM/NodeList.h>
#include <Poco/DOM/AutoPtr.h>
#include <Poco/SAX/InputSource.h>
#include <Poco/Exception.h>

#include <fstream>
#include <sstream>

using Poco::XML::DOMParser;
using Poco::XML::InputSource;
using Poco::XML::Document;
using Poco::XML::Node;
using Poco::XML::NodeList;
using Poco::XML::AutoPtr;
using Poco::Exception;
using Poco::XML::Element;



class HawkEyeEngine
{
private:
	std::map<std::string, RemoteAgent> m_RemoteAgents;

public:
	HawkEyeEngine();
	~HawkEyeEngine();

	bool LoadConfiguration();
	
private:
	bool ParseNodes(const Element&, const std::string&);
	bool ParseXml(const Element&);
	bool SetAlertValue(Element*, RemoteAgent);
	bool InitAlertManager(Element&);
};

