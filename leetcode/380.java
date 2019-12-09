//Runtime: 10 ms, faster than 99.95% of Java online submissions for Insert Delete GetRandom O(1).
//        Memory Usage: 45.5 MB, less than 78.00% of Java online submissions for Insert Delete GetRandom O(1).
class RandomizedSet {

    Map<Integer, Integer> hm;
    List<Integer> arr;
    Random rand;

    /** Initialize your data structure here. */
    public RandomizedSet() {
        hm = new HashMap<>();
        arr = new ArrayList<>();
        rand = new Random();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (hm.containsKey(val)) return false;
        hm.put(val, arr.size());
        arr.add(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (false == hm.containsKey(val)) return false;
        int deleteIndex = hm.get(val);
        int lastIndex = arr.size() - 1;
        hm.remove(val);
        if (deleteIndex != lastIndex) {
            int modifiedKey = arr.get(lastIndex);
            arr.set(deleteIndex, modifiedKey);
            hm.put(modifiedKey, deleteIndex);
        }
        arr.remove(lastIndex);

        return true;
    }

    /** Get a random element from the set. */
    public int getRandom() {
        int random = rand.nextInt(arr.size());
        return arr.get(random);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */