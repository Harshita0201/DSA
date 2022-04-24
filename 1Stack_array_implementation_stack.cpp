#include<bits/stdc++.h>
using namespace std;
class Stack{
    public: 
    //properties 
    int size;
    int *arr;
    int top;
    
    //behavior
    Stack(int size){ //constructor
        this->size=size;
        arr=new int[size];
        top=-1; //index of top element
    }
    void push(int element){
        //check if stack is empty, at lest 1 place empty
        if(size-top>1){
            top++; //increase index
            arr[top]=element;
        }else{
            cout << "Stack overflow/ no space" << endl;
        }
    }
    
    void pop(){
        //chekc if at lest one element present
        if(top>=0){
            top--; //decrement top
        }else{
            cout << "Stack underflow/ no element present"  << endl;
        }
    }
    
    int peek(){
        if(top>=0){
            return arr[top];
        }else{
            cout << "Stack is empty " << endl;
            return -1;
        }
        
    }
    
    bool isEmpty(){
        if(top<0){
            return true; // stack is empty
        }else{
            return false; //stack is not empty 
        }
    }
};

int main(){
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.peek() << endl;
    
    st.pop();
    cout << st.peek() << endl;
    
    st.pop();
    cout << st.peek() << endl;
    
    st.pop();
    cout << st.peek() << endl;
    
    if(st.isEmpty()){
        cout << "stack is empty " << endl;
    }else{
        cout << "Stack is not empty" << endl;
    }
    
    st.push(11);
    cout << st.peek() << endl;
    st.push(22);
    cout << st.peek() << endl;
    st.push(33);
    cout << st.peek() << endl;
    st.push(44);
    cout << st.peek() << endl;
    st.push(55);
    cout << st.peek() << endl;
    st.push(66);
    cout << st.peek() << endl;
    st.push(77);
    cout << st.peek() << endl;
    return 0;
}
