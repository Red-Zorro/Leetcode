#include <iostream>
#include <unordered_map>

using namespace std;

struct CacheNode {
	int key;
	int val;
	CacheNode *next;
	CacheNode *prev;
	CacheNode(int x, int y) : key(x), val(y), next(NULL),prev(NULL) {};
};

class LRUCache{
private:
	int size;
	unordered_map<int, CacheNode *> map;
	CacheNode *head;
	CacheNode *tail;
public:
    LRUCache(int capacity) {
        size=capacity;
		map.clear();
		head=NULL;
		tail=NULL;
    }
    
    int get(int key) {
		unordered_map<int, CacheNode *>::iterator  iter = map.find(key);
		if(iter==map.end()){
			// cout<<"Miss"<<endl;
			return -1;			
		}
		// cout<<"Get"<<endl;
        CacheNode *node = iter->second;
		if(node!=head){
			if(node==tail){
				tail=tail->prev;
				tail->next=NULL;
			}
			else {
				node->prev->next=node->next;
				node->next->prev=node->prev;
			}
			node->prev=NULL;
			node->next=head;
			head->prev=node;
			head=node;
		}
		return node->val;
    }
    
    void set(int key, int value) {
		int val = get(key);
		if(val!=-1){
			map[key]->val=value;
			return;
		}
		CacheNode *node = new CacheNode(key, value);
		node->next=head;
		if(head!=NULL)
			head->prev=node;
		head=node;
		if(tail==NULL)
			tail=node;
		if(map.size()==size){
			map.erase(tail->key);
			tail=tail->prev;
			delete tail->next;
			tail->next=NULL;
		}
		map.insert(make_pair(key, node));
	}
	friend void printList(LRUCache &);
};

void printList(LRUCache & target){
	CacheNode *node = target.head;
	cout<<"Forward: ";
	while(node!=NULL){
		cout<<"("<<node->key<<","<<node->val<<")";
		if(node->next!=NULL)
			cout<<"->";
		node=node->next;
	}
	cout<<endl<<"Backward: ";
	node = target.tail;
	while(node!=NULL){
		cout<<"("<<node->key<<","<<node->val<<")";
		if(node->prev!=NULL)
			cout<<"->";
		node=node->prev;
	}
	cout<<endl;
}

int main(void)
{
    int arr[][2]={{1,2},{2,1},{1,1},{4,2},{2,5},{5,3},{3,6},{1,1}};
	int len= sizeof(arr)/sizeof(int)/2;
	LRUCache cache(4);
	for(int i=0; i<len; i++){
		cache.set(arr[i][0],arr[i][1]);
		printList(cache);
	}
    return 0;
}
