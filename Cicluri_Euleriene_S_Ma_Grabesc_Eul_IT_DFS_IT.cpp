#include<iostream>
#include<fstream>
using namespace std;
int G[100][100];
int n;
int C1[10000];
int nc1;
int C2[10000];
int nc2;
int V[100];
int grades[100];

int read_data()
{
    ifstream f;
    f.open("CicluriEulerieneinput.txt");
    f>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f>>G[i][j];
        }
    }
    f.close();
}
int show_data()
{
    for(int i=1;i<=n;i++)
    {
        cout<<endl;
        for(int j=1;j<=n;j++)
        {
            cout<<G[i][j]<<" ";
        }
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<grades[i]<<" ";
    }
    cout<<endl;
}
int insertion(int C1[],int *nc1,int C2[],int nc2,int k)
{
// in interiorul vectorului C1 de dim nc1 in pozitie k
// inserez continutului vectorului C2 de dim nc2
// => deplasare , insertie
int i=1;
while(i<=nc2)
    {
        C1[nc1+1]=C1[k];
        C1[k]=C2[i];
        k++;
        i++;
    }
}
int init_data()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(G[i][j]==1)
            {
                grades[i]=grades[i]+1;
            }
        }
    }

}
int explore(int G[100][100],int n,int node,int solution[100])
{
// parcurge DFS graful G cu n noduri  incepand cu nod "node"
// lista nodurilor parcurse pana la inchiderea ciclului urmand a
// fi depusa in 'solution'
// att : decrementez gradele nodurilor prin care trec
}

int euler()
{
// strategie ma grabesc , iterativ , dfs iterativ
// caut prim nod nevizitat ( pentru a porni explorare din el )
int gasit=1;
while  (gasit==1)
  {
        gasit=0;
        for(int i=1;i<=n;i++)
        {
            if ( V[i]==0 ) {   int counter;
                                    counter=explore(G,n,i,C1);
                                    for (int j=1;j<=counter;j++)
                                       {
                                            if (grades[C1[j]]>0) {
                                                int numbers;
                                                numbers=explore(G,n,j,C2);
                                                insertion(C1,&counter,C2,numbers,j);
                                                                }
                                       }
                                }
        }
  }
}

int print_data()
{
    int i=1;
    while(C1[i]!=0)
    {
        cout<<C1[i]<<" ";
        i++;
    }
}

int main()
{
read_data();
init_data();
euler();
print_data();
//show_data();
}
