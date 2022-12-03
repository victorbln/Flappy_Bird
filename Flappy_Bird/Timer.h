#ifndef _TIMER
#define _TIMER
#include <chrono>

class Timer
{
public:
    Timer() : beg_(clock_::now()) {}//constructor that initialize the "beg_" variable of type "time_point<clock>" which just starts the cronometer

    void reset()//method that resets the clock
    { 
        beg_ = clock_::now();
    }

    double elapsed() const //method that returns the time elapsed from the curent time to the time where the beg_ variable was last initialized...time casted to seconds
    {
        return std::chrono::duration_cast<second_>(clock_::now() - beg_).count();
    }

private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> beg_;//variable which reprezents a time point in our program
};

#endif