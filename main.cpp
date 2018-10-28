#include <iostream>
#include<stdlib.h>
#include <stdio.h>

using namespace std;

int o;

struct queue{
int rear=-1;
int front=-1;
int arr[50];
}timefree;


void enqueue(queue &q,int item){
if (q.front==-1){
    q.front++;
}
q.rear+=1;

q.arr[q.rear]=item;
}


int dequeue(queue &q){
    int ret=q.arr[q.front];
    q.front++;
    return ret;
}


int minn(int a[],int n){
int i;
int x=0;
int minn;
minn=a[0];
for(i=0;i<n;i++){
        if (a[i]<minn){
            minn=a[i];
            x=i;
        }
}
return x;
}

int main(){

    cout<<"* * * * * Welcome to Desk Duty Assigner * * * * *"<<endl;
    int ch=1;


   int studfree[7]={0,0,0,0,0,0,0};
   int miniassign;
   int n;
   cout<<"Enter the number of students ";
   cin>>n;
   int assigned[n];
   int timesave[7][n];
   int i;
   for (i=0;i<n;i++){
    assigned[i]=0;
   }
   int j=0;
   int h;
   int st_input;
   int studentlist[n][7];     /*array with timings of all students separately*/
   int index;
   int stud_no;
   int time_slot;

int nine=-1;
int ten=-1;
int eleven=-1;
int two=-1;
int three=-1;
int four=-1;
int five=-1;
int ff=9;
int gg=2;
int w;

int k;

int c;
int assignindex;
int finalarr[7];

/*Taking user input for each student to know his free time slots*/

   for(i=0;i<n;i++){
     cout<<"Enter details of student "<<i+1<<": ";
     j=0;
     st_input=1;
     while (st_input!=0){
        cin>>st_input;
        if(st_input!=0){
            studentlist[i][j]=st_input;
            j+=1;

        }
     }
     enqueue(timefree,j);
    }




/*Taking input ends here*/


 for(i=0;i<n;i++){
    w=dequeue(timefree);
    for(j=0;j<w;j++)
    {                                                     /*saving students to time array*/
        if (studentlist[i][j]==9){
                timesave[0][++nine]=i+1;
        }

        else if (studentlist[i][j]==10){
                timesave[1][++ten]=i+1;
        }

        else if (studentlist[i][j]==11){
                timesave[2][++eleven]=i+1;
        }

        else if (studentlist[i][j]==2){
                timesave[3][++two]=i+1;
        }

        else if (studentlist[i][j]==3){
                timesave[4][++three]=i+1;
        }

        else if (studentlist[i][j]==4){
                timesave[5][++four]=i+1;
        }

        else if (studentlist[i][j]==5){
                timesave[6][++five]=i+1;
        }

        }
    }



studfree[0]=nine+1;
studfree[1]=ten+1;
studfree[2]=eleven+1;
studfree[3]=two+1;
studfree[4]=three+1;
studfree[5]=four+1;
studfree[6]=five+1;


int tempcount[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//for 9
int temp1=studfree[0];

for(i=0;i<temp1;i++){
    tempcount[i]=(timefree.arr[timesave[0][i]-1])-1;
}
int mini=minn(tempcount,studfree[0]);
finalarr[0]=timesave[0][mini];
assigned[timesave[0][mini]-1]+=1;
//for 9 ends here

//for10


//for rest
for(j=1;j<7;j++){
        index=0;
        assignindex=0;
        miniassign=assigned[timesave[j][0]-1];
    for(i=0;i<studfree[j];i++){
    tempcount[i]=(timefree.arr[timesave[j][i]-1])-1;
}
    mini=tempcount[0];

    for(k=0;k<studfree[j];k++){
        if(tempcount[k]<mini){
            mini=tempcount[k];
            index=k;
        }
    }
    for(c=0;c<studfree[j];c++){
        if(assigned[timesave[j][c]-1]<miniassign){
            miniassign=assigned[timesave[j][c]-1];
            assignindex=timesave[j][c]-1;
            assignindex=timesave[j][c]-1;
        }
    }

    for(i=index;i<studfree[j];i++){
        if(tempcount[i]==mini){
            if(assigned[timesave[j][i]-1]==miniassign)
                finalarr[j]=timesave[j][i];
                assigned[timesave[j][i]-1]+=1;
                break;
        }
    }


}

while(1){
        cout<<"\n"<<"1.) Print the desk duties assigned"<<endl;
        cout<<"2.) Know time slots of a particular student"<<endl;
        cout<<"3.) Students which are free at a particular time slot"<<endl;
        cout<<"0.) Exit";
cin>>ch;
switch(ch){
case 1:
    for(i=0;i<3;i++){
    cout<<"From"<<ff<<" to "<<ff+1<<": "<<"Student "<<finalarr[i]<<endl;
    ff+=1;
}

for(i=3;i<7;i++){
    cout<<"From"<<gg<<" to "<<gg+1<<": "<<"Student "<<finalarr[i]<<endl;
    gg+=1;
}
break;

case 2:
    cout<<"Enter student's number: ";
    cin>>stud_no;
    for(i=0;i<timefree.arr[stud_no-1];i++){
        cout<<studentlist[stud_no-1][i]<<endl;
    }
    break;

case 3:
    cout<<"Enter time slot: ";
    cin>>time_slot;
    if(time_slot==9){
        for(i=0;i<studfree[0];i++){
            cout<<timesave[0][i]<<endl;
        }
    }
    if(time_slot==10){
        for(i=0;i<studfree[1];i++){
            cout<<timesave[1][i]<<endl;
        }
    }

    if(time_slot==11){
        for(i=0;i<studfree[2];i++){
            cout<<timesave[2][i]<<endl;
        }
    }

    if(time_slot==2){
        for(i=0;i<studfree[3];i++){
            cout<<timesave[3][i]<<endl;
        }
    }

    if(time_slot==3){
        for(i=0;i<studfree[4];i++){
            cout<<timesave[4][i]<<endl;
        }
    }

    if(time_slot==4){
        for(i=0;i<studfree[5];i++){
            cout<<timesave[5][i];
        }
    }

    if(time_slot==5){
        for(i=0;i<studfree[6];i++){
            cout<<timesave[6][i]<<endl;
        }
    }
    break;
case 0:
    exit;
default :
    cout<<"Wrong choice";
    }
}
}
