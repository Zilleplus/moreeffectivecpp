#include "string.h"

String::StringValue::StringValue(const StringValue& rhs)
{
    data = new char[strlen(rhs.data) + 1];
    strcpy(data, rhs.data);
}

String::StringValue::StringValue(const char* initValue)
{
    data = new char[strlen(initValue) + 1];
    strcpy(data, initValue);
}

String::StringValue::~StringValue()
{
    delete[] data;
}

String::String(const char* value)
    : value(RCPtr<StringValue>(new StringValue(value)))
{
}

const char& String::operator[](int index) const
{
    return value->data[index];
}

char& String::operator[](int index)
{
    if(value->isShareable())
    {
        value = new StringValue(value->data);
    }

    // Operator returns reference, 
    // there is no way to check when the
    // user is modifying the string.
    // So can't share it...
    value->markUnshareable();

    return value->data[index];
}
