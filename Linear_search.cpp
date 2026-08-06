#include <stdio.h>
int n,s,i=0;
int main(){
	printf("Enter array size ");
	scanf("%d",&n);int a[n];
	printf("Enter elements ");
	for( ;i<n;i++) scanf("%d",&a[i]);
	printf("Enter key ");
	scanf("%d",&s);
	int f=0;
	while(--i>=0){
		if(a[i]==s){printf("\nElement found at %d ",i+1);f++;}
	}
	if(f==0)printf("Key not found");
	return 0;
}
