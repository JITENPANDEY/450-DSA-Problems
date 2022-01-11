void RecursiveCloneStack(stack<int>& S,
                         stack<int>& Des)
{
    // Base case for Recursion
    if (S.size() == 0)
        return;
 
    // Stores the top element of the
    // source stack
    int val = S.top();
 
    // Removes the top element of the
    // source stack
    S.pop();
 
    // Recursive call to the function
    // with remaining stack
    RecursiveCloneStack(S, Des);
 
    // Push the top element of the source
    // stack into the Destination stack
    Des.push(val);
}