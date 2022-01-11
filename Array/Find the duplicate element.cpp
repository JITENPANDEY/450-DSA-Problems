//method 1
int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        while(i<n){
            int correctIndex = arr[i]-1;
            if(arr[i]<n && arr[i]!=arr[correctIndex]){
                swap(arr[i], arr[correctIndex]);
            }
            else
                i++;
        }
        
        for(i=0;i<n;i++){
            if(arr[i]!=i+1){
                return arr[i];
            }
        }
        return -1;
        
    }

    //method 2
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0];
        int fast = arr[0];
        while(true){
          slow= arr[slow];
          fast= arr[arr[fast]];
            
          if(slow==fast)
              break;
        }

        slow = arr[0];
        while(slow!=fast){
          slow = arr[slow];
          fast = arr[fast];
        }
        return slow;

        
    }