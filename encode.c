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
  FILE* fin=fopen("mobydick.txt", "r");
  char rsymb;
  int rasc;
  int rfreq;
  TreeNode* tree[256];
  int filler;
  for(filler=0;filler<256;filler++)
  {
    TreeNode* filla=NULL;
    filla=(TreeNode*)malloc(sizeof(TreeNode));
    filla -> frequency=0;
    filla -> left=NULL;
    filla -> right=NULL;
    tree[filler]=filla;
  }

  
  while((rsymb=getc(fin))!=EOF)
  {
    if(rsymb=='\n')
    {
      while(1)
      {
	break;
      }
     }
     else
     {
       TreeNode* a=NULL;
       rasc=("%d", rsymb);
       a=tree[rasc];
       rfreq=("%d",a->frequency);
       rfreq++;
       a -> frequency=rfreq;
       (*a).symbol=rsymb;
     }
  }
  return 0;
  fclose(fin);
}