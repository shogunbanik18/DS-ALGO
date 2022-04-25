/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

// using queue
class PeekingIterator : public Iterator {
public:
    queue<int>q;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) 
    {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    for(auto x : nums)
        {
            q.push(x);
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() 
    {
        auto a = q.front();
        return a;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() 
    {
        auto a = q.front();
        q.pop();
        
        return a;
	}
	
	bool hasNext() const 
    {
        if(!q.empty())
        {
            return true;
        }
        return false;
	    
	}
};
