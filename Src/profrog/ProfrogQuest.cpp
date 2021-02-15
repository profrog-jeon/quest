#include "stdafx.h"
#include "ProfrogQuest.h"

CProfrogQuest::CProfrogQuest(void)
	: CQuestInfoSuper()
{
	m_nTargetNpcId = 1;

	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "�ȳ�? �� ���Ȱ���Ʈ�� �����."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "���� C++ ���Ǹ� �ϴ� ������~"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "������� �������� ũ�ν��÷��� API�� ���� å�� �� ���ڶ���."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "... �ȹ���þ�� -_-"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "��, Ȥ�� �˾�? ���� å �ѱ� ����.."));

	{
		ST_QUEST_FLAG_FILTER Reward;
		Reward.mask[1] = 0xFF;
		Reward.flags[1] = 0b10000000;
		m_Sequence.push_back(ST_QUEST_SEQUENCE(QUEST_SEQUENCE_TYPE_REWARD, Reward));
	}

	{
		ST_QUEST_FLAG_FILTER Condition;
		Condition.mask[1] = 0xFF;
		Condition.flags[1] = 0b10000000;
		m_Sequence.push_back(ST_QUEST_SEQUENCE(QUEST_SEQUENCE_TYPE_CONDITION, Condition));
	}

	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "��ħ API�� �����Ϸ��µ���,"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "�� å.. ��� �ϸ� ���� �� �������?"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "���� ������ �ϴ� ģ������ �ַ��� �ߴµ�.."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "�� �ƴ� �� ������ -_- ������ �ȴ�"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "�� ������ ������ �ҰԿ� �Ф�"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "... ���ϰ����� ��Ź �ϳ��� ����ָ� �ٰ�."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "���ϰ� �����Ϸ� ���ٺ��� ��Ű�� �Ҿ���Ⱦ�."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "��ǥ (31, 147) �������̾��� �� ����."));

	{
		ST_QUEST_FLAG_FILTER Reward;
		Reward.mask[1] = 0xFF;
		Reward.flags[1] = 0b11000000;
		m_Sequence.push_back(ST_QUEST_SEQUENCE(QUEST_SEQUENCE_TYPE_REWARD, Reward));
	}

	{
		ST_QUEST_FLAG_FILTER Condition;
		Condition.mask[1] = 0xFF;
		Condition.flags[1] = 0b11100000;	// ProfrogSubQuest
		m_Sequence.push_back(ST_QUEST_SEQUENCE(QUEST_SEQUENCE_TYPE_CONDITION, Condition));
	}

	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "Ȥ�� �̰ǰ���?"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "(��Ű�� �ǳ��ش�)"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "��!!!!!! �¾�! ���� ������ ������ �ߴµ� �ϴ��� ��Ҵ�."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "������ ǥ�÷� �� å �� �ٰ�."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "[ũ�ν��÷��� �ٽɸ�� ������ ��� å]�� �����ߴ�."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "������ ������ ������ ^^"));

	{
		ST_QUEST_FLAG_FILTER Reward;
		Reward.mask[1] = 0xFF;
		Reward.flags[1] = 0b11110000;
		m_Sequence.push_back(ST_QUEST_SEQUENCE(QUEST_SEQUENCE_TYPE_REWARD, Reward));
	}
}

CProfrogQuest::~CProfrogQuest(void)
{
}

bool CProfrogQuest::IsCleared(const ST_USER_QUESTINFO& info)
{
	return info.Check(m_ClearCondition);
}
