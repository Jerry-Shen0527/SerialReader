#pragma once

#include<vector>

#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息
class SerialReader :public QObject
{
	Q_OBJECT
public:
	SerialReader();
	double top();
	~SerialReader();

signals:
	void sig();

private slots:
	void serialPort_readyRead();

private:

	QSerialPort* serial;
	size_t count;
	bool e;

	std::vector<size_t> rawdata_;
};
