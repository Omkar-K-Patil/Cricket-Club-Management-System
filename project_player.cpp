#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct title
{
	char title[20];
};

title ti[5];

struct player 
{
	int jnum;
	char name[30];
	int run;
	int wi;
	int numm;

	player()
	{
		this->jnum=0;
		strcpy(this->name,"N/A");
		this->run=0;
		this->wi=0;
		this->numm=0;
	}

	player (int jnum,char* name,int run,int wi,int numm)
	{
		this->jnum=jnum;
		strcpy(this->name,name);
		this->run=run;
		this->wi=wi;
		this->numm=numm;
	}

	//Setter
	void setjnum(int jnum)
	{
		this->jnum=jnum;
	}

	void setname(char* name)
	{
		strcpy(this->name,name);
	}

	void setrun(int run)
	{
		this->run=run;
	}

	void setwi(int wi)
	{
		this->wi=wi;
	}
	
	void setnumm(int numm)
	{
		this->numm=numm;
	}

	//Getter
	int getjum()
	{
		return this->jnum;

	}

	char* getname()
	{
		return this->name;
	}

	int getrun()
	{
		return this->run;
	}

	int getwi()
	{
		return this->wi;
	}

	int getnumm()
	{
		return this->numm;
	}



	
};
void titledisplay();
void settitle(title*);
void add(player*);
void display(player*,int);
void displayone(player*,int);
player* top(player*,int);
int search(player*,int);
int remov(player*,int*);
int update(player*,int);
player* addpl(player*,int*);
player *dup(player *,int);
int main()
{
	settitle(ti);
	int c;
	int size=5;
	player *arr=(player*)malloc(sizeof(player)*size);


	add(arr);
	
	
	do{
		system("CLS");//clear screen
	printf("\n------------------------------------------------------------------------------------------\n");
	printf("\t\t| Select Any Operataion |\t\t");
	printf("\n------------------------------------------------------------------------------------------\n");	
	printf("1.Display All Players List\n2.Show Top 3 Players\n3.Search Players\n4.Add New Player\n5.Remove Player Data\n6.Update Player Info\n0.Exit");
	printf("\n------------------------------------------------------------------------------------------\n");
	printf("Select One Choice = ");
	scanf("%d",&c);
		switch(c)
		{
			case 1:
			{		
			    titledisplay();
			    display(arr,size);
			    break;
	    	}
	    	case 2:
	    	{
	    		int i;
	    	    player *temp=top(arr,size);
	    	    printf("  \t\t\t\t | Top 3 Player List | \t\t  ");
	    	    titledisplay();
	    	    display(temp,3);
	    	    break;
			}
			case 3:
			{
				int i;
				i=search(arr,size);
			//	printf("%d",i);
				if(i>=0)
				{
				titledisplay();
				printf("\n%-17d| %-15s | %-15d| %-15d| %-15d",arr[i].jnum,arr[i].name,arr[i].run,arr[i].wi,arr[i].numm);
				printf("\n------------------------------------------------------------------------------------------\n");
				printf("  \t\t\t\t |Player Searching Successfully| \t\t  ");
				printf("\n------------------------------------------------------------------------------------------\n");
					
				}
				if(i==-1)
				{
					printf("  \t\t\t\t |Player Not Found | \t\t  ");
					
				}
			    break;	
			}
			case 4:
			{
				arr=addpl(arr,&size);
				titledisplay();
				display(arr,size);
			    break;	
			}
			case 5:
			{
				int i=remov(arr,&size);
			//	printf("%d",i);
				if(i>=0)
				{
				titledisplay();
				display(arr,size);
				printf("\n------------------------------------------------------------------------------------------\n");
				printf("  \t\t\t\t |Remove Successfully| \t\t  ");
				printf("\n------------------------------------------------------------------------------------------\n");
					
				}
				if(i==-1)
				{
				     printf("  \t\t\t\t |Remove not Successfully Try Again| \t\t  ");	
				}
				break;
			}
			case 6:
			{
				int i=update(arr,size);
				printf("\t%d\t",i);
				
				titledisplay();
				printf("\n%-17d| %-15s | %-15d| %-15d| %-15d",arr[i].jnum,arr[i].name,arr[i].run,arr[i].wi,arr[i].numm);
				printf("\n------------------------------------------------------------------------------------------\n");
				printf("  \t\t\t\t |Update Successfully| \t\t  ");
				printf("\n------------------------------------------------------------------------------------------\n");
				
				//else if(i==-1)
				//{
				  //	printf("  \t\t\t\t |Please Try Agian| \t\t  ");         	
				//}
				
				break;
				
			}
			case 0:{
				break;
			}
			default:
			{
				printf("Invalid choice . Please try again .\n");
				break;
			}	
		}
		if(c!=0){
		printf("\nDo you want to cantinue?\n1.Continue\n0.Exit = ");
		scanf("%d",&c);
		}
		
	  }while(c!=0);
}
void add(player *arr)
{
		arr[0].jnum=45;
		strcpy(arr[0].name,"Rohit");
		arr[0].run=550;
		arr[0].wi=0;
		arr[0].numm=6;
		
		arr[1].jnum=10;
		strcpy(arr[1].name,"Sachin");
		arr[1].run=1000;
		arr[1].wi=3;
		arr[1].numm=6;
		
		arr[2].jnum=18;
		strcpy(arr[2].name,"Virat");
		arr[2].run=524;
		arr[2].wi=2;
		arr[2].numm=6;
		
		arr[3].jnum=33;
		strcpy(arr[3].name,"Bhuvi");
		arr[3].run=15;
		arr[3].wi=12;
		arr[3].numm=6;
		
		arr[4].jnum=55;
		strcpy(arr[4].name,"Shami");
		arr[4].run=30;
		arr[4].wi=15;
		arr[4].numm=6;
}
void display(player *arr,int size)
{
	for(int i=0;i<size;i++)
	{
	printf("\n%-17d| %-15s | %-15d| %-15d| %-15d",arr[i].jnum,arr[i].name,arr[i].run,arr[i].wi,arr[i].numm);
    printf("\n------------------------------------------------------------------------------------------\n");
	}
}
void settitle(title *ti)
{
	strcpy(ti[0].title,"jersey number");
    strcpy(ti[1].title,"Name");
	strcpy(ti[2].title,"Runs");
	strcpy(ti[3].title,"Wickets");
	strcpy(ti[4].title,"Matches played");
}
void titledisplay()
{
		printf("\n------------------------------------------------------------------------------------------\n");
		printf(" %-17s| %-15s | %-15s| %-15s| %-15s|",ti[0].title,ti[1].title,ti[2].title,ti[3].title,ti[4].title);
		printf("\n------------------------------------------------------------------------------------------\n");
}
//void displayone(player *arr,int size)
//{
//		for(i=0;i<size;i++)
//		{
//			printf("\n%d\t%s\t%d\t%d\t%d",arr[i].jnum,arr[i].name,arr[i].run,arr[i].wi,arr[i].numm);
//		} 
//}
player* top(player *arr,int size)
{
	player a;
	player *temp=(player*)malloc(sizeof(player)*size);
	int c,i,j;
	for(i=0;i<size;i++)
	{
		temp[i]=arr[i];
		
	}
	printf("select the one top 3 List : \n1.runs   \n2.wikets = ");
	scanf("%d",&c);
	switch (c)
	{
		case 1:
		{
	    for(i=0;i<size;++i)
	    {
	    	for(j=i+1;j<size;++j)
	    	{
	    		if(temp[i].run < temp[j].run)
	    		{
	    		  a=temp[i];
				  temp[i]=temp[j];
				  temp[j]=a;	
				}
			}
		}
	    return temp;
	    	break;
        }
		case 2:
		{
	    for(i=0;i<size;++i)
	    {
	    	for(j=i+1;j<size;++j)
	    	{
	    		if(temp[i].wi < temp[j].wi)
	    		{
	    		  a=temp[i];
				  temp[i]=temp[j];
				  temp[j]=a;	
				}
			}
		}
		return temp;
		break;	
		}
	}
}
int search(player* arr,int size)
{
	int c;
	printf("\n------------------------------------------------------------------------------------------\n");
	printf("Enter the choice \n1.Search By jersey Number \n2.Search By Name = ");
	scanf("%d",&c);
	printf("\n------------------------------------------------------------------------------------------\n");
	switch (c)
	{
		case 1:
		{
		    int num,x;
	        printf("Enter The jersey Number = ");
        	scanf("%d",&num);
        	printf("\n------------------------------------------------------------------------------------------\n");
	        for(int i=0;i<size;i++)
        	{
		        if(arr[i].jnum==num)
	        	return i;
//	       	    x=i;
		
	        }
	        return -1;
			break;
		}
		case 2:
		{
		    char name[20];
	        int x,j,b,i;
        	printf("Enter the player name = ");
	        scanf("%s",&name);
	       	printf("\n------------------------------------------------------------------------------------------\n");

            for(i=0;i<size;i++)
            {

	           // b=strcasecmp(name,arr[i].name);
	           if(strcasecmp(name,arr[i].name)==0)
	           {
	           	
	            //if(b==0)
	            return i;
        	    break;
			   }
	        }
	        return -1;
	        //x=i;
	       // if(b==0);
	        //{
		       
	          //  return x;
		
	        //}
	        //if(b!=0)
	        //{
		      //  printf("\n---Not Fount---\n");
	        //}
		    
			break;	
        }
	}
}
int remov(player* arr,int *size)
{
	int num,x,i,n;
    int c;
	printf("\n------------------------------------------------------------------------------------------\n");
	printf("Enter the choice \n1.Remove By jersey Number \n2.Remove By Name = ");
	scanf("%d",&c);
	printf("\n------------------------------------------------------------------------------------------\n");
	switch (c)
	{
		case 1:
		{
		    int num,x;
	        printf("Enter The jersey Number = ");
        	scanf("%d",&num);
        	printf("\n------------------------------------------------------------------------------------------\n");
	        for(int i=0;i<*size;i++)
        	{
		        if(arr[i].jnum==num)
		        {
					arr[i]=arr[i+1];
	            	for(int j=i+1;j<*size;j++)
	            	{
	                	arr[j]=arr[j+1];
	            	}
					*size=*size-1; 
					return i;
				}
//				break;
	        }
			return -1; 
				break;  
		}
	    case 2:
		   
		{
		    char name[20];
	        int x,j,b,i;
        	printf("Enter the player name = ");
	        scanf("%s",&name);
	       	printf("\n------------------------------------------------------------------------------------------\n");

//            for(i=0;i<*size;i++)
//            {
//	            b=strcasecmp(name,arr[i].name);
//	            if(b==0)
//        	    break;
//	        }
//	        x=i;
	        for(int i=0;i<*size;i++)
        	{
		        if(strcasecmp(name,arr[i].name)==0)
		        {
//	       	    x=i;
//				arr[i]=arr[i+1];
	            for(int j=i;j<*size;j++)
	            {
	                arr[j]=arr[j+1];
	            }   
		        *size=*size-1;
		        return i;
		        break;
				}
	        }
			return -1; 
			break;	
        }
	
    }
}
int update(player *arr,int size)
{
	int num,x,runs,wicket,matche,c;
	printf("\n-------------------------------------------\n");
	printf("List of all Players = \n");
    titledisplay();
    display(arr,size);
    
    printf("\n------------------------------------------------------------------------------------------\n");
	printf("Enter the choice \n1.jersey Number \n2.Name =   ");
	scanf("%d",&c);
	printf("\n------------------------------------------------------------------------------------------\n");
	switch (c)
	{
		case 1:
		{
		    int num,x;
	        printf("Enter The jersey Number = ");
        	scanf("%d",&num);
	        for(int i=0;i<size;i++)
        	{
		        if(arr[i].jnum==num)
	       	    x=i;
	        }
		        
	            
	            printf("\nEnter the updated info - \nPlayer's Runs, Wickets, and Matches played");
	           	printf("\n------------------------------------------------------------------------------------------\n");
	            printf("\nEnter updated Player's Runs = ");
	            scanf("%d",&runs);
	            printf("\nEnter Updated  Player's wickets = ");
	            scanf("%d",&wicket);	
	            printf("\nEnter Updated a player's matches = ");
	            scanf("%d",&matche);
	
	        	arr[x].run=arr[x].run+runs;
	         	arr[x].wi+=wicket;
	        	arr[x].numm+=matche;
	           	printf("\n------------------------------------------------------------------------------------------\n");
	            
	            return x;
	        
	        
			break;
		}
		case 2:
		{
		    char name[20];
	        int x,j,b,i;
        	printf("Enter the player name = ");
	        scanf("%s",&name);
	       	printf("\n------------------------------------------------------------------------------------------\n");

            for(i=0;i<size;i++)
            {
	            b=strcasecmp(name,arr[i].name);
	            if(b==0)
        	    break;
	        }
	        x=i;
	               
	        if(b==0);
	        {
	        	printf("\nEnter the updated info - \nPlayer's Runs, Wickets, and Matches played");
	           	printf("\n------------------------------------------------------------------------------------------\n");
	            printf("\nEnter updated Player's Runs = ");
	            scanf("%d",&runs);
	            printf("\nEnter Updated  Player's wickets = ");
	            scanf("%d",&wicket);	
	            printf("\nEnter Updated a player's matches = ");
	            scanf("%d",&matche);
	
	        	arr[x].run=arr[x].run+runs;
	         	arr[x].wi+=wicket;
	        	arr[x].numm+=matche;
	           	printf("\n------------------------------------------------------------------------------------------\n");
	            return x;
		
	        }
	        if(b!=0)
	        {
		        printf("\n---Not Fount---\n");
		        return -1;
	        }
		    
			break;	
        }
	}


}
player* addpl(player *arr,int *size)
{
        int num;	
	   	printf("\n------------------------------------------------------------------------------------------\n");
	   	printf("Enter the How Many Player Add in List = ");
	   	scanf("%d",&num);
	   	printf("\n------------------------------------------------------------------------------------------\n");
	   	player *a=dup(arr,*size+num);
	   	for(int i=*size;i<*size+num;i++)
	   	{
	   		printf("Enter the Player jersey Number = ");
	   		scanf("%d",&a[i].jnum);
	   		printf("\nEnter the Player Name = ");
	   		fflush(stdin);
	   		gets(a[i].name);
	   		printf("\nEnter the Player Runs = ");
	   		scanf("%d",&a[i].run);
	   		printf("\nEnter the Player Wickets = ");
	   		scanf("%d",&a[i].wi);
	   		printf("\nEnter the Player Matches played = ");
	   		scanf("%d",&a[i].numm);
			
	    }
	    *size=*size+num;
	    return a;
}
player *dup(player *arr,int size)
{
	player *a=(player*)calloc(sizeof(player),size);
	for(int i=0;i<size;i++)
		a[i]=arr[i];
	return a;
}