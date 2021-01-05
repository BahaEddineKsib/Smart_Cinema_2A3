#include "arduino.h"
#include <QDebug>
arduino::arduino()
{data="";
arduino_port_name="";
arduino_is_available = false;
}
QString arduino::getarduino_port_name()
{return arduino_port_name;}
QSerialPort* arduino::getserial()
{return serial;}
int arduino::connect_arduino()
{
    foreach(const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_producy_id){
                arduino_is_available = true;
                arduino_port_name=serial_port_info.portName();
            }
        }
    }
    qDebug()<< "arduino port name is :" << arduino_port_name;
    if(arduino_is_available){
        serial=new QSerialPort();
        serial->setPortName(arduino_port_name);
        qDebug()<< "arduino port name is :" << arduino_port_name;
        if(serial->open(QSerialPort::ReadWrite)) {
           serial->setBaudRate(QSerialPort::Baud115200); // débit:9608 bits/s
           serial->setDataBits(QSerialPort::Data8); //Longueur des données: 8 bits,
           serial->setParity(QSerialPort::NoParity) ;
           serial->setStopBits(QSerialPort::OneStop);
           serial->setFlowControl(QSerialPort::NoFlowControl);

           return 0;
        }
        return 1;
    }
return -1;

}
int arduino::close_arduino(){
    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;
}
int arduino::write_to_arduino(QByteArray d)
{if(serial->isWritable()){
        serial->write(d);//envoyer des données vers Arduino
    }
    else
        qDebug()<<"couldn't write to serial!";
    return 1 ;
    }
QByteArray arduino::read_from_arduino()
{
    if(serial->isReadable()){
        data=serial->readAll();
    return data;}//récupérerles données resues
}


