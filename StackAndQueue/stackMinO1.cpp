/*@ How would you design a stack which, in addition to push and pop, 
  @ also has a function min which  @ returns the minimum element? 
  @ Push, pop and min should all operate in O(1) time.
*/
class TestStack{
priave:
  struct NODE{
    int value;
    int min;
    NODE *next;
    NODE(){next=NULL;}
  };
  NODE* top;
  int size;
public:
  TestStack(){
    top=NULL;
    size=0;
  }
  int pop();
  void push(int value);
  int min(){return top->min;}
};

int TestStack::pop()
{
  if(0==size)return 0;
   int v=top->value;
  NODE*p=top->next;
  delete top;
  top=p;
  size--;
  return v;
}
void push(int value)
{
  NODE* p=new NODE;
  p->value=value;
  p->next=top;
  value<top->min?p->min=value:p->min=top->min;
  top=p;
  size++;
  return;
}
