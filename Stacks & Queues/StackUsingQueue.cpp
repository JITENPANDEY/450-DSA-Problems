void QueueStack :: push(int x)
{
        // Your Code
        // q1 = main queue, q2 = aux queue
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code
        int x = q1.size()>0? q1.front():-1;
        if(q1.size()>0) q1.pop();
        return x;
}