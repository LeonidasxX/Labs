#include <stdio.h>
#include <string.h>

int main()
{
	char string[30], sub[5];
    int k, flag=0, num=0, opcount=0;
	
	printf("Enter main string ");
	scanf("%[^\n]%*c", string);
    printf("%s", string);
	fflush(stdin);
	printf("Enter substring ");
	scanf("%s",sub);
	
	int m = strlen(string);
	int s = strlen(sub);
	
	for(int i = 0;i<m-s+1;i++)
	{
		k = i;
		flag = 0;
		
		for(int j = 0;j<s;j++)
		{
			if(string[k] != sub[j])
			{
				flag = 1;
				break;
			}
			
			opcount++;
			k++;
		}
		
		if(flag == 0)
			num++;
	}
	
	if(num!=0)
		printf("%d Substring found\n",num);
	
	else
		printf("No substring found");
	
	printf("opcount = %d",opcount);

	return 0;
}