class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        //TreeMap<String, List<String>> map = new TreeMap<>();
        Map<String, List> map = new TreeMap<>();

        for (String s : strs) {
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            String key = new String(ca);
            if (!map.containsKey(key)) map.put(key, new ArrayList());
            map.get(key).add(s);
        }
        List<List<String>> ret = new ArrayList<>();
        //map 遍历
        //way1
        // for (Map.Entry<String, List<String>> ss : map.entrySet()){
        //      ret.add(ss.getValue());
        //  }
        //way2
        // for(List<String> v: map.values()){
        for (List v : map.values()) {
            ret.add(v);
        }
        //way3
        // for(String key : map.keySet()){
        //     ret.add(map.get(key));
        // }

        //way4
//         Iterator<Map.Entry<String, List<String>>> entries = map.entrySet().iterator();
//         while(entries.hasNext()){
//             Map.Entry<String, List<String>> entry = entries.next();
//             String key = entry.getKey();
//             List<String> value = entry.getValue();
//             ret.add(value);
//         }

        return ret;
    }
}