#ifndef _PLUGINSLEEP_H_
#define _PLUGINSLEEP_H_

#include <QList>
#include <QMap>
#include <QPair>
#include <QStringList>
#include <QTime>
#include "plugininterface.h"
#include "httprequest.h"
	
class PluginSleep : public PluginInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID OPENJABNAB_PLUGIN_IFACE_VERSION_STRING)
	Q_INTERFACES(PluginInterface)

public slots:
	void OnCronSleep(Bunny *, QVariant);
	void OnCronWakeUp(Bunny *, QVariant);
	
public:
	PluginSleep();
	virtual ~PluginSleep();

	void OnBunnyConnect(Bunny *);
	void OnBunnyDisconnect(Bunny *);
	void OnInitPacket(const Bunny * b, AmbientPacket &, SleepPacket &);

	void InitApiCalls();

	PLUGIN_BUNNY_API_CALL(Api_Sleep);
	PLUGIN_BUNNY_API_CALL(Api_Wakeup);
	PLUGIN_BUNNY_API_CALL(Api_Setup);
	PLUGIN_BUNNY_API_CALL(Api_GetSetup);

private:
	void RegisterCrons(Bunny *);
	void CleanCrons(Bunny *);
	void UpdateState(Bunny *);

	bool IsConfigValid(QList<QVariant> const& wakeupList, QList<QVariant> const& sleepList);
};

#endif
