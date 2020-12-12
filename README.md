<h1>Algorithms and data structures in C</h1>

<h2>Stack (NOT TESTED)</h2>
<h3>struct Stack</h3>
<h3>Stack *create(void);</h3>
<h3>Stack *push(Stack *top, int value);</h3>
<h3>Stack *pop(Stack *top);</h3>
<h3>void free(Stack *top);</h3>

<h2>Queue (NOT TESTED)</h2>

<h2>Lists (NOT TESTED)</h2>
<h3>struct List</h3>
<h3>List *createList(int length);</h3>
<h3>List *push_front(List *lst, int value);</h3>
<h3>List *push_back(List *lst, int value);</h3>
<h3>List *search(List *lst, int value);</h3>
<h3>List *delete(List *lst, int value);</h3>
<h3>void free(List *lst);</h3>

<h2>AVL tree</h2>
<h3>struct TreeNode</h3>
<h3>void free_tree(TreeNode *node);</h3>
<h3>int height(TreeNode *p);</h3>
<h3>TreeNode *findmin(TreeNode *p);</h3>
<h3>TreeNode *findmax(TreeNode *p);</h3>
<h3>TreeNode *search(TreeNode *node, int key);</h3>
<h3>TreeNode *add(TreeNode *head, int key, int value);</h3>
<h3>TreeNode *del(TreeNode *head, int key);</h3>
