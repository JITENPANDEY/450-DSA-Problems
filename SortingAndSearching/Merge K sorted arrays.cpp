struct Element{
    int value, row, col;
    Element(int v, int r, int c){
        value = v;
        row = r;
        col = c;
    }
};

struct compare{
    bool operator()(Element &a, Element &b){
        return a.value > b.value;
    }
};
class Solution
{
    public:
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        priority_queue<Element, vector<Element>, compare> pq;
        for(int i=0;i<K;i++){
            pq.push(Element(arr[i][0], i, 0));
        }
        while(!pq.empty()){
            Element e = pq.top();
            pq.pop();
            int val = e.value;
            int row = e.row;
            int col = e.col;
            
            ans.push_back(val);
            if(col+1<K){
                pq.push(Element(arr[row][col+1], row, col+1));
            }
            
        }
        //cout<<pq.empty()<<endl;
        return ans;
        
    }
};