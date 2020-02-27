#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menu()
{
	printf("                                  |                hello world               |\n");
}



struct student //结构体
{
	char name[20];
	int sno;
	int grade1;
	int grade2;
	int grade3;
}p[3];
struct student t;

//全局变量
int i;
int j;
int n;
int m;
int x;
char b[1];
char *filename;
FILE *fp;

int a1,a2,a3;
int xh;
int sum1,sum2,sum3;
int rs=0;

int main()//main()方法
{
	
	//方法	
	void luru();
	void xs();
	//void bc();
	void px();
	void xg();
	void tj();
	void save();
	void read();
	
	//char sr_cj[10];
	menu();
	
	while(1)
	{
		printf("                                  |     -------------操作菜单-----------     |\n");
		printf("                                  |     ***********1:成绩录入***********     |\n");
		printf("                                  |     ***********2:成绩显示***********     |\n");
		printf("                                  |     ***********3:成绩保存***********     |\n");
		printf("                                  |     ***********4:成绩排序***********     |\n");
		printf("                                  |     ***********5:成绩修改***********     |\n");
		printf("                                  |     ***********6:成绩统计***********     |\n");
		printf("                                  |     ***********0:退出程序***********     |\n");
		printf("                                  |     --------------------------------     |\n");
		printf("按数字键选择要执行的操作:");
		scanf("%d",&x);
		printf("\n");
		//输入0跳出循环，退出程序
		if(x==0)
			break;
		
		switch(x)
		{
		case 1:
			luru();
			
			break;//输入1，跳出switch语句，进入下一次循环
		case 2: 
			read(3,"student.txt");/*从文件中读取数据*/
			
			break;//输入2，跳出switch语句，进入下一次循环
		case 3: 
			//bc();
			save(3,"student.txt");/*将数据保存到文件*/
			
			break;
		case 4:
			px();
			
			break;
		case 5:
			xg();
			
			break;
		case 6:
			tj();
			
			break;
		default://数字输入错误，跳出siwtch语句，进入下一次循环
			printf("输入的数字不正确\n");
			break;
		}
	}
	return 0;
}


void luru()//学生信息录入
{
	system("cls");
	printf("请输入学生姓名 学号 三科成绩:\n");
	for(i=0;i<3;i++)
		scanf("%s%d%d%d%d",&p[i].name,&p[i].sno,&p[i].grade1,&p[i].grade2,&p[i].grade3);
	system("cls");
}


void read(int n,char *filename)//学生信息读取
{
	system("cls");
	
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("cannot open file!\n");
		exit(0);
	}
	printf("姓名   学号    高数   数据结构 马基 \n");
	for(i=0;i<n;i++)
	{
		fread(&p[i],sizeof(struct student),1,fp);
		printf("%s\t%d\t%d\t%d\t%d\n",p[i].name,p[i].sno,p[i].grade1,p[i].grade2,p[i].grade3);
	}
	fclose(fp);
}


void save(int n,char *filename)//学生信息保存
{
	system("cls");
	
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("cannot creat file.\n");
		exit(0);
	}
	for(i=0;i<n;i++)
		if(fwrite(&p[i],sizeof(struct student),1,fp)!=1)
			printf("\n write error!\n");
		fclose(fp);
		printf("学生成绩已保存\n");
}


void px()//学生成绩排序
{
	system("cls");
	printf("请输入按科目几排序：\n");
	scanf("%d",&n);
	printf("\n");
	//按照科目一排序
	if(n==1)
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<2-i;++j)
			{
				if(p[j].grade1>p[j+1].grade1)
				{
					t=p[j];
					p[j]=p[j+1];
					p[j+1]=t;
				}
			}
		}
		save(3,"student.txt");/*将数据保存到文件*/
	}
	//按照科目二排序
	if(n==2)
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<2-i;++j)
			{
				if(p[j].grade2>p[j+1].grade2)
				{
					t=p[j];
					p[j]=p[j+1];
					p[j+1]=t;
				}
			}
		}
		save(3,"student.txt");/*将数据保存到文件*/
	}
	//按照科目三排序
	if(n==3)
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<2-i;++j)
			{
				if(p[j].grade3>p[j+1].grade3)
				{
					t=p[j];
					p[j]=p[j+1];
					p[j+1]=t;
				}
			}
		}
		save(3,"student.txt");/*将数据保存到文件*/
	}
	//将排序结果输出
	read(3,"student.txt");/*从文件中读取数据*/
}


void xg()//学生信息修改
{
	system("cls");
	printf("学生信息修改\n");
	printf("请输入学号,以便修改:\n");
	scanf("%d",&xh);
	for(i=0;i<3;i++)
	{
		if(p[i].sno==xh)
			break;
	}
	printf("确认修改学生: %s 的信息\n",p[i].name);
	printf("请输入y/n(提示，输入y继续输入，输入n结束输入)：");
	scanf("%s",b);
	while(strcmp(b,"Y")==0||strcmp(b,"y")==0)
	{
		printf("请输入第一项成绩(回车可以跳过):\n");
		a1=0;
		scanf("%d",&a1);
		if(a1!=0){p[i].grade1=a1;};
		printf("请输入第二项成绩(回车可以跳过):\n");
		a2=0;
		scanf("%d",&a2);
		if(a2!=0){p[i].grade2=a2;};
		printf("请输入第三项成绩(回车可以跳过):\n");
		a3=0;
		scanf("%d",&a3);
		if(a3!=0){p[i].grade3=a3;};
		printf("输入完毕\n"); 
		printf("是否继续y/n(提示，输入y重新输入，输入n结束输入)：");
		scanf("%s",b);
	}
	save(3,"student.txt");/*将数据保存到文件*/
	system("cls");
}


void tj()//学生信息统计
{
	system("cls");
	read(3,"student.txt");/*从文件中读取数据*/
	printf("统计\n");
	//每门成绩最高的学生的所有信息
	printf("每门成绩最高的学生的所有信息:\n");
	t.grade1=0;
	t.grade2=0;
	t.grade3=0;
	//第一门成绩最高的学生的所有信息
	printf("第一门成绩最高的学生的所有信息:\n");
	for(i=0;i<3;i++)
	{
		if(p[i].grade1>t.grade1)
			t=p[i];
	}
	printf("姓名   学号    科目1   科目2   科目3\n");
	//fread(&p[i],sizeof(struct student),1,fp);
	printf("%s\t%d\t%d\t%d\t%d\n",t.name,t.sno,t.grade1,t.grade2,t.grade3);
	//第二门成绩最高的学生的所有信息
	printf("第二门成绩最高的学生的所有信息:\n");
	for(i=0;i<3;i++)
	{
		if(p[i].grade2>t.grade2)
			t=p[i];
	}
	printf("姓名   学号    科目1   科目2   科目3\n");
	//fread(&p[i],sizeof(struct student),1,fp);
	printf("%s\t%d\t%d\t%d\t%d\n",t.name,t.sno,t.grade1,t.grade2,t.grade3);
	//第三门成绩最高的学生的所有信息
	printf("第三门成绩最高的学生的所有信息:\n");
	for(i=0;i<3;i++)
	{
		if(p[i].grade3>t.grade3)
			t=p[i];
	}
	printf("姓名   学号    科目1   科目2   科目3\n");
	//fread(&p[i],sizeof(struct student),1,fp);
	printf("%s\t%d\t%d\t%d\t%d\n",t.name,t.sno,t.grade1,t.grade2,t.grade3);
	printf("\n");
	printf("\n");
	
	//每门课程的平均成绩
	printf("每门课程的平均成绩:\n");
	//每一课程的平均成绩
	printf("第一课程的平均成绩:");
	for(i=0;i<3;i++)
		sum1+=p[i].grade1;
	sum1=sum1/3;
	printf("%d\n",sum1);
	
	//每二课程的平均成绩
	printf("第二课程的平均成绩:");
	for(i=0;i<3;i++)
		sum2+=p[i].grade2;
	sum2=sum2/3;
	printf("%d\n",sum2);
	
	//每三课程的平均成绩
	printf("第三课程的平均成绩:");
	for(i=0;i<3;i++)
		sum3+=p[i].grade3;
	sum3=sum3/3;
	printf("%d\n",sum3);
	printf("\n");
	printf("\n");
	
	printf("选择查看那门课程人数:");
	//超过某门课程平均成绩的学生人数
	scanf("%d",&m);
	printf("\n");
	
	if(m==1)//超过第一门课程平均成绩的学生人数
	{
		printf("超过第一门课程平均成绩的学生人数:");
		for(i=0;i<3;i++)
		{
			if(p[i].grade1>sum1)
				rs++;
		}
		printf("%d\n",rs);
	}
	
	if(m==2)//超过第二门课程平均成绩的学生人数
	{
		printf("超过第二门课程平均成绩的学生人数:");
		for(i=0;i<3;i++)
		{
			if(p[i].grade2>sum2)
				rs++;
		}
		printf("%d\n",rs);
	}
	
	if(m==3)//超过第三门课程平均成绩的学生人数
	{
		printf("超过第三门课程平均成绩的学生人数:");
		for(i=0;i<3;i++)
		{
			if(p[i].grade3>sum3)
				rs++;
		}
		printf("%d\n",rs);
	}
	sum1=sum2=sum3=0;
	rs=0;
	
}