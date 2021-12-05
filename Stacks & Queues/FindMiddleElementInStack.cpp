#include <bits/stdc++.h>
using namespace std;

class DoublyListNode{
  public:
    int val;
    DoublyListNode* prev;
    DoublyListNode* next;

    DoublyListNode(int x){
      val = x;
      next = prev = NULL;
    }
};

class MyStack{
  DoublyListNode* head;
  DoublyListNode* mid;
  int count;
  public:
    MyStack(){
      DoublyListNode* dummy = new DoublyListNode(-1);
      this->head = dummy;
      this->mid = dummy;
      this->count=0;
    }
    //push
    void push(int x){
      DoublyListNode  *newNode = new DoublyListNode(x);
      newNode->prev = NULL;
      newNode->next = head;

      count++;

      head->prev = newNode;
      head = newNode;
      //if size is 1
      if(count==1)
        mid = newNode;
      else if(count%2==0)
          mid = mid->prev;
    }
    //pop
    int pop(){
      if(count==0){
        cout<<"stack is empty";
        return -1;
      }
      DoublyListNode* temp = head;
      head = head->next;
      if(head)
        head->prev = NULL;
      count--;
      if(count%2==1)
          mid = mid->next;
      int x = temp->val;
      free(temp);
      return x;

    }
    //find middle
    int findMiddle(){
      if(count==0){
        cout<<"stack is empty";
        return -1;
      }
      return mid->val;
    }
    // delete middle
    int deletemiddle(){
      int x = mid->val;
      mid->prev->next= mid->next;
      mid->next->prev = mid->prev;

      DoublyListNode* tempMid = mid;
      count--;

      /* Update the mid pointer when odd
      elements are left in stack */
      if (count % 2 != 0)
      mid = mid->next;
      else
      mid = mid->prev;

      delete tempMid;

      return x;
    } 
};
int main()
{
    /* Let us create a stack using push() operation*/
    MyStack* ms = new MyStack();
    ms->push(11);
    ms->push(22);
    ms->push(33);
    ms->push(44);
    ms->push(55);
    ms->push(66);
    ms->push(77);
 
    cout << "Item popped is " << ms->pop() << endl;
    cout << "Item popped is " << ms->pop() << endl;
    cout << "Item popped is " << ms->pop() << endl;
    cout << "Middle Element is " << ms->findMiddle() << endl;
    cout << "Deleted Middle Element is "<<ms->deletemiddle()<<endl;
    cout << "Middle Element is " << ms->findMiddle() << endl;
    return 0;
}

