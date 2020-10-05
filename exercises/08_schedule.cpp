#include <iostream>
#include <functional>
#include <thread>

using namespace std;

void schedule(function<void()> task, function<void()> callback) {
    thread t (task);
    t.join();
    callback();
}

int main() {
 
    schedule(
        []{cout << "Task func. \n";},
        []{cout << "Callback func. \n";}
    );
    cout << "Finish. \n";
    return 0;
}
