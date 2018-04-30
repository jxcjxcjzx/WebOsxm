#include <stdio.h>
struct person
{
   char name[8];
   char tel[15];
   char addr[50];
};
char filename[20];
FILE *fp;

void creat();
void output();
void search();
void append();
void modify();
void delete();

main()
{
   int m;
   clrscr();
   printf("This is a tongxunlu.\n");
   delay(1000);
   printf("Designed by Mr Jxc.\n");
   delay(1000);
   printf("Pleased to get you to use it.");

   creat();
   while(1)
   {
     printf("\n\ntianjia,qing an 1");
     printf("\n\nchazhao,qing an 2");
     printf("\n\nxiugai,qing an 3");
     printf("\n\nshanchu,qing an 4");
     printf("\n\nshuchu,qing an 5");
     printf("\n\ntuichu,qing an 0\n");
     scanf("%d",&m);
     if(m>=0&&m<=5)
     {
       switch(m)
       {
	 case 1:append();
	    break;
	 case 2:search();
	    break;
	 case 3:modify();
	    break;
	 case 4:delete();
	    break;
	 case 5:output();
	    break;
	 case 0:exit();


       }
	 printf("\n\ncaozuo wanbi,qing zaici xuanze!");


     }
	 else
	  printf("\n\nxuanze cuowu,qing zaici xuanze!");

   }


}

    void creat()
    {
      struct person one;
      long s1;

      printf("\nqing shuru tongxunbu ming:");
      scanf("%s",&filename);
      if((fp=fopen(filename,"w"))==NULL)
      {
	 printf("\nbuneng jianli tongxunbu!");
	 exit();
      }
      fprintf(fp,"%-10s%-20s%-50s\n","xingming","dianhua haoma","zhuzhi");
      printf("\nqing shuru xingming,dianhua haoma, ji zhuzhi(yi 0 jieshu)\n");
      scanf("%s",one.name);
      while(strcmp(one.name,"0"))
      {
	 scanf("%s%s",one.tel,one.addr);
	 fprintf(fp,"%-10s%-20s%-50s\n",one.name,one.tel,one.addr);
	 scanf("%s",one.name);

      }
      fclose(fp);
    }


    void output()
    {
       struct person one;
       if((fp=fopen(filename,"r"))==NULL)
       {
	printf("\nCan not open it!");
	exit();
       }

       printf("\n\n%20s\n","tongxunbu");
       while(!feof(fp))
	{
	  fscanf(fp,"%s%s%s\n",one.name,one.tel,one.addr);
	  printf("%-10s%-20s%-50s",one.name,one.tel,one.addr);


	}
	fclose(fp);

    }


    void append()
    {
      struct person one;

      if((fp=fopen(filename,"a"))==NULL)
       {
	 printf("\nCan not open it!");
	 exit();


       }
       printf("\nqing shuru tianjia de xingming,dianhua haoma ji zhuzhi\n");
       scanf("%s%s%s",one.name,one.tel,one.addr);
       fprintf(fp,"%-10s%-20s%-50s\n",one.name,one.tel,one.addr);
       fclose(fp);


    }

    void search()
    {
      int k=0;
      char namekey[8];
      struct person one;

      printf("\nqing shuru xingming :");
      scanf("%s",namekey);
      if((fp=fopen(filename,"rb"))==NULL)
       {
	  printf("\nCan not open it!");
	  exit();

       }
       while(!feof(fp))
	{
	  fscanf(fp,"%s%s%s",one.name,one.tel,one.addr);
	  if(!strcmp(namekey,one.name))
	   {
	      printf("\n\nyi cha dao,jilu wei:");
	      printf("\n%-10s%-18s%-50s",one.name,one.tel,one.addr);
	      k=1;

	   }



	}
	if(!k)
	 printf("\n\ndui bu qi,meiyou ciren de jilu");
	 fclose(fp);

    }

    void modify()
    {
       int m,k=0;
       long offset;
       char namekey[8];
       struct person one;

       printf("\nqing shuru xingming:");
       scanf("%s",namekey);

       if((fp=fopen(filename,"r+"))==NULL)
	 {
	   printf("\nCan not open it!");
	   exit();
	 }
	while(!feof(fp))
	 {
	   offset=ftell(fp);
	   fscanf(fp,"%s%S%s\n",one.name,one.tel,one.addr);
	   if(!strcmp(namekey,one.name))
	   {
	     k=1;
	     break;
	   }

	 }
	 if(k)
	 {
	   printf("\n yi cha dao,jilu wei:");
	   printf("\n%-10s%-18s%-50s",one.name,one.tel,one.addr);
	   printf("\n qing shuru xingming,dianhua haoma ji zhuzhi:");
	   scanf("%s%s%s",one.name,one.tel,one.addr);
	   fseek(fp,offset,SEEK_SET);
	   printf("%ld",ftell(fp));
	   fprintf(fp,"%-10s%-20s%-50s\n",one.name,one.tel,one.addr);

	 }
	 else
	  printf("\n dui buqi ,meiyou ciren");
	 fclose(fp);
    }

    void delete()
    {
      int m,k=0,flag;
      long offset1,offset2;
      char namekey[8],valid[4];
      struct person one;

      printf("\nqing shuru xingming:");
      scanf("%s",namekey);
      if((fp=fopen(filename,"r+"))==NULL)
      {
	printf("\nCan not open it!");
	exit();
      }
      while(!feof(fp))
      {
	 offset1=ftell(fp);
	 fscanf(fp,"%s%s%S\n",one.name,one.tel,one.addr);
	 if(!strcmp(namekey,one.name))
	 {
	   k=1;
	   break;
	 }


      }
      if(k)
      {
	printf("\n yi cha dao,jilu wei:");
	printf("\n%-10s%-18s%-50s",one.name,one.tel,one.addr);
	printf("\n que shi yao shanchu,an 1,bu shanchu ,an 0:");
	scanf("%d",&m);
	if(m)
	{
	  fseek(fp,offset1,SEEK_SET);
	  fprintf(fp,"%-10s%-20s%-50s\n","","","");

	}

      }
	else
	 printf("\n dui buqi ,meiyou ciren");
	 fclose(fp);
    }

