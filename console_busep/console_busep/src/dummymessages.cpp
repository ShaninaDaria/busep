#include "hdr/dummymessages.h"

dummyMessages::dummyMessages()
{
    IM = new informationMessages();
}

dummyMessages::~dummyMessages()
{
    delete  IM;
}

void dummyMessages::setInputsValue()
{

}

void dummyMessages::createIS3()
{
    IM->createIS3();
}

void dummyMessages::createIS4()
{
    IM->createIS4();
}
