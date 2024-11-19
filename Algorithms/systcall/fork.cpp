#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int main() {
    pid_t pid = fork(); 
    if (pid < 0) {
        cerr << "Fork failed!" << std::endl;
        return 1;
    } else if (pid == 0) {
        cout << "This is the child process. PID: " << getpid() << std::endl;
    } else {
        cout << "This is the parent process. PID: " << getpid() << std::endl;   
        cout << "Child process ID: " << pid << std::endl;
    }
    return 0;
}
