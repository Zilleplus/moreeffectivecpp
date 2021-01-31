#include<cstddef>

// Not as simple as it looks -> pay attention to numObjects and maxObjects.
 
template <typename BeingCounted>
class Counted {
public:
    class TooManyObjects {
    };

    static std::size_t objectCount() { return numObjects; }

protected:
    Counted();
    Counted(const Counted& rhs);
    ~Counted() { --numObjects; }

private:
    static std::size_t numObjects; // needs init value
    static const std::size_t maxObjects; // needs init value
    void init();
};

template<typename T>
Counted<T>::Counted(const Counted&) { init(); }

template<typename T>
Counted<T>::Counted() { init(); }

template<typename T>
void Counted<T>::init()
{
    if(this->numObjects >= maxObjects) throw TooManyObjects();
    this->numObjects++;
}

class Printer : private Counted<Printer> {
    public:
        static Printer* makePrinter();
        static Printer* makePrinter(const Printer* rhs);
        ~Printer();

        using Counted<Printer>::TooManyObjects;
        using Counted<Printer>::objectCount;
    private:
        Printer();
        Printer(const Printer& rhs);

};

template<>
const std::size_t Counted<Printer>::maxObjects  = 3;

template<typename T>
std::size_t Counted<T>::numObjects = 0;

Printer::Printer(){}

Printer* Printer::makePrinter()
{
    return new Printer();
}

int main() { 
    Printer* a = Printer::makePrinter();
    return 0; 
}
