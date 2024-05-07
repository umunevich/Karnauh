#pragma once

#include <iostream>

class Cycle
{
    struct Node
    {
        std::string name;
        Node * prev;
        Node * next;
    };

    Node * tail = nullptr;
    size_t size_ = 0;

public:
    Cycle() = default;
    Cycle(const Cycle&) = delete;
    Cycle & move(Cycle&&) = delete;
    Cycle operator& (const Cycle&) = delete;
    Cycle operator&& (Cycle &&) = delete;

    size_t size() { return this->size_; }
    bool empty() { return size() == 0; }

    void push_front(std::string);
    void push_back(std::string);

    void pop_back();                 
    void pop_front();    

    std::string get_front();
    std::string get_back();
    std::string get_tail();

    class Iterator
    {
        Node* curr;
        Node* last;

    public:
        Iterator(Node*, Node*);
        //Iterator(const Iterator&) = delete;
        Iterator& move(Iterator&&) = delete;
        Iterator operator&(const Iterator&) = delete;
        Iterator operator&&(Iterator&&) = delete;

        bool operator!=(Iterator);
        std::string& operator*();

        Iterator& operator--();
        Iterator& operator++();
    };

    Iterator start() { return Iterator(tail, tail); }

    Iterator end() { return Iterator(tail->prev, tail); }      

    //~Cycle();


};