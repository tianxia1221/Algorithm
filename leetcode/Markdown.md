

[toc]

# title

https://www.jianshu.com/p/b30955885e6d

## 1. 加粗

两个`**`或`__`会被HTML中的``标签包裹，例如：

## 2. Markdown中如何添加特殊符号

>  List of Greek letters and math symbols
>
> https://www.overleaf.com/learn/latex/List_of_Greek_letters_and_math_symbols

> https://blog.csdn.net/Logicr/article/details/82414854

 eg:     $\vee$ 	

```      $\vee$ 	
      $\vee$ 	
```

## 3. Markdown数学公式语法

https://juejin.im/post/5a6721bd518825733201c4a2#heading-7

\\(a + b\\)

```
$x + y = z$ 
```


$$

$$

$x+y=z$

> https://www.jianshu.com/p/e74eb43960a1



### 空格

http://blog.sina.com.cn/s/blog_4ddef8f80100iwwv.html

| 两个quad空格 | a \qquad b | ![a \qquad b](http://upload.wikimedia.org/math/e/5/0/e505263bc9c94f673c580f3a36a7f08a.png) | 两个*m*的宽度  |
| ------------ | ---------- | ------------------------------------------------------------ | -------------- |
| quad空格     | a \quad b  | ![a \quad b](http://upload.wikimedia.org/math/d/a/8/da8c1d9effa4501fd80c054e59ad917d.png) | 一个*m*的宽度  |
| 大空格       | a\ b       | ![a\ b](http://upload.wikimedia.org/math/6/9/2/692d4bffca8e84ffb45cf9d5facf31d6.png) | 1/3*m*宽度     |
| 中等空格     | a\;b       | ![a\;b](http://upload.wikimedia.org/math/b/5/a/b5ade5d5393fd7727bf77fa44ec8b564.png) | 2/7*m*宽度     |
| 小空格       | a\,b       | ![a\,b](http://upload.wikimedia.org/math/7/b/e/7bea99aed60ba5e1fe8a134ab43fa85f.png) | 1/6*m*宽度     |
| 没有空格     | ab         | ![ab\,](http://upload.wikimedia.org/math/b/6/b/b6bd9dba2ebfca24731ae6dc3913e625.png) |                |
| 紧贴         | a\!b       | ![a\!b](http://upload.wikimedia.org/math/0/f/b/0fbcad5fadb912e8afa6d113a75c83e4.png) | 缩进1/6*m*宽度 |

```cpp
$O(n^2)$
```

Time complexity : $O(n^2)$



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

## 5. Jump 

### 1. local file

#### 1.1 way 1

```
[link](#title) jump to title
```

[link](#title) jump to title

#### 1.2 way 2

```
<a href="#其他markdown编辑器的实现方法">点击跳转</a>
```

按住Ctrl(Cmd)点击下面的连接就会跳到“其他markdown编辑器的实现方法”这一小节标题

<a href="#title">点击跳转</a>

### 2. Other file

```
<a href="5.md">点击跳转</a>
```

<a href="5.md">点击跳转</a>

### 3.  Link

引用图片和链接的唯一区别就是在最前方添加一个感叹号。

```
[点击跳转至百度](http://www.baidu.com)
```

[点击跳转至百度](http://www.baidu.com)

## 6. 脚标

```
X^2^
```

X^2^

```
使用`~`来包裹下标内容
```

H~2~O

## 7. 删除线

```
~~AAAAAA~~
```

~~AAAAAA~~

## 8.快捷方式

> 以上就是Markdown的基本的使用，最后奉上Markdown编辑器快捷键：· 加粗 Ctrl + B· 斜体 Ctrl + I· 引用 Ctrl + Q· 插入链接 Ctrl + L· 插入代码 Ctrl + K· 插入图片 Ctrl + G· 提升标题 Ctrl + H· 有序列表 Ctrl + O· 无序列表 Ctrl + U· 横线 Ctrl + R· 撤销 Ctrl + Z· 重做 Ctrl + Y

## 9. List

- 无序列表使用*或+或-标识
- 有序列表使用数字加.标识，例如：1.

```
* 黄瓜
* 玉米
* 茄子
```

*   黄瓜
*   玉米
*   茄子

1. 
2. ss

如果在单一列表项中包含了多个段落，为了保证渲染正常，*与段落首字母之间必须保留四个空格

```
*    段落一

     小段一
*    段落二

     小段二
```

- 段落一

  小段一

- 段落二

  小段二

- 段落一

  > sdfasdfasdf

## 10 分割线

```
***
---
```

---

## 11 特殊字符

Markdown使用反斜杠\插入语法中用到的特殊符号。在Markdown中，主要有以下几种特殊符号需要处理：

```
\   反斜线
`   反引号
*   星号
_   底线
{}  花括号
[]  方括号
()  括弧
#   井字号
+   加号
-   减号
.   英文句点
!   惊叹号
```

##  

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



- 使用`~`来包裹下标内容，例如：`H~2~O`,H2O， `X~long\ text~`/，Xlong text H~2~o
- 使用`^`包裹上标内容，例如`X^2^`,X2
- 

X^2^



