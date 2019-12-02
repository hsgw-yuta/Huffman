#pragma once
// typedef
typedef struct node NODE;
typedef struct code CODE;


/* �n�t�}���؂̐߃f�[�^ */
struct node {
	NODE *parent;        // �eaddress
	NODE *left;          // ����address
	NODE *right;         // �E��address
	NODE *next;          // �q��address
	unsigned int count;  // �o����
	char chr;            // ����
};

/* �n�t�}�������f�[�^ */
struct code {
	char chr;
	int value;
	char bit;
	CODE *next;
};

