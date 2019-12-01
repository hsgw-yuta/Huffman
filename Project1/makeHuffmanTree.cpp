#include"makeHuffmanTree.h"

/* �񕪖ؐ��� */
void makeHuffmanTree(NODE *head)
{
	NODE *first = NULL;
	NODE *second = NULL;
	NODE *tail = NULL;
	NODE *add = NULL;

	// �擪�̐߂̊m�F
	if (head == NULL)
	{
		printf("����������");
	}

	// ���X�g�̏I�[�܂�tail���ړ� 
	tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	// �o���񐔂����߂�
	getAppearance(&first, &second, head);

	/* �e�̂��Ȃ��߂��Q�����ɂȂ�܂Ń��[�v */
	while (first != NULL && second != NULL)
	{
		/* �V�����m�[�h��ǉ� */
		/* ��������'\0'�Ƃ��� */
		add = newNode('\0');
		if (add == NULL)
		{
			printf("malloc error\n");
			return;
		}


		/* �ǉ������߂�left��right�̐e�ƂȂ�悤�Ƀp�����[�^�ݒ� */
		first->parent = add;
		second->parent = add;
		add->left = first;
		add->right = second;
		add->count = first->count + second->count;

		/* �ǉ������߂����X�g�̏I�[�ɓo�^ */
		tail->next = add;
		tail = add;

		/* �o���񐔂̏��Ȃ���̐߂��擾 */
		getAppearance(&first, &second, head);
	}
}

/*
* �֐� : getAppearance
* @param  first : �o���񐔍ŏ�
* @param  scond : �o����2�Ԗ�
* @param  head  : List�̐擪address
* �T�v : ��ԖڂƓ�Ԃɏo���񐔏o���񐔂����Ȃ�NODE�̎��o��
*/
void getAppearance(NODE **first, NODE **scond, NODE *head) {

	unsigned int firstNum = 99999;
	unsigned int secondNum = 99999;

	// ������
	*first = NULL;
	*scond = NULL;

	/* ���X�g�̐擪����T�� */
	while (head != NULL) {
		if (head->parent == NULL) {
			if (firstNum > head->count && secondNum > head->count) {
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
		/* head�����̐߂֐i�܂��� */
		head = head->next;
	}
}
