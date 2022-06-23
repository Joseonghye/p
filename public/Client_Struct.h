#pragma once

	enum SKILLTYPE { SKILL_PHY, SKILL_FIRE, SKILL_ICE, SKILL_ELECTRIC, SKILL_WIND, SKILL_LIGHT, SKILL_DARK, SKILL_UP, SKILL_DOWN, SKILL_END };
	typedef struct tagSkillData
	{
		std::string strName;

		SKILLTYPE eSkillType;		//Ÿ��

		int		iCost;
		int		iTarget;
		int		iAttCount;
		float	fDamage;
		float	fAccuracy;
		float	fCritical;

		std::string	EffectDesc = "";
		std::string strSkillDesc = "";


	}SKILLDATA;

	enum ATKTYPE { ATK_NEAR, ATK_FAR, ATK_END };
	typedef struct tagPlayerData
	{
		std::string	strName;
		std::string	strWeapon;
		std::string	strWeaponBone;
		std::string	strPersonaID;
		ATKTYPE		eAttackType;
		int	iLevel = 0;
		int	iMaxHp;
		int	iMaxMp;
		int	iHp;
		int	iMp;
	}PLAYERDATA;

	typedef struct tagCharPlayerData
	{
		const char*	strName;
		const char*	strWeapon;
		const char*	strWeaponBone;
		const char*	strPersonaID;
		ATKTYPE		eAttackType;
		int	iLevel = 0;
		int	iMaxHp;
		int	iMaxMp;
		int	iHp;
		int	iMp;
	}CHARPLAYERDATA;

	typedef struct tagPersonaData
	{
		std::string strName;
		int iLevel = 0;

		//����
		int iStr = 0;			//�� -����
		int iInt = 0;			//�� -����
		int iDef = 0;			//�� -����
		int iDex = 0;			//�� -����ȸ��,����
		int iLuk = 0;			//�� -ũ�� ��� �����

		unsigned int iTolerance = 0;		//����
		unsigned int iInvalidity = 0;	//��ȿ
		unsigned int iWeakness = 0;		//���� 

		SKILLDATA* Skills;	//��ų��� 
		int		iSkillCnt;

		std::string strModelName;

	}PERSONADATA;

	typedef struct tagEnemyData
	{
		std::string strName;
		std::string strLevel;

		int iMaxHp;
		int iHp;

		//����
		int iStr = 0;			//�� -����
		int iInt = 0;			//�� -����
		int iDef = 0;			//�� -����
		int iDex = 0;			//�� -����ȸ��,����
		int iLuk = 0;			//�� -ũ�� ��� �����

		unsigned int iTolerance = 0;	//����
		unsigned int iInvalidity = 0;	//��ȿ
		unsigned int iWeakness = 0;		//���� 

	}ENEMYDATA;

#define ELEMENT_PHYSICS		(1<<6)
#define ELEMENT_FIRE		(1<<5)
#define ELEMENT_ICE			(1<<4)
#define ELEMENT_ELECTRIC	(1<<3)
#define ELEMENT_WIND		(1<<2)
#define ELEMENT_LIGHT		(1<<1)
#define ELEMENT_DARK		(1<<0)