class Solution {

    class Pair {
        int first;
        int second;

        Pair(Pair pair) {
            this.first = pair.first;
            this.second = pair.second;
        }
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public List<Integer> countSmaller(int[] nums) {
        int[] result = new int[nums.length];
        List<Pair> vec = new ArrayList<>(nums.length);
        for (int i = 0; i < nums.length; i++) {
            vec.add(new Pair(nums[i], i));
        }
        merge_sort(vec, result);

        List<Integer> res = new ArrayList<>();
        for (int i : result) res.add(i);

        return res;
    }


    private void merge_sort(List<Pair> vec, int[] result) {
        int size = vec.size();
        if (size < 2) {
            return;
        }
        int mid = size / 2;
        List<Pair> vec1 = new ArrayList<>();
        List<Pair> vec2 = new ArrayList<>();

        for (int i = 0; i < mid; i++) {
            vec1.add(new Pair(vec.get(i)));
        }
        merge_sort(vec1, result);

        for (int i = mid; i < vec.size(); i++) {
            vec2.add(new Pair(vec.get(i)));
        }
        merge_sort(vec2, result);

        vec.clear();
        merge(vec1, vec2, vec, result);

    }

    private void merge(List<Pair> vec1, List<Pair> vec2, List<Pair> vec, int[] result) {

        int i = 0, j = 0;
        while (i < vec1.size() && j < vec2.size()) {
            if (vec1.get(i).first > vec2.get(j).first) {
                vec.add(vec2.get(j));
                j++;
            } else {
                vec.add(vec1.get(i));
                result[vec1.get(i).second] += j;
                i++;
            }
        }

        for (; i < vec1.size(); i++) {
            vec.add(vec1.get(i));
            result[vec1.get(i).second] += j;
        }

        for (; j < vec2.size(); j++) {
            vec.add(vec2.get(j));
        }
    }
}
