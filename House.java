package com.course.structure;

import java.util.*;

public class House extends Building{
	private int bedRooms;
	private int baths;

	public void setbedRooms(int bedRooms){
		this.bedRooms = bedRooms;
	}

	public int getbed(){
		return this.bedRooms;
	}

	public void setbaths(int baths){
		this.baths = baths;
	}

	public int getbaths(){
		return this.baths;
	}

}