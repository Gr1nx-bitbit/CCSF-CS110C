#ifndef PERSON_H
#define PERSON_H

#include "Birthday.hpp"
#include <string>

class Person {
	private:
		std::string name;
		Birthday birthday;
	public:
		Person(void);
		Person(std::string name, Birthday birthday);
		std::string getName(void);
		Birthday getBirthday(void);
	 	void setName(std::string name);
		void setBirthday(Birthday birthday);
		void operator=(const Person&);
		bool operator==(const Person&);
		bool operator==(Person*);
};

#endif
