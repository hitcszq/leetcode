class LRUCache{
 private   
 int capacity;
 int storage;
 map<int,int> chunk;
 vector<int> keyqueue;
 map<int,int>::iterator iter;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
		this->storage=0;
    }
    
    int get(int key) {
        iter= chunk.find(key);
		if(iter != chunk.end())
		{
			return iter->second;
			
		}
		Else
		{
          return -1;
        }
    }
    
    void set(int key, int value) {
        if(this->storage<this->capacity)
		{
			chunk.insert(pair<int,int>(key,value));
			keyqueue.push_back(key);
		}
		else
		{
			
		}
    }
};