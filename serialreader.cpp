#include <iostream>
#include <serialreader.h>
#include <QSerialPortInfo>
#include<mainwindow.h>
#include<sstream>
#include<QDebug>

SerialReader::SerialReader() : first(true), true_count_(0)
{
	serial = new QSerialPort;
	//创建串口对象
	//设置串口名

	connect(serial, &QSerialPort::readyRead, this, &SerialReader::serialPort_readyRead);
}

void SerialReader::init(QString portname)
{
	serial->setPortName(portname);
	//serial->setPortName(portname);
	//设置波特率
	serial->setBaudRate(QSerialPort::Baud19200);
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
	QMutex mutex;
	//从接收缓冲区中读取数据
	mutex.lock();
	QByteArray buffer = serial->readAll();
	auto temp = buffer.toStdString();
	//std::string temp = buffer.toStdString();
	std::istringstream istream(temp);

	unsigned long micros;

	if (first == true)
	{
		istream >> micros;
		beg = micros;
		first = false;
	}
	while (istream >> micros) {
		true_count_++;
		raw_data_.emplace_back((micros-beg) / 1000000.0f, true_count_ / std::max(1.0f, float(gaps_per_round)));
	}
	sig();

	mutex.unlock();
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
	//count = 0;
	true_count_ = 0;
	first = true;
}