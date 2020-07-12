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


	connect(serial, &QSerialPort::readyRead, this, &SerialReader::serialPort_readyRead);
}

void SerialReader::init(QString portname)
{
	serial->setPortName(portname);
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
			true_count_++;
			raw_data_.emplace_back(count/1000.0f, true_count_/ std::max(1.0f,float(gaps_per_round)));
			sig();
			e = b;
		}
		e = b;
		count++;
	}

	e = b;
}

double SerialReader::top()
{
	if (!raw_data_.empty())
	{
		return raw_data_.back().x();
	}
	return 0;
}

SerialReader::~SerialReader()
{
	serial->close();
	delete serial;
}

void SerialReader::clear()
{
	raw_data_.clear();
	count = 0;
	true_count_ = 0;
	e = false;
}
