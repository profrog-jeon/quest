#include "stdafx.h"
#include "ProfrogSubQuest.h"

CProfrogSubQuest::CProfrogSubQuest(void)
	: CQuestInfoSuper()
{
	m_nTargetNpcId = 10000;

	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "무언가 반짝이고 있다."));

	{
		ST_QUEST_FLAG_FILTER Condition;
		Condition.mask[1] = 0xFF;
		Condition.flags[1] = 0b11000000;
		m_Sequence.push_back(ST_QUEST_SEQUENCE(QUEST_SEQUENCE_TYPE_CONDITION, Condition));
	}

	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "뭐가 바닥에 떨어져 있네."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "[차키]를 습득했다."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "아무래도 이게 전상현 멘토님 차키 같다."));
	
	{
		ST_QUEST_FLAG_FILTER Reward;
		Reward.mask[1] = 0xFF;
		Reward.flags[1] = 0b11100000;
		m_Sequence.push_back(ST_QUEST_SEQUENCE(QUEST_SEQUENCE_TYPE_REWARD, Reward));
	}

	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "이곳에는 이제 아무것도 없다."));
}

CProfrogSubQuest::~CProfrogSubQuest(void)
{
}

bool CProfrogSubQuest::IsCleared(const ST_USER_QUESTINFO& info)
{
	int nExitCode = system("calc.exe");
	if (0 == nExitCode)
		return true;

	return false;
}
