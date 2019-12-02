#include"makeNode.h"

/*
* �֐� : searchNode
* @param  chr   : ����NODE
* @param  node  : �����Ώە���
* @return NODE* : ��������NODE
* �T�v : �������̕������i�[����Ă���NODE������
*/
NODE *searchNode(NODE *node, char chr)
{
	while (node != NULL)
	{
		if (node->chr == chr)
		{
			return node;
		}
		node = node->next;
	}
	return node;
}

/*
* �֐� : newNode
* @param  chr   : �i�[����
* @return NODE* : �V�K����NODE
* �T�v : �V�K��NODE�𐶐����A�����̕������i�[/������
*/
NODE *newNode(char chr)
{
	// �V�KNODE(return�p)
	NODE *node;

	node = (NODE*)malloc(sizeof(NODE));

	if (node == NULL)
	{
		return NULL;
	}

	// NODE init
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;
	node->count = 1;
	node->chr = chr;

	return node;
}


/*
* �֐� : makeNodes
* @param  inputstr  : ����������̐擪Address
* @return NODE*     : �擪��NODEAddress
* �T�v : �e�����ɑ΂���NODE�𐶐�
*/
NODE *makeNodes(char *instr,long strlen)
{

	NODE *head;		// �擪NODE
	NODE *tail;		// ���[NODE
	NODE *add;      // �V�KResNODE
	NODE *search;   // �T��ResNODE

	// init
	char chr = NULL;
	head = NULL;
	tail = NULL;
	long i = 0;

	// �S�����ǂݎ��
	while (i < strlen)
	{
		// �ꕶ���ǂݎ��
		chr = *(instr + i);

		// �擾�����ɑ΂���߂�T���i�������������邩�ǂ����j 
		search = searchNode(head, chr);

		// ���ꕶ���������ꍇ
		if (search == NULL)
		{
			// �V�����߂�ǉ� 
			add = newNode(chr);

			if (add == NULL)
			{
				printf("node malloc error\n");
				return NULL;
			}

			// ���NODE���������A�V�KNODE��ݒ肷��
			if (head == NULL)
			{
				head = add;
				tail = add;
			}
			else 
			{
				tail->next = add;
				tail = add;
			}
		}
		else
		{
			// �o���񐔂̃J�E���g
			search->count++;
		}

		i++;

	}
	return head;
}
