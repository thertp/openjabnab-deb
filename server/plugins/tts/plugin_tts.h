#ifndef _PLUGINTTS_H_
#define _PLUGINTTS_H_

#include "apimanager.h"
#include "plugininterface.h"

class PluginTTS : public PluginInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID OPENJABNAB_PLUGIN_IFACE_VERSION_STRING)
	Q_INTERFACES(PluginInterface)

public:
	PluginTTS();
	virtual ~PluginTTS() {};

	// API
	void InitApiCalls();
	PLUGIN_BUNNY_API_CALL(Api_Say);

private:
};

#endif
