#include "hdr/messageexchange.h"

messageExchange::messageExchange()
{
    IM = new informationMessages();
}

messageExchange::~messageExchange()
{
    delete  IM;
}

void messageExchange::startExchange()
{
    createIS1();
    createIS2();
}

void messageExchange::createIS1()
{
    IM->createIS1();
}

void messageExchange::sendIS1()
{
    // rs485->send(IM->getIS1());
}

void messageExchange::receiveIS3()
{
//     IM->setIS3(rs485->receive());
}

void messageExchange::createIS2()
{
    char number = 0x18;
    IM->createIS2(number);
}

void messageExchange::sendIS2()
{
    // rs485->send(IM->getIS2());
}

void messageExchange::receiveIS4()
{
    // IM->setIS4(rs485->receive());
}
