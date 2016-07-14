class LRUCache{
 private :  
 int capacity;
 int storage;
 multimap<int,int> chunk;
 multimap<int,int> use_rec;
 multimap<int,int>::iterator iter;
 multimap<int,int>::iterator iter_rec;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
		this->storage=0;
    }
    
    int get(int key) {
        iter= chunk.find(key);
		//iter_rec=use_rec.find(key);
		if(iter!=chunk.end())
		{
			for(iter_rec=use_rec.begin();iter_rec != chunk.end();++iter_rec)
			{
				if(iter_rec->first!=key)
					iter_rec->second++;
			}
			return iter->second;
		}
		else
		{
          return -1;
        }
    }
    
    void set(int key, int value) {
		int min_use=0;
		int min_key=0;
        if(this->storage<this->capacity)
		{
			chunk.insert(pair<int,int>(key,value));
			use_rec.insert(pair<int,int>(key,1));
			
			storage=storage+1;
		}
		else
		{
			for(iter_rec=use_rec.begin();iter_rec!=use_rec.end();++iter_rec)
			{
				if(iter_rec->second<min_use)
				{
					min_use=iter_rec->second;
					min_key=iter_rec->first;
				}
			}
			chunk.erase(min_key);
			chunk.insert(pair<int,int>(key,value));
			use_rec.insert(pair<int,int>(key,1));
		}
    }
};

 /*    由于键值允许重复插入，在 multimap 容器中具有同一个键值的元素有可能不只一个。因此，multimap 容器的 find 函数将返回第一个搜索到的元素位置，如果元素不存在，则返回 end 结束元素位置。equal_range 函数则返回一个可指示相等元素范围区间的 pair 对象。
 2 */