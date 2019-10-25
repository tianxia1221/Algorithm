class Solution {
    class BIT {
        private int[] tree;

        public BIT(int n) {
            tree = new int[n];
        }

        public void update_node(int i, int val ) {
            int count = tree.length;
            while( i<count ) {
                tree[i] += val;
                i += i&(-i);
            }
        }

        int sum(int i) {
            int ret = 0;
            while( i>0 ) {
                ret += tree[i];
                i -= i&(-i);
            }
            return ret;
        }
    }

    public List<Integer> countSmaller(int[] nums) {
        Integer[] ret = new Integer[nums.length];
        Set<Integer> noDupNums = new TreeSet();
        for(int i: nums) noDupNums.add(i);

        HashMap<Integer, Integer> hmap = new HashMap<>() ;
        int j=0;
        // Iterator<Integer> it = noDupNums.iterator();
        // while (it.hasNext()) {
        //     hmap.put(it.next(), new Integer(++j));
        // }
        // for(Integer i: noDupNums) hmap.put(new Integer(i), new Integer(++j));

        for(Integer val: noDupNums) hmap.put(val, new Integer(++j));

        BIT bitOpt = new BIT(hmap.size() + 1);

        Integer index;
        for(int i = nums.length - 1; i>=0; i--) {

            index = hmap.get(nums[i]);
            bitOpt.update_node(index, 1);
            ret[i] = bitOpt.sum(index - 1);
        }

        return Arrays.asList(ret);
    }

}