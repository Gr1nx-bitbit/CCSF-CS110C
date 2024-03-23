#include <iostream>
using namespace std;

int main(void)
{
    int sum = 0;
    int n = 150;
    int bigO = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = sum + j + i;
            bigO++;
        }
    
    }
    
    cout << bigO << endl;
    return 0;
}