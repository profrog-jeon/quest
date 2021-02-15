#include "stdafx.h"
#include "QuestInfo.h"

static CQuestInfo g_QuestInfo;

CQuestInfo::CQuestInfo(void)
{
	ExportAPIEntry(this);
	ExportDllMain();
}

CQuestInfo::~CQuestInfo(void)
{
}

void CQuestInfo::QueryNpc(std::vector<ST_NPC_INFO>& vecNPC)
{
	{
		ST_NPC_INFO npc;
		npc.id = 1;
		strcpy(npc.szName, "������ ����");
		npc.x = 75;
		npc.y = 101;
		npc.w = 0.5;
		npc.h = 0.5;
		npc.patch = '@';
		strcpy(npc.szGreetMessage, "��������");
		vecNPC.push_back(npc);
	}

	{
		ST_NPC_INFO npc;
		npc.id = 10000;
		strcpy(npc.szName, "");
		npc.x = 31;
		npc.y = 147;
		npc.w = 0.5;
		npc.h = 0.5;
		npc.patch = '^';
		strcpy(npc.szGreetMessage, "���� ������ ������ ������ �ִ�.");
		vecNPC.push_back(npc);
	}

	{
		ST_NPC_INFO npc;
		npc.id = 10001;
		strcpy(npc.szName, "��Ƽ1");
		npc.x = 81;
		npc.y = 101;
		npc.w = 0.5;
		npc.h = 0.5;
		npc.patch = '&';
		strcpy(npc.szGreetMessage, "������ ����� �ҹ� ���þ�? (-50,50) �ٹ濡 �ִٴ���..");
		vecNPC.push_back(npc);
	}

	{
		ST_NPC_INFO npc;
		npc.id = 10002;
		strcpy(npc.szName, "��Ƽ2");
		npc.x = 81;
		npc.y = 97;
		npc.w = 0.5;
		npc.h = 0.5;
		npc.patch = '&';
		strcpy(npc.szGreetMessage, "���� ������ �ٸ� ����� ����ϴ� �ɸ��� �ȵ�.");
		vecNPC.push_back(npc);
	}

	{
		ST_NPC_INFO npc;
		npc.id = 10003;
		strcpy(npc.szName, "��Ƽ3");
		npc.x = 87;
		npc.y = 101;
		npc.w = 0.5;
		npc.h = 0.5;
		npc.patch = '&';
		strcpy(npc.szGreetMessage, "������ ������� `G` ��ư���� �����ϸ� ���� �� �ִ�.");
		vecNPC.push_back(npc);
	}

	{
		ST_NPC_INFO npc;
		npc.id = 10004;
		strcpy(npc.szName, "��Ƽ4");
		npc.x = 87;
		npc.y = 97;
		npc.w = 0.5;
		npc.h = 0.5;
		npc.patch = '&';
		strcpy(npc.szGreetMessage, "���� ����� ��..... ������ `G`��ư���� ���� ��ƾ� ��");
		vecNPC.push_back(npc);
	}
}

#include "ProfrogQuest.h"
#include "ProfrogSubQuest.h"
void CQuestInfo::QueryQuest(std::vector<CQuestInfoSuper*>& vecQuest)
{
	vecQuest.push_back(new CProfrogQuest());
	vecQuest.push_back(new CProfrogSubQuest());
}
