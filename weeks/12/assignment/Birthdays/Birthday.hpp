#ifndef BIRTHDAY_H
#define BIRTHDAY_H

struct Birthday {
    int month;
    int day;

    bool operator==(const Birthday& right) {
        return (month == right.month && day == right.day);
    }

    bool operator<(const Birthday& right) {
        if (month < right.month) {
            return true;
        } else if (month == right.month) {
            if (day < right.day) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool operator>(const Birthday& right) {
        if (month > right.month) {
            return true;
        } else if (month == right.month) {
            if (day > right.day) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool operator=(const Birthday& right) {
        month = right.month;
        day = right.day;
    }
};

#endif