[toc]

# Initialize

## 1. Initialize ArrayList

> https://www.geeksforgeeks.org/initialize-an-arraylist-in-java/

```java
// create a ArrayList String type 
        // and Initialize an ArrayList with add() 
        ArrayList<String> gfg = new ArrayList<String>() { 
            { 
                add("Geeks"); 
                add("for"); 
                add("Geeks"); 
            } 
        }; 
```

```java
// create a ArrayList String type 
        // and Initialize an ArrayList with asList() 
        ArrayList<String> gfg = new ArrayList<String>( 
            Arrays.asList("Geeks", 
                          "for", 
                          "Geeks")); 
```

```
        // create a ArrayList String type 
        // and Initialize an ArrayList with List.of() 
        List<String> gfg = new ArrayList<>( 
            List.of("Geeks", 
                    "for", 
                    "Geeks")); 
```

```java
// create a ArrayList Integer type 
        // and Initialize an ArrayList with arr 
        List<Integer> gfg = new ArrayList<Integer>(arr);
```

## 2. Initialize an Array

```java
 int[] count = new int[26];
 Arrays.fill(count, 1);
```

## 3. Initialize a two dimension Array 

```java
        char[][] base = new char[n][n];
        for(char[] str : base) {
            Arrays.fill(str, '.');
        }

```

## 4. Initialize original array

```java
    int[][] dirs = new int[][]{{0,1},{0,-1},{1,0},{-1,0}};
```

