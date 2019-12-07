#pragma once
#include"data.h"
#include<stdio.h>
#include<stdlib.h>

NODE *searchNode(NODE *node, char chr);
NODE *newNode(char chr);
NODE *makeNodes(char *instr, long strlen);