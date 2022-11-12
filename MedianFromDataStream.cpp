class MedianFinder {
    
private:
    priority_queue<int,vector<int>>first_part; //maxheap;
    priority_queue<int,vector<int>,greater<int>>second_part; // minheap;
    
    
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if(first_part.size() == 0 || first_part.top() >= num )
        {
            first_part.push(num);
        }
        else{
            second_part.push(num);
        }
        
            balance();
     
    }
    
    
    void balance()
    {
        if(first_part.size() > (second_part.size()+1))
        {
            second_part.push(first_part.top());
            first_part.pop();
        }
        else if(second_part.size() > (first_part.size()+1))
        {
            first_part.push(second_part.top());
            second_part.pop();
        }
            
    }

    // Returns the median of current data stream
    double findMedian() {
        if(first_part.size() == second_part.size()) return ((first_part.top() + second_part.top()) / 2.0);
        else if(first_part.size() > second_part.size()) return first_part.top();
        else return second_part.top();
      
    }

        
    
};
