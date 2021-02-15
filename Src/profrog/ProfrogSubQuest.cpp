#include "stdafx.h"
#include "ProfrogSubQuest.h"

CProfrogSubQuest::CProfrogSubQuest(void)
	: CQuestInfoSuper()
{
	m_nTargetNpcId = 10000;

	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "���� ��¦�̰� �ִ�."));

	{
		ST_QUEST_FLAG_FILTER Condition;
		Condition.mask[1] = 0xFF;
		Condition.flags[1] = 0b11000000;
		m_Sequence.push_back(ST_QUEST_SEQUENCE(QUEST_SEQUENCE_TYPE_CONDITION, Condition));
	}

	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "���� �ٴڿ� ������ �ֳ�."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "[��Ű]�� �����ߴ�."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "�ƹ����� �̰� ������ ����� ��Ű ����."));
	
	{
		ST_QUEST_FLAG_FILTER Reward;
		Reward.mask[1] = 0xFF;
		Reward.flags[1] = 0b11100000;
		m_Sequence.push_back(ST_QUEST_SEQUENCE(QUEST_SEQUENCE_TYPE_REWARD, Reward));
	}

	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "�̰����� ���� �ƹ��͵� ����."));
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
