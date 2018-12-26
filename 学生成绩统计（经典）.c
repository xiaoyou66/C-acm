#include<stdio.h>
int main(){
	int n,i,max=0,num,j,al,k=0;
	int averge[3];
	scanf("%d",&n);
	char name[n][2][100];
	memset(name,0,sizeof(name));
	int score[n][3];
	for(i=0;i<n;i++){
		scanf("%s %s %d %d %d",&name[i][0],&name[i][1],&score[i][0],&score[i][1],&score[i][2]);
		getchar();
	}

	for(i=0;i<3;i++){
		al=0;
		for(j=0;j<n;j++){
			al+=score[j][i];	
		}
		averge[i]=al/n;
	}
	for(i=0;i<n;i++){
		al=0;
		for(j=0;j<3;j++){
			al+=score[i][j];
		}
		if(max<al){
			max=al;
			num=i;
		}
	}
	for(i=0;i<3;i++){
		printf("%d ",averge[i]);		
	}
	printf("\n");
	for(i=0;i<100;i++){
		if(name[num][0][i]==NULL) break;
		printf("%c",name[num][0][i]);
	}	
	printf(" ");
	for(i=0;i<100;i++){
		if(name[num][1][i]==NULL) break;
		printf("%c",name[num][1][i]);
	}
	printf(" %d %d %d\n",score[num][0],score[num][1],score[num][2]);
	return 0;
}
