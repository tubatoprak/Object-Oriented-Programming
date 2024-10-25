package hw7;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class BoardArray2D extends AbstractBoard {
	
	String[][] puzzle2;
	int[][] puzzlesize = new int[100][100];
	String[][] correctpuzzle2;
	int totalmoves2D = 0;	
	char lastmovee= 'S';
	
	public BoardArray2D()
	{
		numberofboards++;
	}
	/**
	 * create the right board.
	 */
	void reset_correct() 
	{
		int sayac = 0;
		ArrayList<String> temppuzzle2 = new ArrayList<>();
		for (int i = 0; i < column; ++i)
		{
			for (int k = 0; k < row; ++k)
			{
				if(!puzzle2[i][k].equals("00") && !puzzle2[i][k].equals("bb") )
				{
					temppuzzle2.add(new String( puzzle2[i][k] ));
					sayac++;
				}
			}	
		}
		Collections.sort(temppuzzle2);
		sayac = 0;
		correctpuzzle2 = new String[column][row];
		for (int i = 0; i < column; ++i)
		{
			for (int k = 0; k < row; ++k)
			{
				if (puzzle2[i][k].equals("00") )
				{
					correctpuzzle2[i][k]= "00";
				}
				else if (i == (column-1) && (k ==row-1))
					correctpuzzle2[column-1][row-1]= "bb";
				else
				{
					correctpuzzle2[i][k] = temppuzzle2.get(sayac);
					sayac++;
				}
			}	
		}
	}	
	/**
	 * Resets the board to the solution.
	 */
	@Override
	void reset() 
	{
		reset_correct();
		for (int i = 0; i < column; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				puzzle2[i][j] =correctpuzzle2[i][j];
			}
		}	
	}
	/**
	 * @param movee sends the desired move
	 */
	@Override
	void move(char movee) {
		lastmovee = movee;
		String temp;
		switch(movee)
		{
			case 'R':
					for (int i = 0; i < column; ++i)
					{
						for(int j= 0; j < row ; ++j)
						{
							if(puzzle2[i][j].equals("bb"))
							{
								if(!puzzle2[i][j+1].equals("00")  && j!=row-1)
								{
									
									puzzle2[i][j] = puzzle2[i][j+1];
									puzzle2[i][j+1] = "bb";
									i=column;
									j=row;
									totalmoves2D++;
								}
								else
									System.out.println("this move (R) can not be made");
							}
						}
					}	
			break;
			case 'L':
					
					for (int i = 0; i < column; ++i)
					{
						for(int j= 0; j < row ; ++j)
						{
							if(puzzle2[i][j].equals("bb"))
							{
								if(!puzzle2[i][j-1].equals("00")  && j!=0)
								{
					                temp = puzzle2[i][j-1];
					                puzzle2[i][j-1] = puzzle2[i][j];
					                puzzle2[i][j] = temp;
									i=column;
									j=row;
									totalmoves2D++;
								}
								else
									System.out.println("this move (L) can not be made");
							}
						}
					}
			break;
			case 'U':
					for (int i = 0; i < column; ++i)
					{
						for(int j= 0; j < row ; ++j)
						{
							if(puzzle2[i][j].equals("bb"))
							{
								if(!puzzle2[i-1][j].equals("00")  && i!=0)
								{
									temp = puzzle2[i-1][j];
									puzzle2[i-1][j] = puzzle2[i][j];
									puzzle2[i][j] = temp;
									i=column;
									j=row;
									totalmoves2D++;
								}
								else
									System.out.println("this move (U) can not be made");
							}
						}
					}
			break;
			case 'D':
					for (int i = 0; i < column; ++i)
					{
						for(int j= 0; j < row ; ++j)
						{
							if(puzzle2[i][j].equals("bb"))
							{
								if(!puzzle2[i+1][j].equals("00")  && i!=column-1)
								{
									temp = puzzle2[i][j];
									puzzle2[i][j] = puzzle2[i+1][j];
									puzzle2[i+1][j] = temp;
									i=column;
									j=row;
									totalmoves2D++;
								}
								else
									System.out.println("this move (D) can not be made");
							}
						}
					}
			break;
			default:
				System.out.println("Invalid Choice...");
		}
	}
	/**
	 * @return return  board is true or false 
	 */
	@Override
	boolean isSolved() {
		boolean finish = true;
		for (int i = 0; i < column; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				if(!puzzle2[i][j].equals(correctpuzzle2[i][j]))
				{
					return false;
				}
			}
		}
		return finish;
	}
	/**
	 * @return data in given indexs
	 * @param i index i
	 * @param y index y
	 */
	@Override
	String cell(int i, int y) {
		
		return puzzle2[i][y];
	}
	/**
	 * @return return String 
	 */
	@Override
	public String toString() 
	{
		String str ="";
		for(int i = 0; i<column ;i++)
		{
			for(int k = 0; k<row ;k++) 
			{
				str += puzzle2[i][k];
				str+=" ";
			}
			str += "\n";
		}	
		return str;
	}
	/**
	 * @return last move  
	 */
	@Override
	char lastMove()
	{	
		return lastmovee;
	}
	/**
	 * @return number of moves  
	 */
	@Override
	int numberOfMoves()
	{
		return totalmoves2D;
	}
	/**
	 * @param filename write  
	 * @exception FileNotFoundException when there is no file
	 */
	@Override
	void writeToFile(String filename) throws IOException{
		 BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
		    writer.write(toString());
		    writer.close();	
	}
	/**
	 * @param filename reading  
	 * @exception FileNotFoundException when there is no file
	 */
	@Override
	void readFromFile(String filename) throws FileNotFoundException 
	{
		File text = new File("./src/hw7/"+filename);
		try (Scanner scnr = new Scanner(text)) {
			int lineNumber = 0;
			int satir = 0;
			String[] temp = new String[1000];
			while(scnr.hasNextLine())
			{
			    String line = scnr.nextLine();
			    String[] ff = line.split(" ");             
			    
			    for(int i = 0;i < 9;i++)
			    {
			    	temp[lineNumber] = ff[i];
			    	lineNumber++;
			    }
			    satir++;
			}
			int sutun =lineNumber/satir;
			int sayac = 0;
			
			puzzle2 = new String[satir][sutun];
			correctpuzzle2 = new String[satir][sutun];
			
			for(int k =0 ;k <satir; k++) 
			{
				for(int j =0 ;j <sutun; j++) 
				{
					puzzle2[k][j] = temp[sayac];
					sayac++;
				}
				set_row_column(sutun,satir);
			
			}
		}
	}
	/**
	 * @param other the compared board
	 * @return Boards are equals or not equals 
	 */
	boolean Equals(BoardArray2D other)
	{
		String[][] board1 = this.puzzle2;
		String[][] board2 = other.puzzle2;
		if(!Arrays.equals(board1,board2))
			return false;
		return true;
	}

}
