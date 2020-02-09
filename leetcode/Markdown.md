



[toc]

https://www.jianshu.com/p/b30955885e6d

## 1. 加粗

两个`**`或`__`会被HTML中的``标签包裹，例如：

## 2. Markdown中如何添加特殊符号

> https://blog.csdn.net/Logicr/article/details/82414854

 eg:     $\vee$ 	

```      $\vee$ 	
      $\vee$ 	
```

## 3. Markdown数学公式语法

> https://www.jianshu.com/p/e74eb43960a1

## 4. 字体颜色

```
<font face="黑体">我是黑体字</font>
<font face="微软雅黑">我是微软雅黑</font>
<font face="STCAIYUN">我是华文彩云</font>
<font color=#0099ff size=7 face="黑体">color=#0099ff size=72 face="黑体"</font>
<font color=#00ffff size=72>color=#00ffff</font>
<font color=gray size=72>color=gray</font>

Size：规定文本的尺寸大小。可能的值：从 1 到 7 的数字。浏览器默认值是 3

```



## un-ordered list

*   Red
*   Green
*   Blue

## ordered list
1.  Red
2.  Green
3.  Blue
4.  



- [ ] a task list item
- [ ] list syntax required
- [ ] normal **formatting**, @mentions, #1234 refs
- [ ] incomplete
- [x] completed



例如：
```
function test(){
  console.log("notice the blank line before this function?");
}
```
语法高亮：

<details> ```java </details>
``` java
String str = new String("hello world!");
System.out.println(str)    
```


$$
\mathbf{V}_1 \times \mathbf{V}_2 = \begin{vmatrix}
\mathbf{i} & \mathbf{j} & \mathbf{k} \
\frac{\partial X}{\partial u} & \frac{\partial Y}{\partial u} & 0 \
\frac{\partial X}{\partial v} & \frac{\partial Y}{\partial v} & 0 \
\end{vmatrix}
$$

| First Header | Second Header |
| ------------ | ------------- |
| Content Cell | Content Cell  |
| Content Cell | Content Cell  |

| Left-Aligned  | Center Aligned  | Right Aligned |
| :------------ | :-------------: | ------------: |
| col 3 is      | some wordy text |         $1600 |
| col 2 is      |    centered     |           $12 |
| zebra stripes |    are neat     |            $1 |

```markdown
你可以使用脚注像这样[^脚注]
[^脚注]: 这里写脚注的*文本*
```





你可以使用脚注像这样[^脚注]

[^脚注]: 这里写脚注的*文本*

你可以使用脚注像这样[^tx]



This is [an example](https://baidu.com/ "Title") inline link.

[This link](http://example.net/) has no title attribute.



This is [an example][id] reference-style link.

Then, anywhere in the document, you define your link label like this, on a line by itself:

[id]: http://example.com/  "Optional Title Here"



[Google][]
And then define the link:

[Google]: http://google.com/



<i@typora.io> 就变成了i@typora.io.

![](C:\Users\xtian5\Desktop\tmp\集体.jpg "Optional title")

``fasdf

`` sdfasfa

<a href="http://typora.io" target="_blank">link</a>.



- 使用`~`来包裹下标内容，例如：`H~2~O`,H2O， `X~long\ text~`/，Xlong text
- 使用`^`包裹上标内容，例如`X^2^`,X2
- 

X^2^



