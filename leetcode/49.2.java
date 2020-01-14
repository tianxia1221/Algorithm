class Solution {

    void changStrToMapKey(String s, List<Integer> key) {
        for (int i = 0; i < key.size(); i++)
            key.set(i, 0);
        for (int i = 0; i < s.length(); i++) {
            int index = s.charAt(i) - 'a';
            int val = key.get(index) + 1;
            key.set(index, val);
        }

    }

    public List<List<String>> groupAnagrams(String[] strs) {
        //TreeMap<String, List<String>> map = new TreeMap<>();
        Map<List, List> map = new HashMap<>();
        List<Integer> key = new ArrayList<>(256);
        for (int i = 0; i < 256; i++)
            key.add(0);

        for (String s : strs) {
            changStrToMapKey(s, key);
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