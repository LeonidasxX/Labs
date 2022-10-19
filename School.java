package com.course.structure;

import java.util.*;

public class School extends Building{
	private int classRooms;
	private String grade;

	public void setclassRooms(int classRooms){
		this.classRooms = classRooms;
	}

	public int getclassRooms(){
		return classRooms;
	}

	public void setgrade(String grade){
		this.grade = grade;
	}

	public String getgrade(){
		return grade;
	}

}