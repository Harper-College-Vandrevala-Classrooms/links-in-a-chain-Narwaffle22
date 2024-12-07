#include <iostream>

using namespace std;

class ChainLink {
private:
    string color;

public:
    ChainLink(string color) {
        this->color = color;
    }

    string get_color() {
        return this->color;
    }
};

class Node {
public:
    Node();

private:
    ChainLink item1;
    ChainLink item2;
    ChainLink item3;
};

Node::Node() {
}

int main() {
    cout << "Hello World!\n";
}