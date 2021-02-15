#pragma once

#include "../QuestFramework/QuestFramework.h"

class CProfrogSubQuest : public CQuestInfoSuper
{
public:
	CProfrogSubQuest(void);
	~CProfrogSubQuest(void);

	bool IsCleared(const ST_USER_QUESTINFO& info);
};

