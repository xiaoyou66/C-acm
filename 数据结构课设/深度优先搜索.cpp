/****************************88

题目描述
   输入一个图，用邻接矩阵存储（实际上也可以选择邻接表），并实现DFSTraverse操作。
拷贝前面已经实现的代码，主函数必须如下，完成剩下的部分。 
int main()
{
   Graph g;
   CreateUDG(g);
   DFSTraverse(g);
   cout << endl;
   DestroyUDG(g);
   return 0;
}//main 

输入
输入的第一行是两个整数，分别是图的总顶点数n和总边数e 
第二行是n个空格分开的字符串，是顶点的名字，依次对应编号0~n-1。 
随后有e行，每行两个空格分开的顶点名字，表示一条边的两个顶点。 
具体见样例。 

输出
输出图的DFS序列，遍历次序按教材，每个顶点后面跟一个空格。 
具体见样例。 

样例输入
8 9
v1 v2 v3 v4 v5 v6 v7 v8
v1 v2
v1 v3
v2 v4
v2 v5
v3 v6
v3 v7
v4 v8
v5 v8
v6 v7

样例输出
v1 v2 v4 v8 v5 v3 v6 v7 

提示
样例对应教材6.5的图G4（P161图6.17a）

这里被坑了，输入的数据不一定是v开头的，也有可能是数字

******************/
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

int LocateVex(Graph G,char a[])
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i][0]==a[0] &&  G.vexs[i][1]==a[1])
			return i;
	return -1;
}
void CreateUDG(Graph &G)
{
	int i,j,k;
	char v1[3],v2[3];
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;i++)
		cin>>G.vexs[i];
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=0;
	for(k=0;k<G.arcnum;k++)
	{
		scanf("%s %s",&v1,&v2);
		i=LocateVex(G,v1);j=LocateVex(G,v2);
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
	if(G.vexs[v][1])
		cout<<G.vexs[v][0]<<G.vexs[v][1]<<" ";
	else
		cout<<G.vexs[v][0]<<" ";
	//printf("%s ",G.vexs[v]);
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
   system("pause");
   return 0;
}//main 









