#include <stack>
#include <vector>
using namespace std;

/*@ Imagine a (literal) stack of plates. If the stack gets too high,
  @ it might topple. Therefore, in real life, we would likely start
  @ a new stack when the previous stack exceeds some threshold.
  @ Implement a data structure SetOfStacks that mimics this.
  @ SetOfStacks should be composed of several stacks, 
  @ and should create a new stack once the previous one exceeds capacity.
  @ SetOfStacks.push() and SetOfStacks.
  @pop() should behave identically to a single stack (that is, pop() should return the same values  @as it would if there were just a single stack).
  @FOLLOW UP
  @Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
*/

class SetOfStacks{
 private:
  int top;
  int threshold;
  int size;
  vector<stack<int>*> stackset;
public:
  int pop();
  void push(int value);
  int popAt(int index);
};
int SetOfStacks::pop()
{
  if(0==size)return 0;
  vector<stack<int>*>::reverse_iterator rIter;
  rIter=stackset.rbegin();
  int v=rIter->pop();
  if(rIter->empty())
    {
      delete *rIter;
      top=++rIter.top();
      stackset.erase(rIter->base());
    }
  size--;
  return v;
 
}
void SetOfStacks::push(int value)
{
  stack *p;
  vector<stack<int>*>::reverse_iterator rIter;
  if(rIter->size()>=threshold)
    {
      if(p=new stack<int>)
	{
	  stackset.push_back(p);
	  p->push(value);
	  size++;
	}
       return;
    }
  rIter->push(value);
  size++;
  top=value;
  return;
}
int SetOfStacks::popAt(int index)
{
  int value=stackset[index]->pop();
  size--;
  return value;
}
