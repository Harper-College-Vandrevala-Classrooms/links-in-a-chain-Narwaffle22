#include <iostream>

using namespace std;

class ChainLink {
private:
    string color;

public:
    ChainLink() {}
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
    Node(ChainLink);
    Node(ChainLink, Node*);
    Node* getlastNode();
    ChainLink getThisChainLink();
private:
    ChainLink thisItem;
    Node* previousNode;
};
Node::Node() {}
Node::Node(ChainLink newItem) {
    thisItem = newItem;
}
Node::Node(ChainLink newItem, Node* lastNode) {
    thisItem = newItem;
    previousNode = lastNode;
}
Node* Node::getlastNode() {
    return previousNode;
}
ChainLink Node::getThisChainLink() {
    return thisItem;
}

int main() {
    ChainLink link1("Red");
    cout << link1.get_color() << endl;

    ChainLink link2("Blue");
    cout << link2.get_color() << endl;

    ChainLink link3("Yellow");
    cout << link3.get_color() << endl;

    Node node1(link1);
    Node node2(link2, &node1);
    Node node3(link3, &node2);

    // Returns the second ChainLink in the list
    Node* retrieved_node = node3.getlastNode();
    ChainLink retrieved_link = retrieved_node->getThisChainLink();

    cout << retrieved_link.get_color() << endl;

    // Returns the first ChainLink in the list
    Node* another_retrieved_node = node3.getlastNode()->getlastNode();
    ChainLink another_retrieved_link = another_retrieved_node->getThisChainLink();

    cout << another_retrieved_link.get_color() << endl;
}