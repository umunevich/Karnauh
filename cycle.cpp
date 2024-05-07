#include "cycle.h"

void Cycle::push_front(std::string data)
{
    if(this->empty()){
        this->tail = new Node{data, nullptr, nullptr};
        this->tail->next = this->tail;
        this->tail->prev = this->tail;
    }
    // if(this->size() == 1)
    // {
    //     Node* temp = new Node{ data, this->tail, this->tail };
    //     this->tail->next = temp;
    //     this->tail->prev = temp;
    //     // tail <-> temp <-> tail
    // }
    else
    { 
        Node* temp = new Node{ data, this->tail, this->tail->next };
        this->tail->next = temp;
        temp->next->prev = temp;
    }
    ++this->size_;
    // tail <-> temp <-> tail->next <-> tail
}
void Cycle::push_back(std::string data)
{
    if (this->empty()) {
       this->tail = new Node{data, nullptr, nullptr};
       this->tail->next = this->tail;
       this->tail->prev = this->tail;
    }
    // if(this->size() == 1)
    // {
    //     Node* temp = new Node{ data, this->tail, this->tail };
    //     this->tail->next = temp;
    //     this->tail->prev = temp;
    //     // tail <-> temp <-> tail
    // }
    else
    {
        Node* temp = new Node{ data, this->tail->prev, this->tail };
        this->tail->prev = temp;
        temp->prev->next = temp;
    }
    ++this->size_;
    // tail->prev <-> temp <-> tail
    // tail->prev     <->      tail
}

void Cycle::pop_back()
{
    if(this->empty()) return;
    if (this->size() == 1) 
    {
        delete tail;
        return;
    }
    auto prev = tail -> prev;
    this->tail->prev = prev->prev;
    prev->prev->next = this->tail;
    delete prev;
    --this->size_;
   // tail->prev->prev <-> tail->prev <-> tail
}
void Cycle::pop_front()
{
    if(this->empty()) return;
    if(this->size()==1)
    if (this->size() == 1) 
    {
        delete tail;
        return;
    }
    auto next = tail -> next;
    this->tail->next = next->next;
    next->next->prev = this->tail;
    delete next;
    --this->size_;

}

std::string Cycle::get_front()
{
    return this->tail->next->name;
}
std::string Cycle::get_back()
{
    return this->tail->prev->name;
}
std::string Cycle::get_tail()
{
    return this->tail->name;
}


Cycle::Iterator::Iterator(Node* curr_, Node* end_): curr(curr_), last(end_)
{
    this->operator--();
}

bool Cycle::Iterator::operator!=(Iterator second)
{
    return (this->curr->prev != second.curr->prev);
}

std::string& Cycle::Iterator::operator*()
{
    return this->curr->name;
}

Cycle::Iterator& Cycle::Iterator::operator--()
{
    if (this->curr == this->last->next)
    {
        std::cout << "popadaye" << std::endl;
        return *this;
    }
  Iterator * temp = new Iterator(this->curr->prev, this->last);
  return *temp;
}


// Cycle::Iterator& Cycle::Iterator::operator++()
// {

// }
