package hw8;

public class GTUSet<T> extends GTUContainer<T> {
	/**
	 * @param specified element given obj
	 * @return  true if there is no same number
	 */
	@Override
	protected boolean checkInsert(T obj) {
		return !contains(obj);
	}

}