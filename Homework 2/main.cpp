
/*
* Title: Trees
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 2
* Description:
*/


#include <iostream>
#include "BinarySearchTree.h"
#include "BinaryNode.h"
#include "analyze.h"
#include <cstddef>
#include <iostream>
using namespace std;
int main() {

    BinarySearchTree tree;
    //BinarySearchTree bst(50);
/*
    tree.add(50);
    tree.add(20);
    tree.add(10);
    tree.add(90);
    tree.add(70);
    tree.add(60);
    tree.add(80);
    tree.add(30);
    tree.inorderTraverse();

    cout<< tree.getHeight()<< endl;
    cout<< tree.successor(10)<< endl;
    cout<< tree.successor(50)<< endl;
    cout<< tree.successor(70)<< endl;
    cout<< tree.successor(40)<< endl;
    cout<< tree.successor(90)<< endl;
    cout<< tree.getWidth() << endl;
    cout<< tree.getNumberOfNodes() <<endl;
    cout<< tree.count(10,70)<< endl;
    cout<< tree.select(30) <<endl;
    cout<< tree.select(50) <<endl;
    cout<< tree.select(10) <<endl;
    tree.remove(50);
    tree.remove(20);
    tree.remove(10);
    tree.remove(90);
    tree.inorderTraverse();

    tree.remove(70);
    tree.remove(60);
    tree.remove(80);
    tree.inorderTraverse();
    tree.remove(30);
*/
    //bst.add(50);
    BinarySearchTree bst = BinarySearchTree();
    std::cout << bst.add(50) << std::endl;
    bst.inorderTraverse();
    std::cout << bst.add(80) << std::endl;
    bst.inorderTraverse();
    std::cout << bst.add(40) << std::endl;
    bst.inorderTraverse();
    std::cout << bst.add(30) << std::endl;
    bst.inorderTraverse();
    std::cout << bst.add(60) << std::endl;
    bst.inorderTraverse();
    std::cout << bst.add(45) << std::endl;
    bst.inorderTraverse();
    std::cout << bst.add(42) << std::endl;
    bst.inorderTraverse();
    std::cout << bst.add(1000) << std::endl;
    bst.inorderTraverse();
    std::cout << bst.add(55) << std::endl;
    bst.inorderTraverse();
    std::cout << bst.add(-10) << std::endl;
    bst.inorderTraverse();
    std::cout << bst.add(100) << std::endl;
    bst.inorderTraverse();
    std::cout << bst.add(100) << std::endl;
    std::cout << bst.add(-100) << std::endl;
    bst.inorderTraverse();
    std::cout << "--------------------" << std::endl;
    std::cout << bst.contains(-10) << std::endl;
    std::cout << bst.contains(10) << std::endl;
    std::cout << bst.contains(100) << std::endl;
    std::cout << bst.contains(1000) << std::endl;
    std::cout << bst.contains(0) << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << bst.count(5, 15) << std::endl;
    std::cout << bst.count(5, 100) << std::endl;
    std::cout << bst.count(-20, 0) << std::endl;
    std::cout << bst.count(-20, 100000) << std::endl;
    std::cout << bst.count(-10, 40) << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "--------------------" << std::endl;
    bst.inorderTraverse();
    std::cout << bst.successor(10) << std::endl;
    std::cout << bst.successor(100) << std::endl;
    std::cout << bst.successor(-10) << std::endl;
    std::cout << bst.successor(50) << std::endl;
    std::cout << bst.successor(60) << std::endl;
    std::cout << bst.successor(40) << std::endl;
    std::cout << bst.successor(1000) << std::endl;
    std::cout << "--------------------" << std::endl;
    bst.inorderTraverse();
    std::cout << bst.select(-100) << std::endl;
    std::cout << bst.select(-10) << std::endl;
    std::cout << bst.select(40) << std::endl;
    std::cout << bst.select(42) << std::endl;
    std::cout << bst.select(45) << std::endl;
    std::cout << bst.select(50) << std::endl;
    std::cout << bst.select(55) << std::endl;
    std::cout << bst.select(60) << std::endl;
    std::cout << bst.select(100) << std::endl;
    std::cout << bst.select(1000) << std::endl;

    std::cout << bst.getWidth() << std::endl;
    std::cout << "--------------------" << std::endl;
    bst.inorderTraverse();
    bst.remove(40);
    bst.inorderTraverse();
    bst.remove(-100);
    bst.inorderTraverse();
    bst.remove(-10);
    bst.inorderTraverse();
    bst.remove(1000);
    bst.inorderTraverse();
    bst.remove(50);
    bst.inorderTraverse();
    bst.remove(60);
    bst.inorderTraverse();
    bst.remove(100);
    bst.inorderTraverse();
    //analyzeBST();

    return 0;

}

