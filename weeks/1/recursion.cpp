//Victor Kozel
//This program implements multiple recursive tasks in C++
//including but not limited to printing a decimal integer
//backwards and printing elements of arrays in reverse order

#include <iostream>
#include <string>
using namespace std;

void backInt(int, int);
void writeBackward(string, int);
void writeBackward2(string, int, int);
int sumThrough(int, int);

int main(void) 
{
    //1: Write digits of positive decimal integer backwards
    backInt(12345678,8);
    
    //2(a): Rewrite writeBackward as a C++ function
    string str = "hello";
    writeBackward(str, 5);

    cout << '\n';

    //2(b): Rewrite writeBackward2 as a C++ function
    string str2 = "goodbye";
    writeBackward2(str2, 7, 0);

    cout << '\n';

    //3: Return the sum of the first and last digits inclusive
    cout << sumThrough(3,6) << endl;

    return 0;
}

void backInt(int num, int len)
{
    if (len != 0)
    {
        int print = num%10;
        cout << print;
        backInt((num/10), (len-1));
    }
    else
    {
        cout << endl;
        return;
    }
    return;
}

void writeBackward(string s, int length)
{
    cout << "Enter writeBack with string: " << s << endl;
    if (length != 0)
    {
        cout << "About to write last character of string: " << s << endl;
        cout << s[length-1] << endl;
        //this is just so shortened string gets printed out when the function is first called
        s[length-1] = '\0';
        writeBackward(s, (length-1));
    }
    cout << "Leave writeBack with string s: " <<  s << endl;
    return;
}

void writeBackward2(string s, int length, int index)
{
    cout << "Enter writeBack2 with string: " << s << endl;
    if (index < length)
    {
        writeBackward2(s, length, index+1);
        cout << "About to write first character of string s: " << s << endl;
        cout << s[index] << endl;
    }
    cout << "Leave writeBack2 with string s: " <<  s << endl;
    return;
}

int sumThrough(int first, int last)
{
    if (first <= last)
    {
        int sum = sumThrough((first+1), last);
        return sum + first;
    }
    else
    {
        return 0;
    }
}

/*
*************
SAMPLE OUTPUT
*************
[vkozel2@hills week1]$ ./a.out 
87654321
Enter writeBack with string: hello
About to write last character of string: hello
o
Enter writeBack with string: hell
About to write last character of string: hell
l
Enter writeBack with string: hel
About to write last character of string: hel
l
Enter writeBack with string: he
About to write last character of string: he
e
Enter writeBack with string: h
About to write last character of string: h
h
Enter writeBack with string: 
Leave writeBack with string s: 
Leave writeBack with string s: 
Leave writeBack with string s: h
Leave writeBack with string s: he
Leave writeBack with string s: hel
Leave writeBack with string s: hell

Enter writeBack2 with string: goodbye
Enter writeBack2 with string: goodbye
Enter writeBack2 with string: goodbye
Enter writeBack2 with string: goodbye
Enter writeBack2 with string: goodbye
Enter writeBack2 with string: goodbye
Enter writeBack2 with string: goodbye
Enter writeBack2 with string: goodbye
Leave writeBack2 with string s: goodbye
About to write first character of string s: goodbye
e
Leave writeBack2 with string s: goodbye
About to write first character of string s: goodbye
y
Leave writeBack2 with string s: goodbye
About to write first character of string s: goodbye
b
Leave writeBack2 with string s: goodbye
About to write first character of string s: goodbye
d
Leave writeBack2 with string s: goodbye
About to write first character of string s: goodbye
o
Leave writeBack2 with string s: goodbye
About to write first character of string s: goodbye
o
Leave writeBack2 with string s: goodbye
About to write first character of string s: goodbye
g
Leave writeBack2 with string s: goodbye

18
[vkozel2@hills week1]$ ./a.out 
676354
Enter writeBack with string: salutations
About to write last character of string: salutations
s
Enter writeBack with string: salutation
About to write last character of string: salutation
n
Enter writeBack with string: salutatio
About to write last character of string: salutatio
o
Enter writeBack with string: salutati
About to write last character of string: salutati
i
Enter writeBack with string: salutat
About to write last character of string: salutat
t
Enter writeBack with string: saluta
About to write last character of string: saluta
a
Enter writeBack with string: salut
About to write last character of string: salut
t
Enter writeBack with string: salu
About to write last character of string: salu
u
Enter writeBack with string: sal
About to write last character of string: sal
l
Enter writeBack with string: sa
About to write last character of string: sa
a
Enter writeBack with string: s
About to write last character of string: s
s
Enter writeBack with string: 
Leave writeBack with string s: 
Leave writeBack with string s: 
Leave writeBack with string s: s
Leave writeBack with string s: sa
Leave writeBack with string s: sal
Leave writeBack with string s: salu
Leave writeBack with string s: salut
Leave writeBack with string s: saluta
Leave writeBack with string s: salutat
Leave writeBack with string s: salutati
Leave writeBack with string s: salutatio
Leave writeBack with string s: salutation

Enter writeBack2 with string: farewell
Enter writeBack2 with string: farewell
Enter writeBack2 with string: farewell
Enter writeBack2 with string: farewell
Enter writeBack2 with string: farewell
Enter writeBack2 with string: farewell
Enter writeBack2 with string: farewell
Enter writeBack2 with string: farewell
Enter writeBack2 with string: farewell
Leave writeBack2 with string s: farewell
About to write first character of string s: farewell
l
Leave writeBack2 with string s: farewell
About to write first character of string s: farewell
l
Leave writeBack2 with string s: farewell
About to write first character of string s: farewell
e
Leave writeBack2 with string s: farewell
About to write first character of string s: farewell
w
Leave writeBack2 with string s: farewell
About to write first character of string s: farewell
e
Leave writeBack2 with string s: farewell
About to write first character of string s: farewell
r
Leave writeBack2 with string s: farewell
About to write first character of string s: farewell
a
Leave writeBack2 with string s: farewell
About to write first character of string s: farewell
f
Leave writeBack2 with string s: farewell

36
[vkozel2@hills week1]$ 

*************
SAMPLE OUTPUT
*************
*/