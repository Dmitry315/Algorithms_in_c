<h1>Algorithms and data structures in C (need in refactoring)</h1>

<h2>Stack (NOT TESTED)</h2>
<h3>struct Stack</h3>
<h3>Stack *createStack(int length);</h3>
<h3>void updateStack(Stack *unit, int value);</h3>
<h3>Stack *pushStack(Stack *top, int value);</h3>
<h3>Stack *popStack(Stack *top);</h3>
<h3>int height(Stack *top);</h3>
<h3>void freeStack(Stack *top);</h3>

<h2>Queue (NOT TESTED)</h2>
<h3>struct Queue</h3>
<h3>struct Unit</h3>
<h3>Queue *createQueue(int length);</h3>
<h3>void updateQueue(Unit *unit, int value);</h3>
<h3>Queue *popQueue(Queue *q);</h3>
<h3>Queue *pushQueue(Queue *q, int value);</h3>
<h3>int lengthQueue(Queue *q);</h3>
<h3>void freeQueue(Queue *q);</h3>

<h2>Lists (NOT TESTED)</h2>
<h3>struct List</h3>
<h3>List *createList(int length);</h3>
<h3>List *push_front(List *lst, int value);</h3>
<h3>List *push_back(List *lst, int value);</h3>
<h3>List *searchList(List *lst, int value);</h3>
<h3>List *deleteList(List *lst, int value);</h3>
<h3>void freeList(List *lst);</h3>

<h2>AVL tree</h2>
<h3>struct TreeNode</h3>
<h3>void free_tree(TreeNode *node);</h3>
<h3>int height(TreeNode *p);</h3>
<h3>TreeNode *findmin(TreeNode *p);</h3>
<h3>TreeNode *findmax(TreeNode *p);</h3>
<h3>TreeNode *searchAVL(TreeNode *node, int key);</h3>
<h3>TreeNode *add(TreeNode *head, int key, int value);</h3>
<h3>TreeNode *deleteAVL(TreeNode *head, int key);</h3>
