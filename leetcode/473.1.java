class Solution {
    public boolean makesquare(int[] nums) {
        boolean[] visited = new boolean[nums.length];
        if(0==nums.length) return false;

        int sum = 0;
        for(int i: nums) sum += i;
        if(sum%4 != 0) return false;

        int target = sum/4;

        Arrays.sort(nums);
        return dfs(nums, nums.length-1, target, visited) && dfs(nums, nums.length-1, target, visited) && dfs(nums, nums.length-1, target, visited);

    }

    boolean dfs(int[] nums, int end,  int target, boolean[] visited) {
        for(int i=end; i>=0; i--) {
            if(visited[i] == true) continue;

            visited[i] = true;
            target -= nums[i];
            if(0 == target) {
                return true;
            }
            if(target > 0) {
                if(dfs(nums, i-1, target, visited)) {
                    return true;
                }
                //trace back
                visited[i] = false;
                target += nums[i];
                return dfs(nums, i-1, target, visited);
            }

            //trace back
            visited[i] = false;
            target += nums[i];

        }
        return false;
    }
}