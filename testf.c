#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
//#include<conio.h>
//#define clear() printf("\033[H\033[J")

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
//FILE *fp1;
FILE *fp3;
int sachin=0;
int hash(char str[])
{
        int l=0,i=0,sum=0;
        l=strlen(str);
        while(i<l)
        {
               sum=sum+(pow(2,i)*((int)str[i]));
               i++;
        }
        return sum;
}
void submit(char name[])
{
  
  char unam_t[100][10],bname[100][10],bna[10];
FILE *fp1;
fp1=fopen("issue.txt","r");
int i=0,chh=0,j=0,b_id[100],hi[100],b_idc[100];
change1:
clear();
  printf("\n\t\tSubmit :\n\n\n");
printf("\t\t\tEnter Book ID: ");
int saksham1=0,bid=0;
char paper1[20];
scanf("%s",paper1);
			while(paper1[saksham1]!='\0')
			{
				if(paper1[saksham1]>=48 && paper1[saksham1]<=57)
				bid=(bid*10)+(paper1[saksham1]-48);
				else
				{
					printf("\n\nonly Number is allowed\n");
					sleep(1);goto change1;
					
				}
			saksham1++;
			}


while(fscanf(fp1,"%s",unam_t[i])!=EOF)
{//printf("sss\n");
  fscanf(fp1,"%d",&b_id[i]);

  if(strcmp(unam_t[i],name)==0 && bid==b_id[i])
  {
    chh=1;

  }
  i++;
  //printf("aaa");
}
fclose(fp1);

///////aaaaaaa
if(chh==1)
{
fp1=fopen("issue.txt","w");

for(j=0;j<i;j++)
{
if(b_id[j]!=bid)
{
  fprintf(fp1,"%s %d\n",unam_t[j],b_id[j]);
}
}
fclose(fp1);
fp1=fopen("complete.txt","r");
i=0;
while(fscanf(fp1,"%s",bname[i])!=EOF)
{
fscanf(fp1,"%d",&b_idc[i]);

if(bid==b_idc[i])
{
strcpy(bna,bname[i]);
break;
}

  i++;
}
fclose(fp1);

fp1=fopen("book.txt","a");
fprintf(fp1,"%s %d\n",bna,bid);
fclose(fp1);
}
else
{
  printf("No book issued\n");
	goto a;
}
time_t mytime;
		mytime = time(NULL);

FILE *fp5;
fp5=fopen("record.txt","a");
fprintf(fp5,"%s		%s		%d	Submit		%s",name,bna,bid,ctime(&mytime));
a:
printf("\n");

sleep(2);
}
int limit(char name[])
{
	char str5[20];
	int chal,lim=0;
	FILE *fp67;
	fp67=fopen("issue.txt","r");
	while(fscanf(fp67,"%s",str5)!=EOF)
	{
		fscanf(fp67,"%d",&chal);
		if(strcmp(str5,name)==0)
		lim++;
	}
return lim;
}
void issue(char name[])
{
//printf("bhjhb");
/*char ch,str[100],str2[100][20];
 int b_a[100],n=0,index=0,i;

char str[100],str2[100][20],ch;
long long int i,b_a[100000],index=0,n=0;
 FILE *fp;
      for(i=0;i<1000000;i++)
        b_a[i]=0;
        fp=fopen("book.txt","r");
        while(fscanf(fp,"%s",str)!=EOF)
{
        index=hash(str);
        strcpy(str2[n++],str);
        fscanf(fp,"%d",&b_a[index]);
}
fclose(fp);
    printf("do you want to search by name or id\n");
  printf("press n for name & i for id\n");
  scanf(" %c",&ch);

		char ch,str2[100][20],key[100],str[100];
		long long int n=0,b_a[100000],index;
        long long int temp[1000],id;
        long long int b_id,i=0,fal=0;
        FILE *fp;
        for(i=0;i<100000;i++)
        b_a[i]=0;*/
	int b_a[10000],n=0,index,fal=0,id,i=0,j=0,nrecord=0;
	char str[100],str2[100][10],ch,key[100],irecord[100];
	FILE *fp1;
        fp1=fopen("book.txt","r");
        while(fscanf(fp1,"%s",str)!=EOF)
{
       // index=hash(str);
        strcpy(str2[n],str);
        fscanf(fp1,"%d",&b_a[n]);
n++;
}
fclose(fp1);

//printf("%s %d",str2[0],b_a[hash(str2[0])]);
        clear();
int issue_lim=0;
issue_lim=limit(name);
if(issue_lim<3)
{
printf("\n\t\t\tIssue:\n");
sleep(1);
       // printf("do you want to search by name or id\n");
        printf("\n\n\n\n\n\t\t\tN-Search by Name\n\n\t\t\tI-Search by Book Id\n");
//printf("%s",str2[i]);
        scanf(" %c",&ch);


if(ch=='n'|| ch=='N')
{clear();
	printf(

    "\n\n\n\n\n\n\t\t\t.-----------------.\n"
  "\tEnter Bookname :"
    "|                 |\n"
    "\t\t\t.-----------------.\n"
);
gotoxy(8,27);
	scanf("%s",key);
for(i=0;i<=n;i++)
{
        if(strcmp(key,str2[i])==0)
        {printf("\n\n\t\t\tBook Issued\n");fal=100;
            fp3=fopen("issue.txt","a");
                fprintf(fp3,"%s %d\n",name,b_a[i]);
                fclose(fp3);
		nrecord=b_a[i];
                b_a[i]=0;break;
                }
}
if(fal==0)
printf("\n\nBook not found.\n");
}
else if(ch=='i'||ch=='I')
{
change1:
clear();
	printf(

    "\n\n\n\n\n\n\t\t\t.-----------------.\n"
  "\tEnter Id    :"
    "   |                 |\n"
    "\t\t\t.-----------------.\n"
);
gotoxy(8,27);
int saksham1=0;
char paper1[20];
scanf("%s",paper1);
			while(paper1[saksham1]!='\0')
			{
				if(paper1[saksham1]>=48 && paper1[saksham1]<=57)
				id=(id*10)+(paper1[saksham1]-48);
				else
				{
					printf("\n\nonly Number is allowed\n");
					sleep(1);goto change1;
					
				}
			saksham1++;
			}

	
	for(i=0;i<100000;i++)
	{
		if(b_a[i]==id)
		{
			for(j=0;j<=n;j++)
			{
			if(b_a[j]==id)
			{
			            fp3=fopen("issue.txt","a");
                fprintf(fp3,"%s %d\n",name,id);
                fclose(fp3);
		strcpy(irecord,str2[j]);
	printf("\n\n\tBook Name :%s \tBook Issued\n",str2[j]);fal=100;b_a[i]=0;break;}
			}
		break;
	}
	}
if(fal==0)
	printf("Book not found.\n");
	}
	else
	printf("Invalid choice\n");


           fp1=fopen("book.txt","w");
           j=0;
           while(j<=n)
           {
           	if(b_a[j]!=0)
           	{
              fprintf(fp1,"%s %d\n",str2[j],b_a[j]);
              b_a[j]=0;
            }
    j++;
		}
	fclose(fp1);
FILE *fp5;
time_t mytime;
		mytime = time(NULL);

	fp5=fopen("record.txt","a");
  //fprintf(fp5,"ss");
	if((ch=='n' || ch=='N') &&(fal!=0))
	{
    //printf("zzz");
	fprintf(fp5,"%s		%s		%d	issued		%s",name,key,nrecord,ctime(&mytime));
	//fprintf(fp5,ctime(&mytime));
	//fprintf(fp5,"\n");
	}
	else if((ch=='i' || ch=='I') && (fal!=0))
	{
    //printf("xxx");
	fprintf(fp5,"%s		%s		%d	issued		%s",name,irecord,id,ctime(&mytime));
	//fprintf(fp5,ctime(&mytime));
	//fprintf(fp5,"\n");
	}
	else
	{}
fclose(fp5);
}

else
goto new;
new:
printf("\n\n\t\tYou have already 3 books issued\n\n");	
  sleep(3);
}

void list()
{FILE *fp1;
int b_id;
char b_name[100];
//clear();
fp1=fopen("book.txt","r");
printf("\n\tBooks\t\tId\n");
while(fscanf(fp1,"%s",b_name)!=EOF)
{
	fscanf(fp1,"%d",&b_id);
	printf("\t%s\t\t%d\n",b_name,b_id);
}
fclose(fp1);
//sleep(5);
}
void record()
{clear();
	char sname[20],sbname[29],mode[20];
	int sbid;
	//char admin[20],right[20];
	//strcpy(right,"iiitkota12#");
	//printf("\n\n\t\t\tStaff Only\n\n");
//char *password112;
//clear();
//password112=getpass("\tEnter Password: ");
	//strcpy(admin,(password112));
	//clear();
	//if(strcmp(admin,right)==0)
	//{
		FILE *fp20;
		fp20=fopen("record.txt","r");
		printf("Username      bookname 	  bookid     activity  		Time\n");	
		while(fscanf(fp20,"%s",sname)!=EOF)
		{
			fscanf(fp20,"%s",sbname);
			fscanf(fp20,"%d",&sbid);
			fscanf(fp20,"%s",mode);
			printf("%s	      %s	    %d	    %s  ",sname,sbname,sbid,mode);
			fscanf(fp20,"%s",sname);
			fscanf(fp20,"%s",sbname);
			fscanf(fp20,"%d",&sbid);
			fscanf(fp20,"%s",mode);
			printf("   %s %s %d %s ",sname,sbname,sbid,mode);
			fscanf(fp20,"%d",&sbid);
			printf("%d\n",sbid);
		}
		//}
	//else
	//{
	//printf("Something went wrong\n");}
}
void create()
{
char libname[20],n_key[20];
int libid;
	clear();
   printf("\n\n\n\t\t\tEnter Book name:");
   scanf("%s",libname);
	change:
	clear();
   printf("\n\n\n\t\t\tEnter Book id:");
   scanf("%s",n_key);
int saksham=0,paper=0;
			while(n_key[saksham]!='\0')
			{
				if(n_key[saksham]>=48 && n_key[saksham]<=57)
				paper=(paper*10)+(n_key[saksham]-48);
				else
				{
					printf("\n\nonly Number is allowed\n");
					sleep(1);goto change;
					
				}
			saksham++;
			}
			
  
   FILE *fp101,*fp102;
	fp101=fopen("book.txt","a");
	fprintf(fp101,"%s %d\n",libname,paper);
	fclose(fp101);
	fp102=fopen("complete.txt","a");
	fprintf(fp102,"%s %d\n",libname,paper);
	fclose(fp102);
		
}
void adminstrative()
{
	char adch;
	char admin[20],right[20];
	strcpy(right,"iiitkota12#");
	printf("\n\n\t\t\tStaff Only\n\n");
char *password112;
//clear();
password112=getpass("\tEnter Password: ");
	strcpy(admin,(password112));
	clear();
	if(strcmp(admin,right)==0)
	{
	printf("\n\n\n\n\t\t\tR-record\n\n");
	printf("\t\t\tI-insert\n\n");
	scanf(" %c",&adch);
	if(adch=='r' || adch=='R')
	record();
	else if(adch=='i' || adch=='I')
	{
	  create();
	}
	else
	{
		printf("Wrong choice\n");
	}
	}
	else
	{printf("something went wrong\n");}
}

void Selfrecord(char name[])
{
	char sbname[10],s1[10],s2[10],s3[10],s4[10],s5[10];
	int i1,i2,i3,i4;
	FILE *fp15;
	
	fp15=fopen("record.txt","r");
	printf("Username      bookname 	bookid	activity  		Time\n");	
	while(fscanf(fp15,"%s",sbname)!=EOF)
	{
		fscanf(fp15,"%s",s1);
		fscanf(fp15,"%d",&i1);
		fscanf(fp15,"%s",s2);
		fscanf(fp15,"%s",s3);
		fscanf(fp15,"%s",s4);
		fscanf(fp15,"%d",&i2);
		fscanf(fp15,"%s",s5);
		fscanf(fp15,"%d",&i3);
	if(strcmp(sbname,name)==0)
	{
		printf("%s	   %s	    %d	   %s  ",sbname,s1,i1,s2);
	printf("   %s %s %d %s ",s3,s4,i2,s5);
printf("%d\n",i3);
	}
	else
	{}
	}
}	
int main()
{
  time_t mytime;


char str[100],key[100],ch,str1[100][20],menu,signname[20],challenge[20],signpass[20];
long long int s_a[1000000],k_index,index,pass,m=0,i,n=0;
char n_key[20],n_key1[20];
char choice,log;
int challengepass;
for(i=0;i<1000000;i++)
s_a[i]=0;
FILE *fp;

fp=fopen("input.txt","r");
while(fscanf(fp,"%s",str)!=EOF)
{
        index=hash(str);
        strcpy(str1[n++],str);
        fscanf(fp,"%lld",&s_a[index]);
}
fclose(fp);
clear();
printf("\n\n\n\tWelcome to Dsa project\n\n");

printf("\n\t\t\t1.Akshat Sharma\n\t\t\t2.Sachin Chouhan\n\t\t\t3.Shashank Joshi\n\t\t\t4.Akarshit Gupta\n\t\t\t5.Saksham Jain\n");
sleep(3);
clear();
printf("\n\t\tWelcome to Library Management System\n");
sleep(1);
printf("\n\n\n\t\tL-login\n\n\t\tS-sign up\n");
scanf("%c",&log);
if(log=='l' || log=='L')
{
clear();

clear();
printf("\n\t\tWelcome to Library Management System\n");
printf("\n\n\t\t\tLogin:\n\n");
sachin=1;
printf(

    "\t\t\t.-----------------.\n"
  "\tEnter Username :"
    "|                 |\n"
    "\t\t\t.-----------------.\n"
);
gotoxy(8,27);
scanf("%s",key);

clear();
for(i=0;i<n;i++)
{
        if(strcmp(key,str1[i])==0)
                break;
}
k_index=hash(key);
if(s_a[k_index]==0)
{printf("Invalid Username\n");goto pa;}
else
{
printf("\n");
again:
printf("\n\n\n\n\n\n");

 /* printf(

      "\n\n\n\n\n\n\t\t\t.-----------------.\n"
    "\tEnter Password :"
      "|                 |\n"
      "\t\t\t.-----------------.\n"
  );*/
 // if(m==0)
gotoxy(8,27);
//else
//gotoxy(9,27);
//char c11,password1[10];
/*int i11=0;
pass=0;
while( (c11=getchar())!= '\n'){
    password1[i11] = c11;
    pass=pass*10+c11;
    printf("*");
    i++;
}*/
//printf("hh..%lld..",pass);
//strcpy(pass,password1);
char *password11;
//clear();
password11=getpass("\tEnter Password: ");
int iaa=0,iaa1=0;
while(*(password11+iaa)!='\0')
{
	iaa1=iaa1*10+((*(password11+iaa))-48);
	iaa++;
}
pass=iaa1;
//scanf("%lld",&pass);
clear();
}
if(pass==s_a[k_index])
{
printf("Access Granted\n");
clear();
//printf("do you want to change your password\ny/n");



action:
clear();

	//fprintf(fp5,ctime(&mytime));
lg:
clear();
mytime = time(NULL);
printf("\t Welcome %s \t%s \n\n\tEnter your choice-",key,ctime(&mytime));

        printf("\n\n\t\t\tI-Issue book\n\n");
        printf("\t\t\tS-Submit\n\n");
        printf("\t\t\tC-Change Password\n\n");
	printf("\t\t\tG-get list of current books\n\n");
	printf("\t\t\tA-Enter security mode\n\n");
	printf("\t\t\tO-get your own record\n\n");
	printf("\t\t\tE-Exit\n");
        scanf(" %c",&choice);
        	//printf("%d",choice);
              if(choice=='i'||choice=='I')
                {
                  issue(key);
			//sleep(2);
			clear();
			goto action;
                 }
                 else if(choice=='s'|| choice=='S')
		{
                  submit(key);
			clear();
			goto action;
		}
                  else if(choice=='c'|| choice=='C')
                  {
			if(sachin==1)
			{
                  	change:
                    clear();
                    //gotoxy(8,27);
                    printf(

                        "\n\n\n\n\n\n\t\t\t.-----------------.\n"
                      "  Enter New password :"
                        "  |                 |\n"
                        "\t\t\t.-----------------.\n"
                    );
                    gotoxy(8,27);
                          scanf("%s",n_key);
			int saksham=0,paper=0;
			while(n_key[saksham]!='\0')
			{
				if(n_key[saksham]>=48 && n_key[saksham]<=57)
				paper=(paper*10)+(n_key[saksham]-48);
				else
				{
					printf("\n\nonly Number is allowed\n");
					sleep(1);goto change;
					
				}
			saksham++;
			}
				
                          clear();
                          printf(

                              "\n\n\n\n\n\n\t\t\t.-----------------.\n"
                            "  Confirm new password :"
                              "|                 |\n"
                              "\t\t\t.-----------------.\n"
                          );
			gotoxy(8,27);
                          scanf("%s",n_key1);

                  	if(strcmp(n_key,n_key1)!=0)
                  	goto change;
                  	else
                  	{
                          s_a[hash(str1[i])]=paper;
                          fp=fopen("input.txt","w");
                  i=0;
                  while(i<n)
                  {

                  fprintf(fp,"%s %lld\n",str1[i],s_a[hash(str1[i])]);
                  i++;

                  }
                  }
		}
		else
		{
		printf("You must first exit  from this & login again\n");
		sleep(3);
		}
		clear();
	goto action;
                }
		//goto action;
		else if(choice=='g' || choice=='G')
		{
	clear();
		printf("\nM-menu\t\t\t\t\t\t\t\tE-Exit\n");
		list();
		scanf(" %c",&menu);
		if(menu=='m' || menu=='M')
		goto action;
		else
		goto pa;
		
		
		}
		else if(choice=='e' || choice=='E')
		{clear();
		printf("\n\n\nThank You!!!\n");
		sleep(2);
		goto pa;
			}
	else if(choice=='a' || choice=='A')
	{
		clear();
		adminstrative();
printf("\n\n\n\nM-menu\t\t\t\t\t\t\t\tE-Exit\n");
scanf(" %c",&menu);
if(menu=='m' || menu=='M')
		goto action;
		else
		goto pa;
	}
	else if(choice=='o' || choice=='O')
		{
			clear();
			Selfrecord(key);
		printf("\n\n\n\nM-menu\t\t\t\t\t\t\t\tE-Exit\n");
scanf(" %c",&menu);
if(menu=='m' || menu=='M')
		goto action;
		else
		goto pa;

		}
                  else
                  {
                    printf("Invalid choice\n");
                    goto action;
                  }
}



else
{

++m;
clear();
printf("Invalid password\n");
if(m<=2)
//{
goto again;
//gotoxy(9,27);
//}
}
}
else if(log=='s' || log=='S')
{
jai:
clear();
	printf("\n\t\tWelcome to Library Management System\n");
printf("\n\n\t\t\tSignup:\n\n");

printf(

    "\t\t\t.-----------------.\n"
  "\tEnter Username :"
    "|                 |\n"
    "\t\t\t.-----------------.\n"
);
gotoxy(8,27);
scanf("%s",signname);
strcpy(key,signname);
FILE *fp23;
fp23=fopen("input.txt","r");
while(fscanf(fp23,"%s",challenge)!=EOF)
{
	fscanf(fp23,"%d",&challengepass);
	if(strcmp(challenge,signname)==0)
	{printf("\n\nUsername is already Exist!!\n\t\tPlease  try with other Username\n");
		sleep(2);
		goto jai;
	}
}
change1:
clear();
printf(

    "\n\n\n\n**password must be only numeric\n\n\t\t\t .-----------------.\n"
  "Enter DateofBirth(dd/mm):"
    "|                 |\n"
    "\t\t\t .-----------------.\n"
);
gotoxy(8,27);
scanf("%s",signpass);
int saksham1=0,paper1=0;
			while(signpass[saksham1]!='\0')
			{
				if(signpass[saksham1]>=48 && signpass[saksham1]<=57)
				paper1=(paper1*10)+(signpass[saksham1]-48);
				else
				{
					printf("\n\nonly Number is allowed\n");
					sleep(1);goto change1;
					
				}
			saksham1++;
			}

sachin=2;
printf("\n\n\n\t\t\tsignup Successful\n\n\t\t\tYour password is your date of birth\n\t\t\t");
FILE *fp50;
fp50=fopen("input.txt","a");
fprintf(fp50,"%s %d\n",signname,paper1);
fclose(fp50);
sleep(2);
goto lg;
}
else
{
printf("Invalid option\n");
}
pa:
printf("\n");
return 0;
}
