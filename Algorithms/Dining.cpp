#include <bits/stdc++.h>
using namespace std;
const int NUM_PHILOSOPHERS = 5;
const int MAX_ITERATIONS = 5;
mutex chopsticks[NUM_PHILOSOPHERS];

void philosopher(int id)
{
    for (int i = 0; i < MAX_ITERATIONS; i++)
    {
        cout << "Philosopher " << id << " is thinking." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Philosopher " << id << " is hungry." << endl;
        if (id % 2 == 0)
        {
            unique_lock<mutex> leftLock(chopsticks[id]);
            unique_lock<mutex> rightLock(chopsticks[(id + 1) % NUM_PHILOSOPHERS]);
        }
        else
        {
            unique_lock<mutex> rightLock(chopsticks[(id + 1) % NUM_PHILOSOPHERS]);
            unique_lock<mutex> leftLock(chopsticks[id]);
        }
        cout << "Philosopher " << id << " is eating." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    cout << "Philosopher " << id << " has finished." << endl;
}
int main()
{
    thread philosophers[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i)
    {
        philosophers[i] = thread(philosopher, i);
    }
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i)
    {
        philosophers[i].join();
    }
    return 0;
}