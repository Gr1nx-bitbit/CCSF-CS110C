#ifndef PATIENT_H
#define PATIENT_H

#include <string>

struct Patient {
    std::string name;
    int priority;

    bool operator<(const Patient& after)
    { return (priority < after.priority); }

    bool operator>(const Patient& after)
    { return (priority > after.priority); }

    bool operator==(const Patient& after)
    { return priority == after.priority; }
};



#endif