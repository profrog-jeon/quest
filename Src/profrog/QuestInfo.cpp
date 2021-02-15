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
		strcpy(npc.szName, "전상현 멘토");
		npc.x = 75;
		npc.y = 101;
		npc.w = 0.5;
		npc.h = 0.5;
		npc.patch = '@';
		strcpy(npc.szGreetMessage, "ㅎㅇㅎㅇ");
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
		strcpy(npc.szGreetMessage, "뭔가 빛나는 물건이 떨어져 있다.");
		vecNPC.push_back(npc);
	}

	{
		ST_NPC_INFO npc;
		npc.id = 10001;
		strcpy(npc.szName, "멘티1");
		npc.x = 81;
		npc.y = 101;
		npc.w = 0.5;
		npc.h = 0.5;
		npc.patch = '&';
		strcpy(npc.szGreetMessage, "전설의 멘토님 소문 들어봤어? (-50,50) 근방에 있다던대..");
		vecNPC.push_back(npc);
	}

	{
		ST_NPC_INFO npc;
		npc.id = 10002;
		strcpy(npc.szName, "멘티2");
		npc.x = 81;
		npc.y = 97;
		npc.w = 0.5;
		npc.h = 0.5;
		npc.patch = '&';
		strcpy(npc.szGreetMessage, "개인 과제는 다른 사람것 대신하다 걸리면 안돼.");
		vecNPC.push_back(npc);
	}

	{
		ST_NPC_INFO npc;
		npc.id = 10003;
		strcpy(npc.szName, "멘티3");
		npc.x = 87;
		npc.y = 101;
		npc.w = 0.5;
		npc.h = 0.5;
		npc.patch = '&';
		strcpy(npc.szGreetMessage, "전설의 멘토님은 `G` 버튼으로 공격하면 깨울 수 있대.");
		vecNPC.push_back(npc);
	}

	{
		ST_NPC_INFO npc;
		npc.id = 10004;
		strcpy(npc.szName, "멘티4");
		npc.x = 87;
		npc.y = 97;
		npc.w = 0.5;
		npc.h = 0.5;
		npc.patch = '&';
		strcpy(npc.szGreetMessage, "과제 지겹다 후..... 과제는 `G`버튼으로 쏴서 잡아야 해");
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
