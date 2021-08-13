#include <stdio.h>
#include <stdlib.h>
#define size 20
struct stack

{

    int top, data[10];

};
int stack[size],visit[20];
int top=-1;
int n,s;
int b[20][20];
int flag=0;

int main()
{
    int i,j;
    struct stack st;
    st.top=-1;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    printf("Enter adjacency matrix : ");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&b[i][j]);
    }

    for(i=1;i<=n;i++)
        visit[i]=0;

    printf("Enter starting node : ");
    scanf("%d",&s);
    dfs(s,&st);

    return 0;
}

void dfs(int w,struct stack *st)
{
    int v;
    printf("vertex %d\n",w);
    visit[w]=1;

    for(v=1;v<=n;v++)
    {
        if(!visit[v]&&b[w][v]==1)
        {
            push(v,st);

            dfs(v,st);
        }

         pop(st);
    }
  return;
}
void push(int ele,struct stack* st)

{



    if (st->top == size-1) //size -1

    {

        printf("\n");

    }

    st->top++;

    st->data[st->top] = ele;

    printf("\pushed vertex is %d\n", ele);

    return;

}



void pop(struct stack* st)

{



    int ele;

    if (st->top == -1)

    {

        //printf("\n..");

        return;

    }

    ele = st->data[st->top];

    printf("\n popped vertex is %d\n ", ele);

    st->top--;

    return;

}