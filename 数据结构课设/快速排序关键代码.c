while(i<j)
{
	while(i<j)
		if(a[j]<=temp){a[i]=a[j];i++;break;}
		else j--;
	while(i<j)
		if(a[i]>=temp){a[j]=a[i];j--;break;}
		else i++;
}
a[i]=temp;
QSort__(a,low,i-1);
QSort__(a,i+1,high);
