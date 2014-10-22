/*
 @ In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which can slide onto any tower. 
 @ The puzzle starts @with disks sorted in ascending order of size from top to bottom (e.g., each disk sits on top of an even larger one).
 @ You have the following cons @traints:
            (A) Only one disk can be moved at a time.
            (B) A disk is slid off the top of one rod onto the next rod.
            (C) A disk can only be placed on top of a larger disk.
   Write a program to move the disks from the first rod to the last using Stacks.
 */
#include <string>
#include<stack>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
struct Disk
{
  int size;
  Disk(int n=0):size(n){}
};
class Rod{
 private:
  string myName;
  stack<Disk> rod;
public:
 
  Disk pop(){
    Disk a=rod.top();
    rod.pop();
    return a;
  }
  int size(){return rod.size();}
  void push(const Disk& a ){ rod.push(a);}
  bool empty() {return rod.empty();}
  string & name(){return myName;}
  void setName(const char* s){myName=s;}
  Rod& operator=(Rod& other)
  {
    if(&other==this)return *this;
    myName=other.myName;
    rod=other.rod;
    return *this;
  }
};
class TowerHanoi{
  private:
     Rod a;
     Rod b;
     Rod c;
  int numDisks;
  Rod* AssistRod(Rod &src,Rod &dest);
public:
  TowerHanoi(int n):numDisks(n){}
 void  init();
 void gameStart();
 void moveTo(Rod* pSrc,Rod* pDest,int n);
  void dumpAllRod(Rod tmp1,Rod tmp2,Rod tmp3); 
};
void TowerHanoi::dumpAllRod(Rod tmp1,Rod tmp2,Rod tmp3 )
{
  
  cout<<tmp1.name()<<": ";
  while(!tmp1.empty()){cout<<setw(4)<<tmp1.pop().size;}
  cout<<endl;
  cout<<tmp2.name()<<": ";
  while(!tmp2.empty()){cout<<setw(4)<<tmp2.pop().size;}
  cout<<endl;
  cout<<tmp3.name()<<": ";
  while(!tmp3.empty()){cout<<setw(4)<<tmp3.pop().size;}
  cout<<endl;
}
Rod* TowerHanoi::AssistRod(Rod &src,Rod& dest)
{
  if(((src.name()==b.name())&&(dest.name()==c.name()))||
     ((src.name()==c.name())&&(dest.name()==b.name())))
    return &a;
  if(((src.name()==a.name())&&(dest.name()==c.name()))||
     ((src.name()==c.name())&&(dest.name()==a.name())))
    return &b;
  if(((src.name()==a.name())&&(dest.name()==b.name()))||
     ((src.name()==b.name())&&(dest.name()==a.name())))
    return &c;
  return NULL;
}
void TowerHanoi::init()
{
  a.setName("A");
  b.setName("B");
  c.setName("C");
  for(int i=1;i<=numDisks;i++)
    a.push(numDisks-i+1);
}

void TowerHanoi::moveTo(Rod* pSrc,Rod* pDest,int n)
{
  if(!pSrc||!pDest||pSrc->empty())return;
  
  if(n>pSrc->size())return;
  if(1==n)
    {
      pDest->push(pSrc->pop());
      cout<<pSrc->name()<<"------->>>"<<pDest->name()<<endl;
      dumpAllRod(a,b,c);
      return;
    }
  Rod* pAssist=AssistRod(*pSrc,*pDest);
  if(!pAssist)return;
  int num=n;
  for(int i=0;i<num;i++)
    {
      moveTo(pSrc,pAssist,--n);
      pDest->push(pSrc->pop());
      cout<<pSrc->name()<<"------->>>"<<pDest->name()<<endl;
      dumpAllRod(a,b,c);
      swap(pSrc,pAssist);
    }
}
void TowerHanoi::gameStart()
{
  init();
  moveTo(&a,&c,numDisks);
}
int main(int argc, char *argv[])
{
  TowerHanoi newGame(4);
  newGame.gameStart();
  return 0;
}
