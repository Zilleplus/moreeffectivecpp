#pragma once

#include "RCObject.h"
#include "RCPtr.h"
#include <cstring>

class String {
    String(const char* value = "");
    const char& operator[](int index) const;
    char& operator[](int index);
private:
    struct StringValue : public RCObject {
        char* data;
        StringValue(const StringValue& rhs);
        StringValue(const char* initValue);
        ~StringValue();
    };

    RCPtr<StringValue> value;
};
