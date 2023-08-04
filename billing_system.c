#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
#define MAX_USERNAME 30
#define FILE_NAME "DETAILS_CUSTOMER.bin"
#define MAX_CUSTOMER_ADDRESS 150
typedef struct
{  
  int  customer_id;
  char customer_name[MAX_USERNAME];
  char customer_address[MAX_CUSTOMER_ADDRESS];
  char customer_ph[20];
  char customer_city[MAX_CUSTOMER_ADDRESS];
}customer;
void addCustomers();
int isValid(char *s);
int ispValid(char *n);
void  viewCustom_detail();
void message(char *message)
{
	int len=0;
	int pos=0;
	len=(80-strlen(message))/2;
	printf("\t\t\t");
	for(pos=0;pos<len;pos++)
	{
		printf("");
	}
	printf("%s\n",message);
}

//part2

/*declaration of checking functions*/
void c_code(char[]);
int check(char[]);

/*structure declaration*/
typedef struct
{
    char name[20],code[12];
    float rate;
    int quantity;

} r;
r item;

void d_mainmenu();
void func();
void bill() ;
void add();
void del();
void exit();
void dbill();
void display(r *item,int i,int j);
void dis_con();

/*declaration of display submenu functions*/

void d_all();

void main()
{
	int choice=0;
	do
	{
		system("cls");
		message("\n\t\t\t\t-----MAIN MENU------");
		printf("\n\n\n\t\t\t1.Add customer detail");
		printf("\n\t\t\t2.view customer details");
		printf("\n\t\t\t3.Cart");
		printf("\n\t\t\t0.Exit");
		printf("\n\n\n\t\t\tEnter choice => ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			       addCustomers();
				   main();
				   break;
			case 2: 
			        viewCustom_detail();
					break;
			case 3:
                    d_mainmenu();			
			        break;
					break;
			case 0:
			       printf("\n\n\n\t\t\t\t Thank you!!!\n\n\n");
				   exit(1);
				   break;
			default:
			    printf("\n\n\n\t\t\t\tINVALID INPUT!!!");
		}
	}
	while(choice!=0);
}
//add customer details
void addCustomers()
{
	
	customer info ={0};
	FILE *fp = NULL;
	int status = 0;
	fp = fopen(FILE_NAME,"ab+");
	if(fp == NULL)
	{
		printf("File not opened\n");
		exit(1);
	}
system("cls");
message("-------ADD CUSTOMER DETAILS:--------");
printf("\n\n\n\t\t\tENTER CUSTOMER DETAILS BELOW:");
printf("\n\t\t\t--------------------------------------------------------------------------------\n");
printf("\n\t\t\tCustomer ID NO =");
fflush(stdin);
scanf("%d",&info.customer_id);
do{
		printf("\n\t\t\tCustomer name = ");
		fflush(stdin);
		fgets(info.customer_name,MAX_USERNAME,stdin);
		status = isValid(info.customer_name);
        if(status==0)	
		{
			printf("\n\t\t\t Name contain invalid character.Please enter again.\n");
			
		}
		
	  }while(!status);
do{
		printf("\n\t\t\tCustomer address = ");
		fflush(stdin);
		fgets(info.customer_address,MAX_CUSTOMER_ADDRESS ,stdin);
		status=isValid(info.customer_address);
        if(status==0)	
		{
			printf("\n\t\t\t Address contain invalid character.Please enter again.");
			
		}
		
}while(!status);
do{
		printf("\n\t\t\t Phone Number = ");
		fflush(stdin);
		fgets(info.customer_ph,20,stdin);
		status = ispValid(info.customer_ph);
        if(status==0)	
		{
			printf("\n\t\t\t Invalid phone number.Please enter again.\n");
			
		}
		
	  }while(!status);
do{
		printf("\n\t\t\tCity = ");
		fflush(stdin);
		fgets(info.customer_city,MAX_CUSTOMER_ADDRESS ,stdin);
		status=isValid(info.customer_city);
        if(status==0)	
		{
			printf("\n\t\t\t Address contain invalid character.Please enter again.");
		}
			
		}while(!status);
fwrite(&info,sizeof(info),1,fp);
fclose(fp);
}
int isValid(char *s)
{
	int valid=0;
	int len=0;
	int index=0;
	len=strlen(s);
	for(index=0;index<len;++index)
	{
		if(isalpha(s[index]) && (s[index]!='\n') && (s[index]!=' '))
		{
			valid = 1;
			break;
			
		}
	}
	return valid;
}
int ispValid(char *n)
{
	int valid=0;
	int len=0;
	int index=0;
	len=strlen(n);
	for(index=0;index<len;++index)
	{
		if(isdigit(n[index]) && len==11  && (n[index]!=' '))
		{
			valid = 1;
			break;
			
		}
	}
	return valid;
}
void  viewCustom_detail()
{
	customer info ={0};
	int found=0;
	FILE *fp = NULL;
	int status =0;
	int countCustomer = 1;
	system("cls");
	message("VIEW CUSTOMER DETAIL");
	fp=fopen(FILE_NAME,"rb");
	if(fp==NULL)
	{
		printf("File is not opened\n");
		exit(1);
	}
	if(fseek(fp,0,SEEK_SET)!=0)
	{
		fclose(fp);
		printf("issue");
		exit(1);
	}
	while(fread(&info,sizeof(info),1,fp))
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t-----------------CUSTOMER  = %d\n\n",countCustomer);
		printf("\n\n\t\tCustomer ID NO= %d",info.customer_id);
		printf("\n\n\t\tCustomer Name = %s",info.customer_name);
		printf("\n\t\tCustomer Adress = %s",info.customer_address);
		printf("\n\t\tCity           = %s",info.customer_city);
		printf("\n\t\tphone number = %s",info.customer_ph);
		found = 1;
		++countCustomer;
	}
	fclose(fp);
	if(!found)
	{
		printf("\n\t\t\t No account created");
		
	}
	printf("\n\n\t\t\t Enter a key to go back to  main menu...");
	fflush(stdin);
	getchar();
	main();
} 


void d_mainmenu()
{
    int i,option;
    char ch;
    const char *menu[]= {"\n1.Calculate Bill","2.Add Records","3.Delete Records","4.Display","5.Exit","\0"};
    system("cls");

    printf("MAIN MENU");
    for (i=0; i<=5; i++)
    {
        
        printf("%s\n\n\n",menu[i]);
    }
    func();
    
}





void func()
{
	int choice;
	printf("Select a choice:");
	scanf("%d",&choice);
	if(choice==1)
	{
		bill();
	}
	else if(choice == 2)
	{
        add();
	}
    else if(choice==3)
    {
        del();
		
	}
	else if(choice==4)
	{
		d_all();
	}
	else
		exit(0);
	
	
}	


void d_search()
{
    char ch;
    int i;
    const char *menu[]= {"   By Code","   By Rate","   By Quantity","   Back to main menu"};
    system("cls");

    printf("SEARCH MENU");
    for (i=0; i<=3; i++)
    {
       
        printf("%s\n\n\n",menu[i]);
    }
  
}


void add ()
{
    FILE *file;
    char y[25],x[12];
    system("cls");

    printf("Enter new record(Y/N)?");
    while(toupper(getche())=='Y')
    {
        system("cls");
        file=fopen("record.txt","ab");
        c_code(y);
        strcpy(item.code,y);
        
        printf("\nEnter rate of the item:");
        scanf("%f",&item.rate);
       
        printf("\nEnter quantity of the item:");
        scanf("%d",&item.quantity);
       
        printf("\nEnter name of the item:");
        scanf("%s",item.name);
        fseek(file,0,SEEK_END);
        fwrite(&item,sizeof(item),1,file);
        fclose(file);
        
        printf("Enter new record(Y/N)?");
		

    }
    d_mainmenu();
}

void c_code(char y[])
{
    int flag;
    FILE *f;
    f=fopen("record.txt","rb");
    while(1)
    {
        system("cls");
        
        printf(" ADD ARTICLES \n")  ;
        flag=1;
        rewind(f);
        
        printf("Enter new code of the article:");
		fflush(stdin);
        scanf(" %[^\n]",y);
        while(fread(&item,sizeof(item),1,f)==1)
        {
            if (strcmp(y,item.code)==0)
            {
                flag=0;
                
                printf("\ncode already exists\n");
                
                printf("\nTo enter again press any key\n");
                getch();
                break;
            }
        }
        if (flag==1)
            break;
    }
}


void del()
{
	int flag;
	char x[25];
	FILE *f,*f2;
	system("cls");
	printf("Delete Articles");
	printf("Enter item code:");
	scanf("%s",x);
	flag=check(x);
	if(flag==0)
	{
		f2=fopen("record1.txt","ab");
		f=fopen("record.txt","rb");
		rewind(f);
		while(fread(&item,sizeof(item),1,f))//reading file
		{
			if(strcmp(item.code,x)!=0)//only the codes that are not equal to x 
				fwrite(&item,sizeof(item),1,f2);//are written into file f2
		}
		printf("ITEM DELETED");
		remove("record.txt");
		
		rename("record1.txt","record.txt");//record1.txt is renamed and it doesnt contain x
	}
	if(flag==1)//codes dont match hence item not found
	{
		printf("ITEM DOES NOT EXIST\n");
		printf("TRY AGAIN\n");
	}
	fclose(f2);
	fclose(f);
	printf("Press any key:\n");
	getch();
	d_mainmenu();
}

int check(char x[12])
{
    FILE *f;
    int flag=1;
    f=fopen("record.txt","rb");
    rewind(f);
    while (fread(&item,sizeof (item),1,f))
    {
        if(strcmp(item.code,x)==0)// if item codes are  equal flag=0
        {
            flag=0;
            break;
        }
    }
    fclose(f);
    return flag;
}


void bill()
{
	char x[4]= {0};
    int q=0,size=0;
    float total=0,gtotal=0;
	FILE *file;
	file=fopen("record.txt","rb");
	system("cls");
	rewind(file);
	
	
	while(1)
    {    
		printf("\n\nenter item code or press end to exit:");
        scanf("%s",x);
        if(strcmp(x,"end")==0)
            break;
		printf("\nenter quantity:");
        scanf("%d",&q);
		dbill();
        rewind(file);
        while(fread(&item,sizeof(item),1,file))
        {
            if((strcmp(item.code,x)==0))
            {
                total=item.rate*q;
				printf("\n");
                printf("\t\t%9s",item.name);
                printf("%13d",q);
                printf("\t%15.2f",item.rate);
                printf("\t%13.2f",total);
                gtotal=gtotal+total;
				if(gtotal!=0)
               {
        
               printf("\n\n\n-------------TOTAL AMOUNT = NRs. %6.2f",gtotal);
		
              }
	
                size=sizeof(item);
                item.quantity=item.quantity-q;
                fseek(file,-size,SEEK_CUR);
                fwrite(&item,sizeof(item),1,file);
                break;
			}
			
			
			
		}
	}
	
	
    fclose(file);
    getch();
    d_mainmenu();
}

void dbill()
{
    int i;

    for (i=1; i<=10; i++)
        printf("*");
    printf("  ");
    for (i=1; i<=10; i++)
        printf("*");
    printf("\n\n");
    
    printf("\n");

   
    printf("CUSTOMER'S BILL") ;

    printf("SN.   Item Name     Quantity     Rate          Total");
}


/*function to display all records*/
void d_all()
{
    int i,j=1;
    FILE *file;
    dis_con();
    file=fopen("record.txt","rb");
    rewind(file);
    i=26;
    fflush(file);
    while(fread(&item,sizeof(item),1,file))
    {
        display(&item,i,j);
        i++;
        j++;
        if ((j%20)==0)
        {
            
            printf("Press any key to see more...........");
            getch();
            system("cls");
            dis_con();
            i=26;
            continue;
        }
    }
    getch();
    if (i==26)
    {
       
        printf("-- no articles found --");
    }
    getch();
    fclose(file);
    d_mainmenu();
}


void display(r *item,int i,int j)
{
    printf("\n");
   
    printf("\t%9s",item->name);
    printf("\t%12s",item->code);
    printf("\t%14.2f",item->rate);
    printf("\t%11d",item->quantity);
}

void dis_con()
{
    int i;
    system("cls");
    
    ;
    for (i=1; i<=10; i++)
        printf("\n");
    printf("  ");
    for (i=1; i<=10; i++)
        printf("\n");
    printf("\n\n");
   
    printf("\nBILL");

    printf("RECORDS") ;

    printf ( " Item Name \t  Item Code  \t    Rate  \t   Quantity");
}

