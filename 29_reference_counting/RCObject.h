#pragma once

#include <cstddef>

class RCObject {
public:
    RCObject();
    RCObject(const RCObject& rhs);
    RCObject& operator=(const RCObject& rhs);
    virtual ~RCObject() = 0;

    void addReference();
    void removeReference();

    void markUnshareable();
    bool isShareable();

    bool isShared() const;

private:
    std::size_t refCount;
    bool shareable;
};
