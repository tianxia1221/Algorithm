//Runtime: 12 ms, faster than 80.15% of Java online submissions for Top K Frequent Elements.
//Memory Usage: 40.6 MB, less than 61.21% of Java online submissions for Top K Frequent Elements.
class Node{
	int num;
	int count;
	public Node(int num, int count) {
		this.num = num;
		this.count = count;
	}
}

class MyCmp implements Comparator<Node>{
    public int compare(Node a){

    }
}

class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
    	List<Integer> res = new ArrayList<Integer>(k);
    	Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    	for(int num: nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
    	}

    	PriorityQueue<Node> smallQ = new PriorityQueue<Node>(k);
    	int count = 0;
    	for(Map.Entry<Integer, Integer> entry: map.entrySet()) {
    		count = entry.getValue();
    		if(smallQ.size()<k) {
    			smallQ.add(new Node(entry.getKey(), count));
    			continue;
    		}

    		if(count > smallQ.peek().count) {
    			smallQ.remove();
    			smallQ.add(new Node(entry.getKey(), count));
    		}
    	}

    	while(smallQ.size()>0) {
    		res.add(smallQ.peek().num);
    		smallQ.remove();
    	}
        return res;
    }
}