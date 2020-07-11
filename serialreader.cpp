#include <iostream>
#include <serialreader.h>
#include <QSerialPortInfo>
#include<mainwindow.h>
#include<sstream>
#include<QDebug>

SerialReader::SerialReader() :count(0), e(false)
{
	serial = new QSerialPort;
	//创建串口对象
	//设置串口名
	serial->setPortName("COM7");
	//设置波特率
	serial->setBaudRate(QSerialPort::Baud9600);
	//设置数据位数
	serial->setDataBits(QSerialPort::Data8);
	//设置奇偶校验
	serial->setParity(QSerialPort::NoParity);
	//设置停止位
	serial->setStopBits(QSerialPort::OneStop);
	//设置流控制
	serial->setFlowControl(QSerialPort::NoFlowControl);
	//打开串口
	serial->open(QIODevice::ReadWrite);
	bool status = serial->isOpen();
	std::cout << status << endl;

	connect(serial, &QSerialPort::readyRead, this, &SerialReader::serialPort_readyRead);
}

void SerialReader::serialPort_readyRead()
{
	//从接收缓冲区中读取数据
	QByteArray buffer = serial->readAll();
	std::string temp = buffer.toStdString();
	std::istringstream istream(temp);

	bool b;
	while (istream >> b) {
		if (e == true && b == false)
		{
			rawdata_.push_back(count);
			sig();
		}
		e = b;
		count++;
	}
}

double SerialReader::top()
{
	if (!rawdata_.empty())
	{
		return rawdata_.back();
	}
	return 0;
}

SerialReader::~SerialReader()
{
	serial->close();
	delete serial;
}