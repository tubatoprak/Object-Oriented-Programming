package hw7;

import java.io.FileNotFoundException;
import java.io.IOException;

public abstract class AbstractBoard{
	 
	public int row;
	public int column;
	public int total;
	public int size;
	public int r_temp,c_temp;
	static int  numberofboards;
	/**
	 * set row and column
	 * @param r_temp row
	 * @param c_temp column
	 */
	public void set_row_column(int r_temp,int c_temp)
	{
		row = r_temp;
		column = c_temp;
		total = r_temp*c_temp;
	}
	/**
	 * @return return number of boards  
	 */
	public int NumberOfBoards()
	{
		return numberofboards;
	}
	/**
	 * set  give row and  given column
	 * @param x given row
	 * @param y given column
	 */
	public void setSize(int x,int y)
	{
		int[] puzzlesize = new int[x*y];
		
		System.out.println("----");
		int key =1;
		
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				puzzlesize[key] = key;
				System.out.println(puzzlesize[key]+" ");
				if(key<10)
					System.out.println(" ");
				key++;			
			}
			System.out.print("\n");
		}
	}
	/**
	 * @param filename reading  
	 * @exception FileNotFoundException when there is no file
	 */
	abstract void readFromFile(String filename) throws FileNotFoundException;
	/**
	 * Resets the board to the solution.
	 */
	abstract void reset();
	/**
	 * @param movee sends the desired move
	 */
	abstract void move(char movee);
	/**
	 * @return return  board is true or false 
	 */
	abstract boolean isSolved();
	/**
	 * @return return  data in given indexs
	 * @param i index i
	 * @param y index y 
	 */
	abstract String cell(int i,int y);
	/**
	 * @return return String 
	 */
	public abstract String toString();
	/**
	 * @return return  last move  
	 */
	abstract char lastMove();
	/**
	 * @return return  number of moves 
	 */
	abstract int numberOfMoves();
	/**
	 * @param filename writing  
	 * @exception FileNotFoundException when there is no file
	 */
	abstract void writeToFile(String filename) throws IOException;

}
