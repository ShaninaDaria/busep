#include "dummymessages.h"

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
