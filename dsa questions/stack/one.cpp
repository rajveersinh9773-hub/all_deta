#include <iostream>
using namespace std;

class one
{

private:
int capacity;
int topSize = 0;
int top = -1;
int *arr;

public:
  one(int capacity){
    this->capacity = capacity;
    this->arr = new int[capacity];
    }

  void push(int value){
    if(top < capacity - 1){
      top++;
      arr[top] = value;
      topSize++;
    } else {
      cout << "Stack is full!" << endl;
    }
  };
  void pop(){
    if(top >= 0){
      top--;
      topSize--;
    } else {
      cout << "Stack is empty!" << endl;
    }
  };
  void peak(){
    if(top >= 0){
      cout<<arr[top]<<endl;
    } else {
      cout << "Stack is empty!" << endl;
    }
  }
  void display(){
   for(int i=top; i>=0; i--){
    cout << arr[i]<<endl;
   }
  };
  void checkSize(){
    if(top == -1){
        cout<<"array is empty"<<endl;
    }else if(top == capacity-1){
        cout<<"array is full"<<endl;
    }else{
        cout<<"array have "<<capacity-top-1<<" elements"<<endl;
    }
  }

  void reset(){
    for(int i=top; i>=0; i--)
    {
      top--;
    }
  }
  void update(int positon,int newvalue){
    this->arr[positon] =newvalue;
  }
  void revers(){
    
  }
};


int main(){
    one stack(5);

    stack.push(10);
    stack.pop();
    stack.peak();
    stack.checkSize();
    stack.display();
    stack.reset();

    return 0;
}