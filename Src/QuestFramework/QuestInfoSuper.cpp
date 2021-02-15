#include "stdafx.h"
#include "QuestInfoSuper.h"

CQuestInfoSuper::CQuestInfoSuper(void)
	: m_nTargetNpcId(0)
	, m_nIndex(0)
{
}

CQuestInfoSuper::~CQuestInfoSuper(void)
{
}

int CQuestInfoSuper::GetID(void)
{
	return m_nTargetNpcId;
}

void CQuestInfoSuper::Check(ST_USER_QUESTINFO& userInfo, std::vector<ST_NPC_MESSAGE>& outMessage)
{
	int nConditionIndex = m_nIndex;
	for (int i = m_nIndex; i<(int)m_Sequence.size(); i++)
	{
		const ST_QUEST_SEQUENCE& seq = m_Sequence[i];
		if (QUEST_SEQUENCE_TYPE_CONDITION != seq.nType)
			continue;

		if (!userInfo.Check(seq.filter))
			break;

		nConditionIndex = i;
	}

	while (m_nIndex < (int)m_Sequence.size())
	{
		const ST_QUEST_SEQUENCE& seq = m_Sequence[m_nIndex];
		if (QUEST_SEQUENCE_TYPE_MESSAGE == seq.nType)
			outMessage.push_back(seq.message);

		if (QUEST_SEQUENCE_TYPE_CONDITIONAL_MESSAGE == seq.nType && nConditionIndex < m_nIndex)
			outMessage.push_back(seq.message);

		if (QUEST_SEQUENCE_TYPE_REWARD == seq.nType)
			userInfo.Apply(seq.filter);

		if (QUEST_SEQUENCE_TYPE_CONDITION == seq.nType && !userInfo.Check(seq.filter))
			break;

		m_nIndex++;
	}

	// ���ǿ� �ɷ��� �ƹ��� ��ȭ�� ���� �� ���ٸ� ���� ��ȭ�� ã�Ƽ� �־���
	if (!outMessage.empty())
		return;

	int i;
	for (i = m_nIndex-1; 0 <= i; i--)
	{
		if (QUEST_SEQUENCE_TYPE_MESSAGE != m_Sequence[i].nType &&
			QUEST_SEQUENCE_TYPE_CONDITIONAL_MESSAGE != m_Sequence[i].nType)
			continue;

		outMessage.push_back(m_Sequence[i].message);
		break;
	}

	// �Ǽ��� �޽����� ������ ���� ����Ʈ���� ���Ǹ� ��
	if (outMessage.empty())
		outMessage.push_back(ST_NPC_MESSAGE(0, "** �ƹ� �޽����� �����ϴ�. ���� ���ƿ�..~ **"));
}
