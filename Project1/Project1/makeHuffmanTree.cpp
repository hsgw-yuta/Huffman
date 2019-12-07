#include"makeHuffmanTree.h"

/*
* �֐� : makeHuffmanTree
* @param  head  : List�̏I�[Address
* �T�v : �񕪖ؐ���
*/
void makeHuffmanTree(NODE *head)
{
	NODE *first = NULL;    // �o���񐔍ŏ�NODE
	NODE *second = NULL;   // �o����2�Ԗ�NODE
	NODE *tail = NULL;     // �Ō��NODE
	NODE *add = NULL;      // �V�KNODE


	// �擪�̐߂̊m�F
	if (head == NULL)
	{
		printf("%d head null\n", head);
		return;
	}

	// ���X�g�̏I�[�܂�tail���ړ� 
	tail = head;

	// tail�̌��ɒǉ����Ă���
	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	// �o���񐔂̏��Ȃ����2���擾
	getAppearance(&first, &second, head);

	// �e�̂��Ȃ��߂��Q�����ɂȂ�܂�
	// 
	while (first != NULL && second != NULL)
	{
		// ��ȏ゠��̂ŁA�eNODE���쐬����
		add = newNode('\0');

		if (add == NULL)
		{
			printf("malloc error\n");
			return;
		}

		// �eNODE init
		first->parent = add;
		second->parent = add;
		add->left = first;
		add->right = second;

		// count�̍��v
		add->count = first->count + second->count;

		// List�̏I�[�ɒǉ�
		tail->next = add;
		tail = add;
		getAppearance(&first, &second, head);
	}
}

/*
* �֐� : getAppearance
* @param  *first : �o���񐔍ŏ�
* @param  *scond : �o����2�Ԗ�
* @param  head  : List�̐擪address
* �T�v : ��ԖڂƓ�Ԃɏo���񐔏o���񐔂����Ȃ�NODE�̎��o��
*/
void getAppearance(NODE **first, NODE **scond, NODE *head)
{
	unsigned int firstNum = 99999;
	unsigned int secondNum = 99999;

	// ������
	*first = NULL;
	*scond = NULL;

	// ���X�g�̐擪����T�� (SORT)
	while (head != NULL)
	{
		if (head->parent == NULL)
		{
			if (firstNum > head->count && secondNum > head->count)
			{
				firstNum = head->count;
				*scond = *first;
				*first = head;
			}
			else if (secondNum > head->count)
			{
				secondNum = head->count;
				*scond = head;
			}
		}

		head = head->next;
	}
}
