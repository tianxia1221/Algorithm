//
//Runtime: 2 ms, faster than 100.00% of Java online submissions for Flatten Nested List Iterator.
//        Memory Usage: 37.6 MB, less than 100.00% of Java online submissions for Flatten Nested List Iterator.
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    List<Integer> list;
    int cur;
    public NestedIterator(List<NestedInteger> nestedList) {
        list = new ArrayList<>();
        iterator(nestedList, list);
        if(list.size() == 0) cur = -1;
        else cur = 0;
    }

    @Override
    public Integer next() {
        if(cur == -1) return null;
        return list.get(cur++);
    }

    @Override
    public boolean hasNext() {
        if(cur == -1  || cur >=list.size() ) return false;
        return true;
    }

    void iterator(List<NestedInteger> nestedList, List<Integer> list){
        NestedInteger cur;
        for(int i=0; i<nestedList.size(); i++){
            cur = nestedList.get(i);
            if(cur.isInteger()) {
                list.add(cur.getInteger());
            }
            else{
                iterator(cur.getList(), list);
            }
        }

    }

}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */