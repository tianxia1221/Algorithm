//Runtime: 3 ms, faster than 56.93% of Java online submissions for Intersection of Two Arrays II.
//        Memory Usage: 36.3 MB, less than 83.87% of Java online submissions for Intersection of Two Arrays II.
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int[] num = nums1;
        int[] numMax = nums2;
        if(nums2.length < nums1.length) {
            num = nums2;
            numMax = nums1;
        }
        List<Integer> arr = new ArrayList<>();
        Map<Integer, Integer> hash = new HashMap<>();
        for(int i=0; i<num.length; i++){
            hash.put(num[i], hash.getOrDefault(num[i], 0) + 1);
        }

        for(int i: numMax) {
            if(hash.containsKey(i)){
                arr.add(i);
                if(hash.get(i) == 1)
                    hash.remove(i);
                else
                    hash.put(i, hash.get(i) - 1);
            }
        }

        int[] res = new int[arr.size()];
        for(int i=0; i<arr.size(); i++) {
            res[i] = arr.get(i);
        }

        return res;

    }
}