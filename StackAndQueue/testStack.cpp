#include <iostream>
using namespace std;

int stackSize=300;
int indexUsed=0;
int stackPointer[]={-1,-1,-1};
struct StackNode{
  int previous;
  int value;
  StackNode(int p,int v):previous(v),value(v){}
};
StackNode **buffer;
void push(int stackNum,int value)
{
  int lastIndex = stackPointer[stackNum];
  stackPointer[stackNum] = indexUsed;
  indexUsed++;
  buffer[stackPointer[stackNum]]=new StackNode(lastIndex,value);
}
int pop(int stackNum)
{
  int value = buffer[stackPointer[stackNum]]->value;
  int lastIndex = stackPointer[stackNum];
  stackPointer[stackNum] = buffer[stackPointer[stackNum]]->previous;
  buffer[lastIndex] = NULL;
  indexUsed--;
  return value;
}
int main(int argc, char *argv[])
{
  buffer = new StackNode*[stackSize * 3];
  push(0,1);
  push(1,2);
  push(2,3);
  push(0,4);
  push(1,5);
  push(2,6);
  pop(1);
  push(1,5);
  for(int i=0;i<6;i++)
    if(buffer[i])
      { cout<<buffer[i]->value<<endl;}
    else
      cout<<endl;
  return 0;
}
