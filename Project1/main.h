#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"data.h"

// プロトタイプ宣言
extern NODE *makeNodes(char *inputstr);
extern NODE *searchNode(NODE *node, char chr);
extern NODE *newNode(char chr);
extern void makeHuffmanTree(NODE *head);
extern void getAppearance(NODE **first, NODE **scond, NODE *head);
extern CODE *makeHuffmanCode(NODE *node);
void freeNode(NODE *node);