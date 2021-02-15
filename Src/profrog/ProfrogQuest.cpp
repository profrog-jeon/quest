#include "stdafx.h"
#include "ProfrogQuest.h"

CProfrogQuest::CProfrogQuest(void)
	: CQuestInfoSuper()
{
	m_nTargetNpcId = 1;

	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "안녕? 난 보안개발트랙 멘토야."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "지금 C++ 강의를 하는 중이지~"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "윈도우와 리눅스의 크로스플랫폼 API에 관한 책을 쓴 저자란다."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "... 안물어봤어요 -_-"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "흥, 혹시 알아? 내가 책 한권 줄지.."));

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

	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "마침 API를 공부하려는데요,"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "그 책.. 어떻게 하면 받을 수 있을까요?"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "공부 열심히 하는 친구에게 주려고 했는데.."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "넌 아닌 것 같구나 -_- 딱보면 안다"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "헉 앞으로 열심히 할게요 ㅠㅠ"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "... 못믿겠지만 부탁 하나만 들어주면 줄게."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "급하게 강의하러 오다보니 차키를 잃어버렸어."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "좌표 (31, 147) 지점쯤이었던 것 같아."));

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

	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "혹시 이건가요?"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "(차키를 건네준다)"));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "어!!!!!! 맞아! 오늘 집에도 못갈뻔 했는데 니덕에 살았다."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "고마움의 표시로 이 책 너 줄게."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(0, "[크로스플랫폼 핵심모듈 설계의 기술 책]을 습득했다."));
	m_Sequence.push_back(ST_QUEST_SEQUENCE(m_nTargetNpcId, "앞으로 열심히 공부해 ^^"));

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
