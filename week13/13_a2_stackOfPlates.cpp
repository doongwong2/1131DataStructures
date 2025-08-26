#include<iostream>
#include<stack>

using namespace std;

class Plates {
public:
    int n;

    Plates(int capacity) {
        n = capacity;
    }

    void push(int val) {

    }

    int pop() {

    }

    int popAtStack(int index) {

    }
};

int main() {
    string s;
    int n;
    cin >> n;
    Plates plate(n);
    while (cin >> s) {
        if (s == "pop")
            cout << plate.pop() << '\n';
        else if (s == "push") {
            cin >> n;
            plate.push(n);
        }
        else if (s == "popAtStack") {
            cin >> n;
            cout << plate.popAtStack(n) << '\n';
        }
    }
    return 0;
}