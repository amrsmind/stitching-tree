You have a binary tree where each node has a pointer to the left child and the right child.
Imagine that we added a third pointer to the node definition called "NextBrother".
Now we need you to write a function called "Stitch" which takes the root of the tree and fills the "NextBrother" pointer with the following rules
NextBrother should point to the next node on the same level of the current node
Next node could be a child of the same parent or another parent
This is represented by the red horizontal line. *check 'checkme.jpg'*




