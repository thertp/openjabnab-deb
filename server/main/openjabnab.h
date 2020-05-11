#ifndef _OPENJABNAB_H_
#define _OPENJABNAB_H_

#include <QCoreApplication>
#include <QTcpServer>

class OpenJabNab : public QCoreApplication
{
	Q_OBJECT

public:
	OpenJabNab(int argc, char ** argv);
	void Close();
	virtual ~OpenJabNab();

signals:
	void Quit();

private slots:
	void RotateLog();
	void NewHTTPConnection();
	void NewXMPPConnection();

private:
	QTcpServer * httpListener;
	QTcpServer * xmppListener;
	bool httpApi;
	bool httpVioletApi;
};

#endif
