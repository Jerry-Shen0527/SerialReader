#pragma once

#include<vector>

#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息
class SerialReader :public QObject
{
	Q_OBJECT
public:
	SerialReader();
	void init(QString portname);

	double top();
	~SerialReader();

	std::vector<QPointF> raw_data_;

	void clear();
	void set_gpr(int i) { gaps_per_round = i; }

signals:
	void sig();

private slots:
	void serialPort_readyRead();

private:

	int gaps_per_round = 1;

	QSerialPort* serial;
	//float count;

	float true_count_;

	bool first;
	unsigned long beg;
};
