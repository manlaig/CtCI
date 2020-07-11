#include <iostream>
#include <stack>
using namespace std;

void printState(stack<int> s1, stack<int> s2, stack<int> s3)
{
    cout << endl << "Tower 1: ";
    while(!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl << "Tower 2: ";
    while(!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl << "Tower 3: ";
    while(!s3.empty())
    {
        cout << s3.top() << " ";
        s3.pop();
    }
    cout << endl;
}

// This algorithm is O(2^N), N is the number of disks
// Because we make 2 recursive calls to N-1 in each iteration
void move(stack<int>& one, stack<int>& two, stack<int>& three, int count)
{
    if(count == 0)
        return;

    // move n-1 disks to the second tower, so that
    // we can move the largest disk to the last tower
    move(one, three, two, count-1);
    
    // move the largest disk to the last tower
    three.push(one.top());
    one.pop();
    printState(one, two, three);

    // move the n-1 disks from second tower to the last
    move(two, one, three, count-1);
}

void towers_of_hanoi(int N)
{
    stack<int> one, two, three;
    for(int i = N; i > 0; i--)
        one.push(i);
    move(one, two, three, N);
}

int main()
{
    cout << "-------- 3 DISKS --------" << endl;
    towers_of_hanoi(3);
    cout << endl << "-------- 4 DISKS --------" << endl;
    towers_of_hanoi(4);
}