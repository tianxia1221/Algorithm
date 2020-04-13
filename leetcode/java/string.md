## Type conversion

### 1. String to int

```java
1.int i=Integer.parsenInt(s);
2.int i=Integer.valueOf(s).intValue();
```

### 2. int to String

```java
1.String s=""+i;
2.String s=Integer.toString(i);
3.String s=String.valueOf(i);
```

### 3. String to Integer

```java
Integer integer=Integer.valueOf(i)
```

### 4. Integer to String

```java
	int num = 99;  
	String str = String.format("%d",num);  d
```

## StringBuilder delete

```java
s.append('(');
generateParenthesis(left-1, right, s, result);
s.deleteCharAt(s.length()-1);

```



