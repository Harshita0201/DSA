//using stackk:
    stack<int> s;
    while(!q.empty()){
        int ele=q.front();
        q.pop();
        s.push(ele);
    }
    
    while(!s.empty()){
        int ele=s.top();
        s.pop();
        q.push(ele);
    }
    return q;


//using recursion:

// void solve(queue<int> &q){
//     // Base case
//     if (q.empty())
//         return;
 
//     // Dequeue current item (from front) 
//     int data = q.front();
//     q.pop();
 
//     // Reverse remaining queue 
//     solve(q);
 
//     // Enqueue current item (to rear) 
//     q.push(data);
    
// }
// //Function to reverse the queue.
// queue<int> rev(queue<int> q)
// {
//    solve(q);
//    return q;    
    
// }
