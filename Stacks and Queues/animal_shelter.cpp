#include <iostream>
#include "Queue.h"

// just using 2 separate queues to store dogs and cats separately
// to dequeue, we just compare the peek elements and return the smaller one
struct Shelter
{
    // queue stores entry times of animals as ints
    Queue *dogs, *cats;

    Shelter() : dogs(new Queue()), cats(new Queue()) {}

    void enqueueDog(int entry_time)
    {
        dogs->add(entry_time);
    }

    void enqueueCat(int entry_time)
    {
        cats->add(entry_time);
    }

    int dequeueAny()
    {
        if(!dogs->size)
            return cats->remove();
        if(!cats->size)
            return dogs->remove();
        return dogs->peek() < cats->peek() ? dogs->remove() : cats->remove();
    }

    int dequeueDog()
    {
        return dogs->remove();
    }

    int dequeueCat()
    {
        return cats->remove();
    }
};

int main()
{
    Shelter s;
    s.enqueueDog(2);
    s.enqueueDog(4);
    s.enqueueDog(7);

    s.enqueueCat(1);
    s.enqueueCat(3);
    s.enqueueCat(5);
    s.enqueueCat(9);

    std::cout << s.dequeueAny() << std::endl;
    std::cout << s.dequeueAny() << std::endl;
    std::cout << s.dequeueAny() << std::endl;
    std::cout << s.dequeueAny() << std::endl;
    std::cout << s.dequeueAny() << std::endl;
    std::cout << s.dequeueAny() << std::endl;
    std::cout << s.dequeueAny() << std::endl;
    std::cout << s.dequeueAny() << std::endl;

    s.enqueueDog(2);
    s.enqueueDog(4);
    s.enqueueDog(7);

    s.enqueueCat(1);
    s.enqueueCat(3);
    s.enqueueCat(5);
    s.enqueueCat(9);

    std::cout << std::endl << s.dequeueDog() << std::endl;
    std::cout << s.dequeueDog() << std::endl;
    std::cout << s.dequeueDog() << std::endl;
    std::cout << s.dequeueDog() << std::endl;
    std::cout << s.dequeueCat() << std::endl;
    std::cout << s.dequeueCat() << std::endl;
    std::cout << s.dequeueAny() << std::endl;
    std::cout << s.dequeueAny() << std::endl;
    std::cout << s.dequeueAny() << std::endl;
}