/*******************88
题目描述
   输入一个图，用邻接表存储（实际上也可以选择邻接矩阵），并实现BFS操作。 
拷贝前面已经实现的代码，主函数必须如下，完成剩下的部分。 
int main()
{
   Graph g;
   CreateUDG(g);
   BFS(g, 0);//从0号顶点开始遍历
   DestroyUDG(g);
   return 0;
}//main 

输入
输入的第一行是两个整数，分别是图的总顶点数n和总边数e 
第二行是n个空格分开的字符串，是顶点的名字，依次对应编号0~n-1。 
随后有e行，每行两个空格分开的顶点名字，表示一条边的两个顶点。 
具体见样例。 

输出
输出图的BFS序列，遍历次序按教材，每个顶点后面跟一个空格。 
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
v1 v2 v3 v4 v5 v6 v7 v8 

提示
样例对应教材6.5的图G4（P161图6.17a）

这个也很简单，直接利用我们上次写的函数，然后在加上一个队列的使用就行了！
广度优先搜索可以看书上写的

***********************/
#include<iostream>
using namespace std;

#define MVNum 100
#define MAXQSIZE 100

int visited[MVNum]={0};

typedef struct
{
	char vexs[MVNum][2];
	int arcs[MVNum][MVNum];
	int vexnum,arcnum;
}Graph;

typedef struct
{
	int *base;
	int front;
	int rear;
}sqQueue;


bool InitQueue(sqQueue &Q)
{

	Q.base = new int[MAXQSIZE];
	if (!Q.base) return false;
	Q.front = Q.rear = 0;
	return true;
}


bool EnQueue(sqQueue &Q, int e)
{
	
	if ((Q.rear + 1) % MAXQSIZE == Q.front) return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return true;

}

bool DeQueue(sqQueue &Q, int &e)
{
	if (Q.front == Q.rear) return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return true;

}


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

void BFS(Graph G,int v)
{
	int w; 
	if(G.vexs[v][1])
		cout<<G.vexs[v][0]<<G.vexs[v][1]<<" ";
	else
		cout<<G.vexs[v][0]<<" ";
	visited[v]=1;
	sqQueue Q;
	int u;
	InitQueue(Q);
	EnQueue(Q,v);
	while(Q.front!=Q.rear)
	{
		DeQueue(Q,u);
		for(w=FirstAdjvex(G,u);w>=0;w=NextAdjvex(G,u,w))
			if(!visited[w])
			{
				 	if(G.vexs[w][1])
						cout<<G.vexs[w][0]<<G.vexs[w][1]<<" ";
					else
						cout<<G.vexs[w][0]<<" ";
					visited[w]=1;
					EnQueue(Q,w);
			}
	}



}

int main()
{
   Graph g;
   CreateUDG(g);
   BFS(g, 0);
   cout << endl;
  // system("pause");
   return 0;
}//main 



