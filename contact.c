#include "contact.h"
void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->date, 0, sizeof(pc->date));//设置内存
}
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX)//满了
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入名字：>");
	scanf("%s", pc->date[pc->count].name);
	printf("请输入年龄：>");
	scanf("%d", &(pc->date[pc->count].age));
	printf("请输入性别：>");
	scanf("%s", pc->date[pc->count].sex);
	printf("请输入电话：>");
	scanf("%s", pc->date[pc->count].tele);
	printf("请输入地址：>");
	scanf("%s", pc->date[pc->count].addr);
	pc->count++;
	printf("增加成功\n");
}
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%12s\t%30s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%20s\t%3d\t%5s\t%12s\t%30s\n", pc->date[i].name,
			     
			pc->date[i].age,
			                                   pc->date[i].sex,
                                   pc->date[i].tele,
			                                    pc->date[i].addr);
	}
}
int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for(i=0;i<pc->count;i++)
		if (0 == strcmp(pc->date[i].name, name))
		{
			return i;
        }
	return -1;
}
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
		assert(pc);//判断若为空不删除
		int i = 0;
		if (pc->count == 0)
		{
			printf("通讯录为空，没有信息可以删除\n");
			return;
		}
	printf("请输入要删除人的名字：>");
	scanf("%s ", name);
	//删除
	//1.查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2.删除//防止越界
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}


