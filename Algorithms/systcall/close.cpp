#include <bits/stdc++.h>
#include <fcntl.h>

using namespace std;
int main() {
    const char*file = "example.txt";
    int fileDescriptor = open(file, O_WRONLY | O_CREAT, 0644);

    if (fileDescriptor < 0) {
        cout << "Failed to open the file";
        return 1;
    }
    cout << "File opened successfully. File descriptor: " << fileDescriptor <<endl;
    int val = close(fileDescriptor);
    if(val < 0) {
        cout << "Falied to close the file";
        return 0;
    }
    cout << "Successfully closed the file";
}


