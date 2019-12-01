#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"data.h"

// �v���g�^�C�v�錾
extern NODE *makeNodes(char *inputstr);
extern NODE *searchNode(NODE *node, char chr);
extern NODE *newNode(char chr);
extern void makeHuffmanTree(NODE *head);
extern void getAppearance(NODE **first, NODE **scond, NODE *head);
extern CODE *makeHuffmanCode(NODE *node);
void freeNode(NODE *node);