#include"makeHuffmanCode.h"


CODE *makeHuffmanCode(NODE *node) {

	NODE *child = NULL;
	NODE *parent = NULL;
	CODE *code = NULL;
	CODE *top = NULL;
	CODE *add = NULL;

	/* ������ */
	int value;
	int bit;


	/* �t�S�Ăɕ��������蓖�Ă��烋�[�v�I�� */
	/* �t�ȊO�̐߂̕�����'\0' */
	while (node != NULL && node->chr != '\0') {
		/* �����Ƃ��̃r�b�g����0�ɏ����� */
		value = 0;
		bit = 0;

		/* CODE�\���̂�ǉ� */
		add = (CODE*)malloc(sizeof(CODE));
		if (add == NULL) {
			printf("malloc error\n");
			return NULL;
		}

		/* �ǉ�����CODE�\���̂̕�����ݒ� */
		add->chr = node->chr;

		/* child�͍����ڂ��Ă���߂ւ̃|�C���^ */
		child = node;

		/* parent�͍����ڂ��Ă���߂̐e�ւ̃|�C���^ */
		parent = node->parent;

		/* �t���獪�܂Őe��k���Ă��� */
		/* ���̐߂�parent��NULL */
		while (parent != NULL) {
			/* �e���猩�č����ڂ��Ă���߂����̎q�̏ꍇ */
			if (parent->left == child) {
				/* �r�b�g��ivalue�j�̈�ԍ��փr�b�g0��ǉ� */
				value = value + (0 << bit);
				/* �e���猩�č����ڂ��Ă���߂��E�̎q�̏ꍇ */
			}
			else if (parent->right == child) {
				/* �r�b�g��ivalue�j�̈�ԍ��փr�b�g1��ǉ� */
				value = value + (1 << bit);
			}
			/* �r�b�g��̃r�b�g����1���₷ */
			bit++;

			/* �����ڂ��Ă���߂̐e���A�V���Ȓ��ڐ߂ɍX�V */
			child = parent;

			/* �e���e�̐e�ɍX�V */
			parent = parent->parent;
		}

		/* ���������ߏI������̂ŁA
		�ǉ�����CODE�ɕ������̂��̂Ƃ��̃r�b�g����ݒ� */
		add->value = value;
		add->bit = bit;

		/* CODE�\���̂��܂�����Ȃ��ꍇ */
		if (code == NULL) {
			code = add;
			top = code;

			/* CODE�\���̂����łɂ���ꍇ�͍Ō���ɒǉ� */
		}
		else {
			code->next = add;
			code = code->next;
		}

		/* ���̐߂ɑ΂��ĕ������Z�o */
		node = node->next;
	}

	return top;
}

