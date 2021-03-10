package test;

import java.util.ArrayList;

class Animal{
	
	public void move() {
		System.out.println("������ �����Դϴ�.");
	}
}

class Human extends Animal{
	
	public void move() {
		System.out.println("����� �ι߷� �Ƚ��ϴ�.");
	}
	
	public void readBook() {
		System.out.println("����� å�� �н��ϴ�.");
	}
}

class Tiger extends Animal{
	public void move() {
		System.out.println("Ȧ���̰� �׹߷� �ݴϴ�.");
	}
	
	public void hunting() {
		System.out.println("ȣ���̰� ����� �մϴ�.");
	}
}

class Eagle extends Animal{
	public void move() {
		System.out.println("�������� �ϴ��� �����ϴ�.");
	}
	
	public void flying() {
		System.out.println("�������� �ϴ��� ���� �ֽ��ϴ�.");
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
		
		ArrayList<Animal> animals = new ArrayList<Animal>(); // �����迭 ����
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
