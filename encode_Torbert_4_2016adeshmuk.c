#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
 char symbol;
 int frequency;
 struct Node* left;
 struct Node* right;
} TreeNode;

int main()
{
  FILE* fin=fopen("encodeIN.txt", "r");
  char rsymb;
  int rasc;
  int rfreq;
  TreeNode* tree[256];
  int filler;
  int recount;
  int refill;
  int outer;
  int inner;
  int tempcount;
  TreeNode* tempnod=NULL;
  TreeNode* tempnoda=NULL;
  TreeNode* root=NULL;
  //root=(TreeNode*)malloc(sizeof(TreeNode));
  //(*root).symbol=''
  int follow;
  int check;
  for(filler=0;filler<256;filler++)
  {
    TreeNode* filla=NULL;
    filla=(TreeNode*)malloc(sizeof(TreeNode));
    filla -> frequency=0;
    filla -> left=NULL;
    filla -> right=NULL;
    (*filla).symbol='*';
    tree[filler]=filla;
  }

  
  while((rsymb=getc(fin))!=EOF)
  {
	//printf("%c", rsymb);
   TreeNode* a=NULL;
   rasc= (int)rsymb;
   a=tree[rasc];
   rfreq=(a->frequency);
   rfreq++;
   a -> frequency=rfreq;
   (*a).symbol=rsymb;
 }
 recount=0;
 for(filler=0;filler<256;filler++)
 {
  TreeNode* filla=tree[filler];
  if(filla->symbol!='*')
  {
    recount++;
  }
}
TreeNode* treeb[recount];
follow=0;
for(refill=0;refill<256;refill++)
{
 if(tree[refill]->symbol!='*')
 {
   treeb[follow]=tree[refill];
   follow++;
 }
}
for(outer=0;outer<recount;outer++)
{
  check=0;
  for(inner=outer;inner<recount;inner++)
  {
    if(treeb[inner]->frequency < treeb[outer]->frequency)
    {
      if(check==0)
      {
        tempnod=treeb[inner];
        tempcount=inner;
        check=1;
      }
      if(treeb[inner]->frequency < tempnod->frequency)
      {
        tempcount=inner;
        tempnod=treeb[inner];
      }
    }
  }
  tempnoda=treeb[tempcount];
  treeb[tempcount]=treeb[outer];
  treeb[outer]=tempnoda;
}  
tempnoda=treeb[recount-1];
treeb[recount-1]=treeb[recount-2];
treeb[recount-2]=tempnoda;
  //create tree with two smallest frequency
  //makes the tree
for(outer=0;outer<recount;outer++)
{
  printf("%d\n", treeb[outer]->frequency);
}
fclose(fin);
return 0;
}