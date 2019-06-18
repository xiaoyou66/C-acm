/**********************************************
题目描述
n个人排成一圈，按顺时针方向依次编号1，2，3…n。从编号为1的人开始顺时针"一二"报数，报到2的人退出圈子。这样不断循环下去，圈子里的人将不断减少。最终一定会剩下一个人。试问最后剩下的人的编号。



要求程序模拟题意来实现。


输入
不超过1000组数据。

每组数据一行，每行一个正整数，代表人数n。 (1 <= n <= 1000)


输出
每组输入数据输出一行, 仅包含一个整数，代表最后剩下的人的编号。


样例输入
7
2

样例输出
7
1

提示
第一组数据出队顺序: 2 4 6 1 5 3
************************************************/
## 方法1
我们可以直接通过创建一个单链表来解决
```
#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

//void PrintLink(LinkList L,int n)
//{
//	LinkList p = L->next;
//	while (n--)
//	{
//		cout << p->data<<" ";
//		p = p->next;
//	}
//	cout <<endl;
//}

int round(int n)
{
	if(n==1) return 1;
	int i,live=n;
	LinkList L=new LNode;
	L->data=1;
	LinkList q=L;
	for(int i=2;i<=n;i++)
	{
		LinkList p=new LNode;
		q->next=p;
		p->data=i;
		q=p;
	}
	q->next=L;
	q=L;
	i=1;
	while(live>1)
	{
		i++;
		if(i%2==0)
		{
			LinkList p=q->next;
			q->next=q->next->next;
			delete p;
			live--;
		}else
			q=q->next;
		//PrintLink(q,live);
	}
	//PrintLink(L);
	return q->data;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
		cout<<round(n)<<endl;
    }
	//system("pause");
}

```
通过单链表不断减小节点数，达到缩小范围的目的。

```
#include<iostream>
using namespace std;

void printnums(int nums[],int n)
{
	for(int i=1;i<=n;i++)
	{
		if(nums[i]==1)
			printf("%d ",i);
	}
	printf("\n");

}
int round(int n)
{
	int i,j,live=n;
	int nums[1000]={1};
	if(n==1) return 1;
	for(i=1;i<=n;i++) nums[i]=1;
	i=1;
	j=0;
	while(live>1)
	{
		if(nums[i]==1)
		{
			j++;
			if(j%2==0)
			{
				nums[i]=0;
				live--;
			}
			i++;
			//printnums(nums,n);
		}else
		{
			while(true)
			{
				i++;
				if(i>n) i=1;
				if(nums[i]==1) break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(nums[i]==1)
			return i;
	}
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
		cout<<round(n)<<endl;
    }
	//system("pause");
}

```
这里使用数组的方式也可以解决这个问题。

原理我这里就不多解释了。








