package test;


import java.util.Comparator;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class MyComparator implements Comparator {

	public int compare(Object o1, Object o2) {
		StudentNoCmp p1 = (StudentNoCmp) o1;
		StudentNoCmp p2 = (StudentNoCmp) o2;
//		if (p1.score < p2.score)
//			return 1;
//		else if (p1.score > p2.score)
//			return -1;
//		else
//			return 0;
//		
//		jim : 92
//		tom : 89
//		jack : 77
		
		return p1.score - p2.score;
	}
}

class StudentNoCmp {
	String name;
	int score;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getScore() {
		return score;
	}
	public void setScore(int score) {
		this.score = score;
	}
}
class Student implements Comparable<Student> {

	String name;
	int score;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getScore() {
		return score;
	}
	public void setScore(int score) {
		this.score = score;
	}
	
	@Override
	public int compareTo(Student o) {
		// TODO Auto-generated method stub
		return score - o.score;
	}
}

public class ScoreSort{
 
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		List s = new ArrayList();
		StudentNoCmp b = new StudentNoCmp();
		b.name = "tina";
		b.score = 89;
		s.add(b);
 
		b = new StudentNoCmp();
		b.name = "jessie";
		b.score = 92;
		s.add(b);
 
		b = new StudentNoCmp();
		b.name = "Jim";
		b.score = 77;
		s.add(b);
 
		for(int i=0 ;i < s.size();i++){
			b = (StudentNoCmp)s.get(i);
			System.out.println(b.name + " : " + b.score);
		}
 
		System.out.println("------------------------");
 
		Collections.sort(s,new MyComparator());  
 
		for(int i=0 ;i < s.size();i++){
			b = (StudentNoCmp)s.get(i);
			System.out.println(b.name + " : " + b.score);
		}
 
		ArrayList<Student> ss = new ArrayList<>();
		Student bb = new Student();
		bb.name = "tina";
		bb.score = 89;
		ss.add(bb);
 
		bb = new Student();
		bb.name = "jessie";
		bb.score = 92;
		ss.add(bb);
 
		bb = new Student();
		bb.name = "Jim";
		bb.score = 77;
		ss.add(bb);
		System.out.println("------------------------");
		Collections.sort(ss);  
		for(int i=0 ;i < ss.size();i++){
			bb = ss.get(i);
			System.out.println(bb.name + " : " + bb.score);
		}
	}

}

