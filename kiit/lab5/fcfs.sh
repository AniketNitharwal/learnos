#include <stdio.h>
#include <stdlib.h>

struct p{
    int bt, wt, tat;
    struct p *next;
};

int main(){
    int n,i,time=0;
    struct p *h=NULL,*t=NULL,*nn;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        nn=malloc(sizeof(struct p));
        scanf("%d",&nn->bt);
        nn->next=NULL;
        if(!h) h=t=nn;
        else t->next=nn, t=nn;
    }

    for(t=h;t;t=t->next){
        t->wt=time;
        t->tat=t->wt+t->bt;
        time+=t->bt;
        printf("%d %d %d\n",t->bt,t->wt,t->tat);
    }
    return 0;
}
