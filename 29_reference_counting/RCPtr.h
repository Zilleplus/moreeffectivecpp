#pragma once

// Assumes T is a guy that inherits 
// from the RCObject class.
template <class T>
class RCPtr {
public:
    RCPtr(T* realPtr = 0);
    RCPtr(const RCPtr& rhs);
    ~RCPtr();

    RCPtr& operator=(const RCPtr& rhs);

    T* operator->() const;
    T& operator*() const;

private:
    T* pointee;

    void init();
};

template <class T>
RCPtr<T>::RCPtr(T* realPtr)
    : pointee(realPtr)
{
    init();
}

template <class T>
RCPtr<T>::RCPtr(const RCPtr& rhs)
    : pointee(rhs.pointee)
{
    init();
}

template <class T>
void RCPtr<T>::init()
{
    if (pointee == 0) { // if the dumb pointer is null,
        return;         // so is the smart one.
    }

    if (pointee->isShareable() == false) { 
        // If the value isn't shareable copy it.
        // call copy-ctor that should do deep copy.
        pointee = new T(*pointee); 
    }

    pointee->addReference();
}


template<class T>
RCPtr<T>& RCPtr<T>::operator=(const RCPtr& rhs)
{
    if(pointee!= rhs.pointee){  // Skip assigment
                                // where the value
                                // doesn't change.

        T *oldPointee = pointee;// Save old pointee value.

        pointee = rhs.pointee;  // Point old pointee value
        init();                 // if possible, share it
                                // else make own copy.

        if(oldPointee)
        {
            oldPointee->removeReference(); // Remove the reference to 
                                           // current value.
        }
    }

    return *this;
}

template<typename T>
RCPtr<T>::~RCPtr<T>()
{
    if(pointee)
    {
        pointee->removeReference();
    }
}

template<typename T>
T* RCPtr<T>::operator->() const
{
    return pointee;
}

template<typename T>
T& RCPtr<T>::operator*() const
{
    return *pointee;
}
