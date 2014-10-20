#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;



/**
 * This is for array rorate inveriew :
 * Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
 * write a method to rotate the image by 90 degrees. Can *you do this in place?
 * @name  - rorateSqureMatrix90
 * @return -void
 */
void showSquare(int**,int);
void rorateSqureMatrix90(int **a,int n)
{
  int *p=new int[n];
  if(!p)return;
  int start=0;
  int end=n-1;
  int i=0;
  while(start<end)
    {
      memcpy(p,(int*)a+n*start+start,4*(end-start+1));
      //left--->top
      for(i=start;i<=end;i++)
	//a[start][end-(i-start)]=a[i][start];
	*((int*)a+n*start+end-(i-start))=*((int*)a+n*i+start);

      //down--->left
      for(i=start;i<=end;i++)
	//a[i][start]=a[end][i];
        *((int*)a+n*i+start)=*((int*)a+n*end+i);


      //right--->down
      for(i=end;i>=start;i--)
	//a[end][end-(i-start)]=a[i][end];
	*((int*)a+n*end+end-(i-start))=*((int*)a+n*i+end);


      //top--->right
      for(i=end;i>=start;i--)
	//a[i][end]=p[i-start];
	*((int*)a+i*n+end)=p[i-start];
      ++start;
      --end;
    }
  delete []p;
}

void showSquare(int **a,int n)
{
  for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
	cout<<setw(4)<<*((int*)a+n*i+j);
      cout<<endl;
    }
}
int b[4][4]={1,  2,  3,  4,
	     5,  6,  7,  8,
	     9,  10, 11, 12,
             13, 14, 15, 16
};
int main(int argc, char *argv[])
{
  rorateSqureMatrix90((int **)b,4);
  cout<<endl<<endl;
  showSquare((int**)b,4);
  return 0;
}
