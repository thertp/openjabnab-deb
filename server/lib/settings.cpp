#include <QCoreApplication>
#include <QDir>
#include <QSettings>
#include <iostream>
#include <cstdlib>
#include "log.h"
#include "settings.h"

GlobalSettings::GlobalSettings()
{
	QDir confdir = SettingsDir();
	QString fileName = confdir.absoluteFilePath("openjabnab.ini");
	if (QFile::exists(fileName))
		settings = new QSettings(fileName, QSettings::IniFormat);
	else
	{
		std::cerr << "Error, openjabnab.ini not found !" << std::endl;
		exit(-1);
	}
}

GlobalSettings::~GlobalSettings()
{
	delete settings;
}


QVariant GlobalSettings::Get(QString const& key)
{
	if (instance->settings->contains(key))
		return instance->settings->value(key);
	else
	{
		LogWarning(QString("Unknown setting : %1").arg(key));
		return QVariant();
	}
}

QVariant GlobalSettings::Get(QString const& key, QVariant const& defaultValue)
{
	if (instance->settings->contains(key))
		return instance->settings->value(key);
	else
		return defaultValue;
}

bool GlobalSettings::HasKey(QString const& key)
{
	return instance->settings->contains(key);
}

GlobalSettings * GlobalSettings::instance = 0;
