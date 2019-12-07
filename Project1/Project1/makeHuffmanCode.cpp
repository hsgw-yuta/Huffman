#include"makeHuffmanCode.h"

/*
* �֐� : makeHuffmanCode
* @param  *node : �񕪖�NODE
* @return CODE* : ������List
* �T�v : �e�����̕����̎Z�o
*/
CODE *makeHuffmanCode(NODE *node)
{
	NODE *child = NULL;   // �qNODE
	NODE *parent = NULL;  // �eNODE
	CODE *code = NULL;    // �����f�[�^
	CODE *top = NULL;     // �����f�[�^�擪
	CODE *add = NULL;     // �V�K�����f�[�^

	// ����CODE���f�[�^
	int value = 0;
	int bit = 0;

	// �t�̂��ׂĂɕ��������蓖�Ă�
	while (node != NULL && node->chr != '\0')
	{

		// �����Ƃ��̃r�b�g����0�ɏ�����
		value = 0;
		bit = 0;

		// �V�KCODE����
		add = (CODE*)malloc(sizeof(CODE));
		if (add == NULL)
		{
			printf("malloc error\n");
			return NULL;
		}

		// �ǉ�CODE�ɕ������Z�b�g����
		add->chr = node->chr;

		// ���݃X�|�b�g����Ă���NODE�̑ޔ�
		child = node;

		// ���݃X�|�b�g����Ă���eNODE�ւ̃|�C���^ 
		parent = node->parent;

		// �t���獪�܂Őe�������̂ڂ� 
		while (parent != NULL)
		{
			// �e����̐�
			if (parent->left == child)
			{
				// �r�b�g��ivalue�j�̈�ԍ��փr�b�g0��ǉ� 
				value = value + (0 << bit);
			}
			else if (parent->right == child)
			{
				// �r�b�g��ivalue�j�̈�ԍ��փr�b�g1��ǉ� 
				value = value + (1 << bit);
			}

			// bit�����C���N�������g
			bit++;

			// ���݃X�|�b�g�̍X�V
			child = parent;

			// �e�̍X�V
			parent = parent->parent;
		}

		// �V�KCODE�ւ̒l�Z�b�g
		add->value = value;
		add->bit = bit;
		add->next = NULL;

		// CODE�\���̂����łɂ���ꍇ�͍Ō���ɒǉ�
		if (code == NULL)
		{
			code = add;
			top = code;
		}
		else
		{
			code->next = add;
			code = code->next;
		}

		// NODE�̃C���N�������g
		node = node->next;
	}

	return top;
}

