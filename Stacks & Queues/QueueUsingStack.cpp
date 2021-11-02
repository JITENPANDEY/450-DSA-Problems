void StackQueue :: push(int x)
{
    // Your Code
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s2.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
        // Your Code 
        int x = s1.empty()? -1 : s1.top();
        if(!s1.empty()) s1.pop();
        return x;
}