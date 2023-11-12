#include <bits/stdc++.h>
using namespace std;

class LRU
{
    int capacity;
    int pagefault;
    vector<int> v;
    deque<int> q;
    deque<int>::iterator itr;

public:
    LRU()
    {
        capacity = 0;
        pagefault = 0;
        q.clear();
    }
    LRU(int c)
    {
        capacity = c;
        pagefault = 0;
        q.clear();
    }
    void input()
    {
        int n;
        cout << "Enter the number of pages" << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int p;
            cout << "Enter the element :" << endl;
            cin >> p;
            v.push_back(p);
        }
    }
    void func()
    {
        for (int i = 0; i < v.size(); i++)
        {
            itr = find(q.begin(), q.end(), v[i]);

            if (!(itr != q.end()))
            {
                pagefault++;
                if (q.size() == capacity)
                {
                    q.erase(q.begin());
                    q.push_back(v[i]);
                }
                else
                {
                    q.push_back(v[i]);
                }
            }
            else
            {
                q.erase(itr);
                q.push_back(v[i]);
            }
        }
        cout << "The number of page faults : " << pagefault << endl;
    }
    void display()
    {
        cout << "the queue is currently : " << endl;

        for (int i = 0; i < capacity; i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

class FIFO
{
    int capacity;
    int pagefault;
    unordered_set<int> s;
    vector<int> v;
    deque<int> q;

public:
    FIFO()
    {
        capacity = pagefault = 0;
    }
    FIFO(int c)
    {
        capacity = c;
        pagefault = 0;
    }
    void input()
    {
        int n;
        cout << "ENTER THE NUMBER ROF PAGES";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int p;
            cout << "ENTER THE ELEMENTS : " << endl;
            cin >> p;
            v.push_back(p);
        }
    }
    void func()
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (s.size() < capacity)
            {
                if (s.find(v[i]) == s.end())
                {
                    s.insert(v[i]);
                    pagefault++;
                    q.push_back(v[i]);
                }
            }
            else
            {
                if (s.find(v[i]) == s.end())
                {
                    int val = q.front();
                    q.erase(q.begin());
                    s.erase(val);
                    s.insert(v[i]);
                    pagefault++;
                    q.push_back(v[i]);
                }
            }
        }
        cout << "The number of pagefaults are : " << pagefault << endl;
    }
    void display()
    {
        cout << "The current queue is : ";
        for (int i = 0; i < capacity; i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};
class optimal
{
    int capacity;
    int pagefault;
    deque<int> q;
    vector<int> v;
    unordered_set<int> s;

public:
    optimal()
    {
        capacity = pagefault = 0;
    }
    optimal(int c)
    {
        capacity = c;
        pagefault = 0;
    }
    void input()
    {
        int p;
        cout << "ENTER THE NUMBER OF PAGES : " << endl;
        cin >> p;

        for (int i = 0; i < p; i++)
        {
            int n;
            cout << "ENTER THE ELEMENTS" << endl;
            cin >> n;
            v.push_back(n);
        }
    }
    void func()
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (s.size() < capacity)
            {
                if (s.find(v[i]) == s.end())
                {
                    s.insert(v[i]);
                    pagefault++;
                    q.push_back(v[i]);
                }
            }
            else
            {
                if (s.find(v[i]) == s.end())
                {
                    int farthest = -1, idx = -1;

                    for (int j = 0; j < q.size(); j++)
                    {
                        int nextoccurence = INT_MAX;

                        for (int k = i + 1; k < v.size(); k++)
                        {
                            if (v[k] == q[j])
                            {
                                nextoccurence = k;
                                break;
                            }
                        }
                        if (nextoccurence == INT_MAX)
                        {
                            idx = j;
                            break;
                        }
                        if (nextoccurence > farthest)
                        {
                            farthest = nextoccurence;
                            idx = j;
                        }
                    }
                    int val = q[idx];
                    q.erase(q.begin() + idx);
                    s.erase(val);
                    s.insert(v[i]);
                    pagefault++;
                    q.push_back(v[i]);
                }
            }
            cout << "Number of pagefaults : " << pagefault << endl;
        }
    }
    void display()
    {
        cout << "The current queue is : ";
        for (int i = 0; i < capacity; i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};
int main()
{

    while (true)
    {
        int ch;
        cout << "1)LRU " << endl;
        cout << "2)FIFO " << endl;
        cout << "3)OPTIMAL " << endl;

        cout << "ENTER YOUR CHOICE" << endl;
        cin >> ch;

        if (ch == 1)
        {
            cout << "--------------------Least Recently Used Algorithm--------------------" << endl;
            int c1;
            cout << "Enter the capacity of the pages\n";
            cin >> c1;
            LRU l(c1);
            l.input();
            l.func();
            l.display();
        }
        else if (ch == 2)
        {
            cout << "-----------------------First In First Out Algorithm-----------------------" << endl;
            int c1;
            cout << "Enter the capacity of the pages\n";
            cin >> c1;
            FIFO f(c1);
            f.input();
            f.func();
            f.display();
        }
        else if (ch == 3)
        {
            cout << "-----------------------OPTIMAL-----------------------" << endl;
            int c1;
            cout << "Enter the capacity of the pages\n";
            cin >> c1;
            optimal o(c1);
            o.input();
            o.func();
            o.display();
        }
        else
        {
            cout << "Choose valid option" << endl;
            break;
        }
    }
    return 0;
}