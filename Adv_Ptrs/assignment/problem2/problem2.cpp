#include "MileageTrackerNode.h"
#include <string>
#include <iostream>
using namespace std;

int main () {
    // References for MileageTrackerNode objects
    MileageTrackerNode* headNode;
    MileageTrackerNode* currNode;
    MileageTrackerNode* lastNode;

    double miles;
    string date;
    int i;

    // Front of nodes list
    headNode = new MileageTrackerNode();
    lastNode = headNode;

    // TODO: Read in the number of nodes
    int n_nodes;
    cin >> n_nodes;

    // TODO: For the read in number of nodes, read
    //       in data and insert into the linked list
    cin >> miles;
    cin >> date;
    currNode = new MileageTrackerNode(miles, date);
    headNode->InsertAfter(currNode);
    for (i = 1; i < n_nodes; i++) {
        lastNode = currNode;
        cin >> miles;
        cin >> date;
        currNode = new MileageTrackerNode(miles, date);
        lastNode->InsertAfter(currNode);
    }

    // TODO: Call the PrintNodeData() method
    //       to print the entire linked list
    currNode = headNode->GetNext();
    while (currNode != nullptr) {
        currNode->PrintNodeData();
        currNode = currNode->GetNext();
    }

    // MileageTrackerNode Destructor deletes all
    //       following nodes
    delete headNode;
}
