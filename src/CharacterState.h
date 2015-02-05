#ifndef CHARACTERSTATE_H
#define CHARACTERSTATE_H

enum CharacterStateJump
{
	NOJUMP,
	JUMP,
	JUMP2,
	FALL,
	FALL2
};

enum CharacterStateWalk
{
	IDLE,
	WALK,
	BACKDASH
};

enum CharacterStateAttack
{
	NOATTACK,
	ATTACK
};

enum CharacterStateRedSoul
{
	NORSOUL,
	RSOUL
};

enum CharacterStateBlueSoul
{
	NOBSOUL,
	BSOUL
};

#endif // CHARACTERSTATE_H

