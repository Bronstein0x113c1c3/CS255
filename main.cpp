#include <SDL2/SDL.h>
#include <UserLib/test.h>
#include <UserLib/Time.h>
#include <UserLib/Date.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <DSA/Queue.h>

using namespace std;
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Quit();

    Time timeStart(0, 30);
    Time timeEnd(0, 20);
    Time newTime = timeEnd - timeStart;

    std::cout << newTime << std::endl;

    print_hello_world();

    cout << "sdfsdfewrefdsbfdfsefewfsdgdfvwfeqfsefvdfvb" << endl;

    Date d1{"-1/9/2002"};
    cout << d1 << endl;
    // cout<<t.tm_hour<<endl<<t.tm_mon<<endl<<t.tm_wday<<endl<<t.tm_yday<<endl<<t.tm_year;

    std::string time_str = "20 : 10 ";
    Time time(time_str);
    std::cout << time << std::endl;

    cout << "=================================" << endl;
    // test the record!
    string record = "24/02/2016,7:45,12:30";
    for (char &x : record)
    {
        if (x == ',')
        {
            x = ' ';
        }
    }
    stringstream ss(record);
    string day_worked, time_start_work, time_go_home;
    ss >> day_worked >> time_start_work >> time_go_home;
    cout << day_worked << endl
         << time_start_work << endl
         << time_go_home << endl;

    Node<int> *node1 = new Node<int>(10);
    Node<int> nodeTemp1(20, node1);
    Node<int> nodeTemp2(nodeTemp1);

    nodeTemp1.getNextNode()->setValue(30);
    std::cout << nodeTemp2.getNextNode()->getValue() << std::endl;

    Queue<int> nums1 = {1,2,3,4,5,6};
    // nums1.Enqueue(20);
    // nums1.Enqueue(40);
    std::cout << nums1.Dequeue() << std::endl;
    std::cout << nums1.Dequeue() << std::endl;
    std::cout << nums1.Dequeue() << std::endl;
    std::cout << nums1.Dequeue() << std::endl;
    std::cout << nums1.Dequeue() << std::endl;
    std::cout << nums1.Dequeue() << std::endl;
    std::cout << nums1.Dequeue() << std::endl;
    return 0;
}
