class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ret = new ArrayList<>();
        List<String> elm = new ArrayList<>();
        dfs(ret, elm, s, 0);
        return ret;
    }

    private void dfs(List<List<String>> ret, List<String> elm, String s, int pos) {
        int n = s.length();
        if (pos == n) {
            // List<String> e=new ArrayList<>(); //ok
            // e.addAll(elm);
            ret.add(new ArrayList<>(elm));
            return;
        }
        String cur;
        for (int i = pos + 1; i <= n; i++) { //i means end pos excusively
            if (isP(s, pos, i - 1)) {
                cur = s.substring(pos, i);
                elm.add(cur);
                dfs(ret, elm, s, i);
                elm.remove(elm.size() - 1);
            }
        }
    }

    private boolean isP(String s, int i, int j) {
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }
        return true;
    }
}