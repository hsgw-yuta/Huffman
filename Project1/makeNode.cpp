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
	NODE *node;


	node = (NODE*)malloc(sizeof(NODE));

	if (node == NULL)
	{
		return NULL;
	}

	// NULL�ŏ�����
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
* @return NODE*     :
* �T�v : �e�����ɑ΂���NODE�𐶐�
*/
NODE *makeNodes(char *inputstr)
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

	/* �S�����ǂݏI���܂łP�������ǂݎ�� */
	while (i < 10) {
		chr = *(inputstr + i);
		/* ���̕����ɑΉ�����߂�T�� */
		search = searchNode(head, chr);
		if (search == NULL) {
			/* �߂��Ȃ��ꍇ�͐V�����߂�ǉ� */
			add = newNode(chr);
			if (add == NULL)
			{
				printf("node malloc error\n");
				return NULL;
			}

			if (head == NULL)
			{
				head = add;
				tail = add;
			}
			else // ���łɑ��� -> �I�[�ɒǉ�
			{
				tail->next = add;
				tail = add;
			}
		}
		else
		{
			/* ���̕����ɑΉ�����߂�����ꍇ�͏o���֐����J�E���g�A�b�v */
			search->count++;
		}
		i++;
	}
	return head;
}
