package test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

@SuppressWarnings("rawtypes")
class Node implements Comparable {
	String key;
	int count;
	Node(String key, int count) {
		this.key = key;
		this.count = count;
	}
	@Override
	public int compareTo(Object o) {
		Node that = (Node) o;
		int ret = this.count - that.count;
		if(0 == ret) {
			return that.key.compareTo(key);
		}
		return ret;
	}
}

public class IV1 {
	public static ArrayList<String> retFs(int numFs,
											 int topFs,
											 List<String> possibleFs,
											 int numReqs,
											 List<String> reqs) {
		ArrayList<String> ret = new ArrayList<>();
		ArrayList<String> res = new ArrayList<>();
		Map<String, Integer> hm = new HashMap<>();
		Map<String, String> caseHm = new HashMap<>();
		String[] arr = null;
		String key = null;
		PriorityQueue<Node> smallQ = new PriorityQueue<Node>();
		Node node = null;
		
		if(topFs > numReqs) topFs = numReqs;
		if(topFs == 0) return ret;
		
		for(int i=0; i<numFs; i++) {
			String str = possibleFs.get(i).toLowerCase();
			hm.put(str, 0);
			caseHm.put(str, possibleFs.get(i));
		}
		
		for(int i=0; i<numReqs; i++) {
			Set<String> hs = new HashSet<>();
			arr = reqs.get(i).split(" ");
			for(int j=0; j<arr.length; j++) {
				key = arr[j].toLowerCase();
				if(false == hm.containsKey(key)) continue;
				if(hs.add(key) == false) continue;
				hm.put(key, hm.get(key) + 1);
			}
		}
		
		for(String k: hm.keySet()) {
			node = new Node(k, hm.get(k));
			if(topFs > 0) {
				smallQ.add(node);
				topFs--;
				continue;
			}
			if(node.compareTo(smallQ.peek()) > 0 ) {
				smallQ.poll();
				smallQ.add(node);
			}
		}
		
		while(smallQ.size() != 0) ret.add(smallQ.poll().key);
		
		//Collections.reverse(ret);
		
		for(int i=ret.size()-1; i>=0; i--) res.add(caseHm.get(ret.get(i)));
		
		return res;	
	}
	
	public static void main(String[] args) { 
		int numFs = 6;
		 int topFs = 2;
		 
		 List<String> possibleFs = new ArrayList<>();
		 possibleFs.add("dell");
		 possibleFs.add("emc");
		 possibleFs.add("hover");
		 possibleFs.add("VMWare");
		 possibleFs.add("HP");
		 possibleFs.add("solar");
		 
		 int nReqs = 7;
		 
		 List<String> reqs = new ArrayList<>();
		 reqs.add("even more dell" );
		 reqs.add("emc life" );
		 reqs.add("HP" );
		 reqs.add("HP emc two IBM" );
		 reqs.add("HP please hp" );
		 reqs.add("net hover" );
		 reqs.add("solar power" );

		 List<String> ret = retFs(numFs, topFs ,possibleFs ,nReqs ,reqs);
		 System.out.println(ret);
	}
}
