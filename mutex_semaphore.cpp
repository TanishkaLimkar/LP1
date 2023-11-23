#include <iostream>
#include <queue>

using namespace std;

struct semaphore
{
    int value;
    queue<int> q;
};

class Semaphore
{
    semaphore s;
    int currItemNum;

public:
    Semaphore()
    {
        s.value = 0;
        currItemNum = 0;
    }
    void getlockvalue()
    {
        cout << "The lock value is " << s.value << endl;
    }
    void getitemcount()
    {
        cout << "The number of items available " << currItemNum << endl;
    }
    void produce()
    {
        char ch;
        do
        {
            s.value = s.value - 1;

            if (s.value < 0)
            {
                s.q.push(currItemNum);
                currItemNum++;
                cout << "Item " << currItemNum << " produced !!" << endl;
            }
            else
            {
                cout << "The thread is busy " << endl;
                return;
            }
            cout << "Do you want to continue (y/n)" << endl;
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }

    void consume()
    {
        char ch;
        do
        {
            if (currItemNum <= 0)
            {
                cout << "No items available" << endl;
                return;
            }

            s.value = s.value + 1;

            if (s.value < 0)
            {
                int val = s.q.front();
                s.q.pop();
                cout << "Item " << val << " consumed" << endl;
                currItemNum--;
            }
            else
            {
                cout << "Thread is busy" << endl;
                return;
            }
            cout << "do you want to continue (y/n)" << endl;
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }
};

class Mutex
{
    int lockstate;
    int currItemNum;

public:
    Mutex()
    {
        lockstate = 0;
        currItemNum = 0;
    }
    void setlockstate()
    {
        lockstate = 1;
    }
    void unsetlockstate()
    {
        lockstate = 0;
    }

    void produce()
    {
        if (lockstate == 1)
        {
            cout << "Thread is busy !!" << endl;
            return;
        }

        setlockstate();
        currItemNum++;

        cout << "Item " << currItemNum << " produced " << endl;

        unsetlockstate();
        lockstate = 0;
    }

    void consume()
    {
        if (lockstate == 1)
        {
            cout << "Thread is busy !!" << endl;
            return;
        }
        setlockstate();

        if (currItemNum <= 0)
        {
            cout << "No items available !!" << endl;
            unsetlockstate();
            return;
        }

        cout << "Item " << currItemNum << " consumed " << endl;
        currItemNum--;
        unsetlockstate();

        lockstate = 0;
    }
};
int main()
{
    cout << "-------------------MUTEX------------------" << endl;
    Mutex mt;
    mt.produce();
    mt.produce();
    mt.consume();
    mt.consume();
    mt.setlockstate();
    mt.produce();

    cout << "----------------------SEMAPHORE----------------------" << endl;
    Semaphore sm;
    sm.produce();
    sm.getlockvalue();
    sm.getitemcount();

    sm.consume();
    sm.getlockvalue();
    sm.getitemcount();

    return 0;
}