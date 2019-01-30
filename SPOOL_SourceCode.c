#include <stdio.h>
#include <stdlib.h>
int checksim(float depth[],int n,int node,int w)//to check if neighboring nodes are similar
{


}
int checknode(float depth[],int n,int node, int w )
    {
        float l,r;
        if(node==1)//extreme left of array
        {
            r=depth[node]-depth[node+1];
            if(r>w)
            {
            depth[node]-=w;
            w=0;//water finishes here
            return;
            }
            if(r<w)
            {
                if(r>0)
                {
                    depth[node]-=r;
                    w=w-r;
                    node=node+1;
                    checknode(depth,n,node,w);

                }
                else
                {
                        node=node+1;
                        checknode(depth,n,node,w);
                }
            }
        }
        if(node==n)//extreme right
        {
            l=depth[node]-depth[node-1];
            if(l>w)
            {
            depth[node]-=w;
            w=0;//water finishes here
            return;
            }
            if(l<w)
            {
                if(l>0)
                {
                    depth[node]-=l;
                    w=w-l;
                    node=node-1;
                    checknode(depth,n,node,w);

                }
                else
                {
                        node=node-1;
                        checknode(depth,n,node,w);
                }
            }
        }

        if(node>1&&node<n)
           {
        l=depth[node]-depth[node-1];
        r=depth[node]-depth[node+1];
           }
        if(l==0&&r!=0)
        {
            checksim(depth,n,node,w); // a function to check similar nodes and its chain (incomplete)
        }
        if(w<=l&&w<=r)
        {
            depth[node]-=w;
            w=0;//water finishes here
            return;
        }
        if(w<=l&&w>r)
        {
            if(r>0)
            {
                depth[node]-=r;
                w=w-r;
                checknode(depth[],n,node,w );
            }
            if(r<0)
            {
                node=node+1;
                checknode(depth,n,node,w);
                return;
            }
        }
        if(w>l&&w<=r)
        {
             if(l>0)
            {
                depth[node]-=l;
                w=w-l;
            }
            if(l<0)
            {
                node=node-1;
                checknode(depth,n,node,w);
            }
        }
        if(w>l&&w>r)
        {
            if((w/2<l&&w/2<r))
            {
                depth[node+1]+=w/2;
                depth[node-1]+=w/2;//water ends
                return;
            }
            if(l<r)
            {
                depth[node]-=l;
                w-=l;
                node=node+1;
                checknode(depth,n,node,w);
            }
            if(r>l)
            {
                depth[node]-=l;
                w-=r;
                node=node-1;
                checknode(depth,n,node,w);
            }

        }
    }

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q,i;
        scanf("%d%d",&n,&q);
        float depth[n+1],sum;

         for(i=1;i<=n;i++)
            scanf("%d",&depth[i]);
            for(i=1;i<=n;i++)
            sum=sum+depth[i];
        while(q--)
        {
            scanf("%d",&type);
            if(type==1)
            {
                scanf("%d%d",&node,&w)//w denotes litres of water
            }
            else{
                scanf("%d",&node);
            }
            if(type==1)
            {
                if(sum<w)//overflow condition
                {
                for(i=1;i<=n;i++)
                 depth[i]=0;
                }
             else
                {
                 checknode(depth,n,node,w); //for query 1
                }

            }
            if(type==2)
            {
                printf("%.10f\n",depth[node]);  //for query 2 , print the depth
            }

        }

