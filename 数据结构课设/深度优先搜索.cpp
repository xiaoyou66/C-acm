#include<iostream>
using namespace std;

#define MVNum 100

int visited[MVNum]={0};

typedef struct
{
	char vexs[MVNum][2];
	int arcs[MVNum][MVNum];
	int vexnum,arcnum;
}Graph;

void CreateUDG(Graph &G)
{
	int i,j,k;
	char v1[3],v2[3];
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;i++)
		scanf("%s",&G.vexs[i]);
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=0;
	for(k=0;k<G.arcnum;k++)
	{
		scanf("%s %s",&v1,&v2);
		i=v1[1]-49;j=v2[1]-49;
		//printf("%d %d",i,j);
		G.arcs[i][j]=1;
		G.arcs[j][i]=1;
	}
}			

void printgraph(Graph G)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
			cout<<G.arcs[i][j]<<" ";
		cout<<endl;
	}
}


int FirstAdjvex(Graph G,int v)
{
	int i;
	 for(i=0;i<G.vexnum;i++)
		if(G.arcs[v][i]) return i;
	 return -1;
}


int NextAdjvex(Graph G,int v,int w)
{
  	int i;
	 for(i=w+1;i<G.vexnum;i++)
		if(G.arcs[v][i]) return i;
	 return -1;
}

void DFSTraverse(Graph G,int v)
{
	int w;  
	cout<<"v"<<v+1<<" ";
	visited[v]=1;
	for(w=FirstAdjvex(G,v);w>=0;w=NextAdjvex(G,v,w))
		if(!visited[w]) DFSTraverse(G,w);
}

int main()
{
   Graph g;
   CreateUDG(g);
   DFSTraverse(g,0);
   cout << endl;
   //system("pause");
   return 0;
}//main 
