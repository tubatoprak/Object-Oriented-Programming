package hw8;

import java.util.Iterator;

public abstract class GTUContainer<T> implements Iterable<T>{

	private T[] arr;
	private int size = 0;
	final private int initialCap = 5;
	private int capacity = initialCap;
	
	
	@SuppressWarnings("unchecked")
	GTUContainer(){
		arr = (T[])new Object[capacity];
	}
	
	/**
	 *  Print for  Set or vector 
	 */
	public void print() {
		for(int i = 0; i < size ; i++)
			System.out.print(" " + arr[i]);
	}
	
	/**
	 *  @return of size
	 */
	public int size() {return size;}
	
	/**
	 *  @return  whether container is empty 
	 */
	public boolean empty() {return (size == 0);}
	
	/**
	 *  @return of  maximum size
	 */
	public int maxSize() {return capacity;}
	
	/**
	 *  @param  obj given Insert element 
	 *  @throws IllegalArgumentException when a problem arises while inserting
	 */
	public void insert(T obj) {
		if (checkInsert(obj)) {
			if (size == capacity)
				expand();
			arr[size] = obj;
			size++;
		} else {
			throw new IllegalArgumentException();
		}
	}
	
	/**
	 *  @param i given index  
	 *  @return data in given index 
	 */
	public T get(int i) {
		if (i >= 0 && i < size)
			return arr[i];
		else
			return null;
	}
	
	/**
	 *  @param obj that given element
	 */
	public void erase(T obj) {
		if (!contains(obj))
			return;
		
		for(int i =0; i < size; i++) {
			if(arr[i].equals(obj)) {
				for(int j = i; j <size-1 ;j++)
					arr[j]= arr[j+1];
				size--;
				return;
			}
		}		
	}
	
	/**
	 *  Clear all content 
	 */
	@SuppressWarnings("unchecked")
	public void clear() 
	{
		size = 0;
		capacity = initialCap;
		arr = (T[])new Object[capacity];
	}
	
	/**
	 *  @return iterator 
	 */
	public Iterator<T> iterator() {	return new GTUIterator<T>(this);}
	
	/**
	 * @param obj that given specified element 
	 * @return  true if this collection contains the specified element 
	 */
	public boolean contains(T obj) {
		for(int i = 0; i < size ; i++)
			if(arr[i].equals(obj))
				return true;
		return false;
	}
	
	/**
	 * @param obj that given specified element 
	 * @return  true if there is no same number
	 */
	abstract protected boolean checkInsert(T obj);
	
	@SuppressWarnings("unchecked")
	private void expand() {
		T[] temp = (T[])new Object[capacity*2];
		
		for(int i = 0; i< arr.length;i++)
		{
			temp[i]=arr[i]; 
		}
		
		arr = temp;
	}
	
	
}
