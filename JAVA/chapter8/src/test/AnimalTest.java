package test;

import java.util.ArrayList;

class Animal{
	
	public void move() {
		System.out.println("동물이 움직입니다.");
	}
}

class Human extends Animal{
	
	public void move() {
		System.out.println("사람이 두발로 걷습니다.");
	}
	
	public void readBook() {
		System.out.println("사람이 책을 읽습니다.");
	}
}

class Tiger extends Animal{
	public void move() {
		System.out.println("홀랑이가 네발로 뜁니다.");
	}
	
	public void hunting() {
		System.out.println("호랑이가 사냥을 합니다.");
	}
}

class Eagle extends Animal{
	public void move() {
		System.out.println("독수리가 하늘을 날읍니다.");
	}
	
	public void flying() {
		System.out.println("독수리가 하늘을 날고 있습니다.");
	}
}

public class AnimalTest {

	public static void main(String[] args) {
		
		AnimalTest test = new AnimalTest();
		test.moveAnimal(new Human());
		test.moveAnimal(new Tiger());
		test.moveAnimal(new Eagle());
	
		Animal[] animalList = new Animal[3];
		animalList[0] = new Human();
		
		ArrayList<Animal> animals = new ArrayList<Animal>(); // 동적배열 생성
		animals.add(new Human());
		animals.add(new Tiger());
		animals.add(new Eagle());
		
	}
	
	public void moveAnimal(Animal ani) {
		ani.move();
		
		if ( ani instanceof Human) {
			Human human = (Human)ani;
			human.readBook();
		}
		else if( ani instanceof Tiger ) {
			Tiger tiger = (Tiger)ani;
			tiger.hunting();
		}
		else if ( ani instanceof Eagle) {
			Eagle eagle = (Eagle)ani;
			eagle.flying();
		}
	}
}
