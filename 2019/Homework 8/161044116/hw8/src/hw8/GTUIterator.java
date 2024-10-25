package hw8;

import java.util.Iterator;

public class GTUIterator<T> implements Iterator<T> {
	
	private int cursor = 0;
	private GTUContainer<T> cont;
	
	GTUIterator(GTUContainer<T> obj){
		cont = obj;
	}
	
	@Override
	public boolean hasNext() {
		return cursor < cont.size();
	}
	
	@Override
	public T next() {
		cursor++;
		return cont.get(cursor - 1);
	}
}
