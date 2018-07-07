#include <iostream>
#include <thread>

#include <vector>
#include <algorithm>

void thread_f() {
    for (int i =0; i < 10000; i++);
    std::cout << "Thread function execution" << std::endl;

    std::cout << "Inside Function Thread ID = " << std::this_thread::get_id()<<std::endl;
}

class DisplayThread
{
    public:
        void operator ()()
        {
            for (int i =0; i < 10000; i++);
                std::cout << "Thread Object Executing " << std::endl;

            std::cout << "Worker Object Thread ID = " << std::this_thread::get_id()<<std::endl;
        }
};

int main () {

    std::cout << "====== Create Thread as Function =====" << std::endl;

    std::thread threadF(thread_f);
    
    for (int i = 0; i < 10000; i++);
        std::cout << "Display from MainThread" << std::endl;


   std::cout << "===== Create Thread as Object =====" << std::endl;

   std::vector <std::thread> threadList;
   for (int i = 0; i < 10; i++)
       threadList.push_back( std::thread( DisplayThread() ) );

    std::cout << "Display from MainThread" << std::endl;
    std::cout << "Wait all Object Threads to finish " << std::endl;
    std::for_each( threadList.begin(), threadList.end(), std::mem_fn(&std::thread::join));

   std::cout << "===== Create Thread by Lambda =====" << std::endl;

   std::thread threadL([]{
           for (int i =0; i < 10000; i++);
            std::cout << "Display Lambda Thread Execution" << std::endl;

            std::cout << "Inside Lambda Thread ID = " << std::this_thread::get_id()<<std::endl;
        });
   for (int i = 0; i < 10000; i++);
   std::cout << "Display from MainThread" << std::endl;

   threadF.join();
   threadL.join();
   std::cout << "Exiting from MainThread" << std::endl;
  return 0;
}
