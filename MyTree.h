#ifndef TREE_MYTREE_H
#define TREE_MYTREE_H

#include <string.h>
#include "Config.h"
#include "Errors.h"


typedef int elem_t;


typedef struct TreeNode
{
    int kan1;
    int secret;
    elem_t data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int kan2;
} node_t;


typedef struct Tree
{
    int kan1;
    node_t* head;
    int err;
    int kan2;
} tree_t;



node_t* NodeCreate(elem_t data)
{
    node_t* node = (node_t*) calloc(1, sizeof(node_t));
    node->kan1 = KAN1;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    node->kan2 = KAN2;
    return node;
}


node_t* TreeCreate(tree_t* tree)
{
    tree->kan1 = KAN1;
    tree->kan2 = KAN2;
    tree->err = 0;
    tree->head = NodeCreate(0);

    return tree->head;
}


node_t* TreeHead(const tree_t* tree)
{
    return tree->head;
}


node_t* TreeLeft(const node_t* node)
{
    return node->left;
}


node_t* TreeRight(const node_t* node)
{
    return node->right;
}


void NodeFill(node_t* node, elem_t data)
{
    node->data = data;
}


void NodePrint(const node_t* node)
{
    printf("%d\n", node->data);
}


void NodeRight (node_t* parent, node_t* child)
{
    parent->right = child;
    child->parent = parent;
}


void NodeLeft (node_t* parent, node_t* child)
{
    parent->left = child;
    child->parent = parent;
}


void NodeDelete(node_t* node)
{
    node->parent = nullptr;
    free(node);
}

void BranchDelete(node_t* node)
{
    if (node->left == nullptr)
        NodeDelete(node->left);
    else
        BranchDelete(node->left);

    if (node->right == nullptr)
        NodeDelete(node->right);
    else
        BranchDelete(node->right);
}

void FilePrintNode(FILE* fout, node_t* node)
{
    fprintf(fout, "%d", node->data);
}

void FileTextPrintTree(FILE* fout, node_t* node)
{
    if (!node)
    {
        return;
    }
    if ((node->left == nullptr) && (node->right != nullptr))
        fprintf(fout, "nil ");
    fprintf(fout, "%d ", node->data);
    FileTextPrintTree(fout, node->left);
    FileTextPrintTree(fout, node->right);
    fprintf(fout, "end ");
}

void FileTextRestoreTree (FILE* fin, node_t* node)
{
    node_t* temp = node;
    node_t* tempcpy = nullptr;
    int tempnum = 0;
    char str[STR_MAX] = "";

    fscanf(fin, "%s", &str);
    tempnum = atoi(str);
    NodeFill(temp, tempnum);

    while (fscanf(fin, "%s", str) != EOF)
    {
        if (strcmp(str, "end") == 0)
        {
            if (temp->parent != nullptr)
                tempcpy = temp->parent;
            temp = tempcpy;
        }
        else if (strcmp(str, "nil") == 0)
        {
            fscanf(fin, "%s", str);

            tempnum = atoi(str);
            tempcpy = NodeCreate(tempnum);
            if (temp->left == nullptr)
                NodeLeft(temp, tempcpy);
            else
                NodeRight(temp, tempcpy);
            temp = tempcpy;

            fscanf(fin, "%s", str);
            tempnum = atoi(str);
            tempcpy = NodeCreate(tempnum);
            NodeRight(temp, tempcpy);
            temp = tempcpy;
        }
        else
        {
            tempnum = atoi(str);
            tempcpy = NodeCreate(tempnum);
            if (temp->left == nullptr)
                NodeLeft(temp, tempcpy);
            else
                NodeRight(temp, tempcpy);
            temp = tempcpy;
        }
    }
}


void TreeGraph(FILE* fout, node_t* node)
{
    if (!node)
    {
        return;
    }
    if (node->left == nullptr)
        fprintf(fout, "%d -- 000%d000;\n", node->data, node->data);
    if (node->right == nullptr)
        fprintf(fout, "%d -- 000%d000;\n", node->data, node->data);
    if (node->parent != nullptr)
        fprintf(fout, "%d -- %d;\n", node->parent->data, node->data);
    TreeGraph(fout, node->left);
    TreeGraph(fout, node->right);
}
#endif //TREE_MYTREE_H
