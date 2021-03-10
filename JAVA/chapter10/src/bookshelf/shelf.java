package bookshelf;

import java.util.ArrayList;

public class shelf {
	protected ArrayList<String> shelf;
	
	public shelf() {
		shelf = new ArrayList<String>();
	}
	
	public ArrayList<String> getShelf(){
		return shelf;
	}
	
	public int getCount() {
		return shelf.size();
	}
}
