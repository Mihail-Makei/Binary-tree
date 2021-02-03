#include <stdlib.h>
#include <stdio.h>
#include "MyTree.h"

void test1();

void test2();

int main() {
    test1();
    test2();
    return 0;
}

void test1()
{
    tree_t tree = {};
    node_t* head = TreeCreate(&tree);
    NodeFill(head, 10);

    node_t* node1 = NodeCreate(20);
    node_t* node2 = NodeCreate(30);
    NodeLeft(head, node1);
    NodeRight(head, node2);

    node_t* node3 = NodeCreate(40);
    node_t* node4 = NodeCreate(50);
    NodeLeft(node1, node3);
    NodeRight(node1, node4);

    node_t* node5 = NodeCreate(60);
    node_t* node6 = NodeCreate(70);
    node_t* node7 = NodeCreate(80);
    node_t* node8 = NodeCreate(90);
    node_t* node9 = NodeCreate(100);
    node_t* node10 = NodeCreate(110);
    NodeLeft(node2, node6);
    NodeRight(node2, node5);
    NodeLeft(node6, node7);
    NodeRight(node7, node8);
    NodeLeft(node8, node9);
    NodeRight(node8, node10);

    FILE* fout = fopen("output.txt", "w");
    FileTextPrintTree(fout, head);
    fclose(fout);

    FILE* fgraph1 = fopen("graph1.gv", "w");
    fprintf(fgraph1, "graph tree {\n");
    TreeGraph(fgraph1, head);
    fprintf(fgraph1, "}");
    fclose(fgraph1);

    FILE* fin = fopen("output.txt", "r");
    FileTextRestoreTree(fin, TreeHead(&tree));
    fclose(fin);

    FILE* fresult = fopen("result.txt", "w");
    FileTextPrintTree(fout, TreeHead(&tree));
    fclose(fresult);

    FILE* fgraph2 = fopen("graph2.gv", "w");
    fprintf(fgraph2, "graph tree {\n");
    TreeGraph(fgraph2, head);
    fprintf(fgraph2, "}");
    fclose(fgraph2);
}


void test2()
{
    tree_t tree = {};
    node_t* head = TreeCreate(&tree);
    NodeFill(head, 10);

    node_t* node1 = NodeCreate(20);
    node_t* node2 = NodeCreate(30);
    NodeLeft(head, node1);
    NodeRight(head, node2);

    node_t* node3 = NodeCreate(40);
    node_t* node4 = NodeCreate(50);
    NodeLeft(node1, node3);
    NodeRight(node1, node4);

    node_t* node5 = NodeCreate(60);
    node_t* node6 = NodeCreate(70);
    node_t* node7 = NodeCreate(80);
    node_t* node8 = NodeCreate(90);
    node_t* node9 = NodeCreate(100);
    node_t* node10 = NodeCreate(110);
    NodeLeft(node2, node6);
    NodeRight(node2, node5);
    NodeLeft(node6, node7);
    NodeRight(node7, node8);
    NodeRight(node8, node9);
    NodeRight(node9, node10);

    FILE* fgraph = fopen("graph3.gv", "w");
    fprintf(fgraph, "graph tree {\n");
    TreeGraph(fgraph, head);
    fprintf(fgraph, "}");
    fclose(fgraph);
}