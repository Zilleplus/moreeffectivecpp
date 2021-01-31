#include"RCObject.h"

RCObject::RCObject()
    : refCount(0), shareable() {}

RCObject::RCObject(const RCObject& rhs)
    : refCount(0), shareable(true) {}

RCObject& RCObject::operator=(const RCObject& rhs)
{
    return *this;
}

RCObject::~RCObject(){}

void RCObject::addReference()
{
    ++refCount;
}

void RCObject::removeReference(){
    --refCount;
}

void RCObject::markUnshareable(){
    shareable=false;
}

bool RCObject::isShareable(){
    return shareable;
}

bool RCObject::isShared() const{
    return refCount > 1;
}



