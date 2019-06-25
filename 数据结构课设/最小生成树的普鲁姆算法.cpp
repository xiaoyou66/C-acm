/*************************88
题目描述
最小生成树问题是实际生产生活中十分重要的一类问题。假设需要在n个城市之间建立通信联络网，则连通n个城市只需要n-1条线路。这时，自然需要考虑这样一个问题，即如何在最节省经费的前提下建立这个通信网。
可以用连通网来表示n个城市以及n个城市之间可能设置的通信线路，其中网的顶点表示城市，边表示两个城市之间的线路，赋于边的权值表示相应的代价。对于n个顶点的连通网可以建立许多不同的生成树，每一棵生成树都可以是一个通信网。现在，需要选择一棵生成树，使总的耗费最小。这个问题就是构造连通网的最小代价生成树，简称最小生成树。一棵生成树的代价就是树上各边的代价之和。
而在常用的最小生成树构造算法中，普里姆（Prim）算法是一种非常常用的算法。 
在本题中，读入一个无向图的数据并存入邻接矩阵，然后用普里姆（Prim）算法建立最小生成树，并输出最小生成树的代价。 


本题不完整程序 

输入
第一行：输入总顶点数ｎ，总边数ｅ，以空格隔开。其中n不超过50，e不超过1000。 
第二行：输入n个顶点的名称（char类型） 
随后输入e行：每行输入1条边依附的顶点及权值，如a b 5 

输出
先输出n-1行，对应构造的最小生成树的n-1条边，格式为“(边端点,边端点):边权值" 
最后输出最小生成树的总代价值，格式为"minCost=总代价值"。请注意行尾输出换行。 

样例输入
6 10
a b c d e f
a b 6
a c 1
a d 5
b c 5
b e 3
c d 5
c e 6
c f 4
d f 2
e f 6

样例输出
(a,c):1
(c,f):4
(f,d):2
(c,b):5
(b,e):3
minCost=15

提示
参考教材P167页的prim算法，图参考P166页的图6.19（a）

这个题目可以直接照着书上的写就行了，就是计算花费哪里要自己写一个函数

********************************/

//算法6.8　普里姆算法
#include <iostream>
using namespace std;

typedef char VerTexType;
typedef int ArcType;
#define MVNum 100
#define MaxInt 32767                    	//表示极大值，即∞

//辅助数组的定义，用来记录从顶点集U到V-U的权值最小的边
struct{
	VerTexType adjvex;						//最小边在U中的那个顶点
	ArcType lowcost;						//最小边上的权值
}closedge[MVNum];

//- - - - -图的邻接表存储表示- - - - -
typedef char VerTexType;              		//假设顶点的数据类型为字符型
typedef int ArcType;                  		//假设边的权值类型为整型
typedef struct{
	VerTexType vexs[MVNum];            		//顶点表
	ArcType arcs[MVNum][MVNum];      		//邻接矩阵
	int vexnum,arcnum;                		//图的当前点数和边数
}AMGraph;

int LocateVex(AMGraph G , VerTexType v){
	//确定点v在G中的位置
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
		return -1;
}//LocateVex

void CreateUDN(AMGraph &G){
    //采用邻接矩阵表示法，创建无向网G
	int i , j , k;
//	cout <<"请输入总顶点数，总边数，以空格隔开:";
    cin >> G.vexnum >> G.arcnum;							//输入总顶点数，总边数

//	cout << "输入点的名称，如a" << endl;
    for(i = 0; i < G.vexnum; ++i){
//		cout << "请输入第" << (i+1) << "个点的名称:";
		cin >> G.vexs[i];                        			//依次输入点的信息
	}

    for(i = 0; i < G.vexnum; ++i)                			//初始化邻接矩阵，边的权值均置为极大值MaxInt
		for(j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = MaxInt;
//	cout << "输入边依附的顶点及权值，如a b 5" << endl;
	for(k = 0; k < G.arcnum;++k){							//构造邻接矩阵
		VerTexType v1 , v2;
		ArcType w;
//		cout << "请输入第" << (k + 1) << "条边依附的顶点及权值:";
		cin >> v1 >> v2 >> w;								//输入一条边依附的顶点及权值
		i = LocateVex(G, v1);  j = LocateVex(G, v2);		//确定v1和v2在G中的位置，即顶点数组的下标
		G.arcs[i][j] = w;									//边<v1, v2>的权值置为w
		G.arcs[j][i] = G.arcs[i][j];						//置<v1, v2>的对称边<v2, v1>的权值为w
	}//for
}//CreateUDN

int Min(AMGraph G){
	//返回权值最小的点
	int i;
	int index = -1;
	int min = MaxInt;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(min > closedge[i].lowcost && closedge[i].lowcost != 0){
			min = closedge[i].lowcost;
			index = i;
		}
	}//for
	return index;
}//Min


int coutcost(AMGraph G,char a,char b)
{
	 int i,j;
	 i=LocateVex(G,a);
	 j=LocateVex(G,b);
	 return G.arcs[i][j];
}

int MiniSpanTree_Prim(AMGraph G, VerTexType u){
    //无向网G以邻接矩阵形式存储，从顶点u出发构造G的最小生成树T，输出T的各条边
	int k , j , i, cnt=0,sum;
	VerTexType u0 , v0;
  //将本函数实现完整 begin
	k=LocateVex(G,u);
	for(j=0;j<G.vexnum;j++)
		if(j!=k){ closedge[j].adjvex=u;closedge[j].lowcost=G.arcs[k][j];}
	closedge[k].lowcost=0;
	for(i=1;i<G.vexnum;i++)
	{
		k=Min(G);
		u0=closedge[k].adjvex;
		v0=G.vexs[k];
		sum=coutcost(G,u0,v0);
		printf("(%c,%c):%d\n",u0,v0,sum);
		cnt+=sum;
		closedge[k].lowcost=0;
		for(j=0;j<G.vexnum;j++)
			if(G.arcs[k][j]<closedge[j].lowcost)
			{
				closedge[j].adjvex=G.vexs[k];
				closedge[j].lowcost=G.arcs[k][j];
			}
	}


  //将本函数实现完整 end

	return cnt;
}//MiniSpanTree_Prim

int main(){
//	cout << "************算法6.8　普里姆算法**************" << endl << endl;
	AMGraph G;
	CreateUDN(G);
//	cout << "******利用普里姆算法构造最小生成树结果：******" << endl;
	cout << "minCost="<< MiniSpanTree_Prim(G , 'a');
	cout << endl;
	//system("pause");
	return 0;
}//main


