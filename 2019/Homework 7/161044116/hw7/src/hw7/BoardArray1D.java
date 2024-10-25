package hw7;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class BoardArray1D extends AbstractBoard 
{
	String[] puzzle1 = new String[100] ;
	String[] correctpuzzle1 = new String[100];
	int totalmoves1D = 0;	
	char lastmovee= 'S';
	
	public BoardArray1D()
	{
		numberofboards++;
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
			puzzle1 = new String[satir*sutun];
			for(int k =0 ;k <(satir*sutun); k++) 
			{
				puzzle1[k] = temp[k];
			}
			set_row_column(sutun,satir);
		}
        reset_variable();
	}
	/**
	 * All variable reset
	 */
	public void reset_variable()
	{
		correctpuzzle1 = new String[row*column];
		totalmoves1D = 0;
		total = (row*column);
	}
	/**
	 * create the right board.
	 */
	public void reset_correct()
	{
		
		int sayac = 0;
		
		ArrayList<String> temppuzzle1 = new ArrayList<>();
		
		
		
		for (int i = 0; i < total; ++i)
		{
			if(!puzzle1[i].equals("00") && !puzzle1[i].equals("bb") )
			{
				temppuzzle1.add(new String( puzzle1[i] ));
				sayac++;
			}
		}
		
		Collections.sort(temppuzzle1);
		
		sayac = 0;
		for (int i = 0; i < total - 1; ++i)
		{
			if (puzzle1[i].equals("00") )
			{
				correctpuzzle1[i]= "00";
			}
			else
			{
				correctpuzzle1[i] = temppuzzle1.get(sayac);
				sayac++;
			}
		}
		correctpuzzle1[total-1]= "bb";
		sayac = 0;
	}
	/**
	 * Resets the board to the solution.
	 */
	@Override
	void reset()
	{
		reset_correct();
		for (int i = 0; i < total; ++i)
		{
			puzzle1[i] = correctpuzzle1[i];
		}				
	}
	/**
	 * @param movee sends the desired move
	 */
	@Override
	void move(char movee)
	{
		lastmovee = movee;
		
		switch(movee)
		{
			case 'R':
					for (int i = 0; i < total-1; ++i)
					{
						if(puzzle1[i].equals("bb") )
						{
							if(!puzzle1[i+1].equals("00")   && (i+1)%row != 0)
							{
								puzzle1[i] = puzzle1[i+1];
								puzzle1[i+1] ="bb";
								i=total; 
								totalmoves1D++;
							}
							else
								System.out.println("this move (R) can not be made");
						}
					}
			break;
			case 'L':
					
					for (int i = 0; i < total-1; ++i)
					{
						if(puzzle1[i].equals("bb") )
						{
							if(!puzzle1[i-1].equals("00")   && i%row != 0)
							{
								puzzle1[i] = puzzle1[i-1];
								puzzle1[i-1] ="bb";
								i=total;
								totalmoves1D++;
							}
							else
								System.out.println("this move (L) can not be made");
						}
					}
			break;
			case 'U':
					for (int i = 0; i < total-1; ++i)
					{
						if(puzzle1[i].equals("bb") )
						{
							if(!puzzle1[i-row].equals("00")  && i>row)
							{
								puzzle1[i] = puzzle1[i-row];
								puzzle1[i-row] ="bb";
								i=total;
								totalmoves1D++; 
							}
							else
								System.out.println("this move (U) can not be made");
						}
					}
			break;
			case 'D':
					for (int i = 0; i < total-1; ++i)
					{
						if(puzzle1[i].equals("bb") )
						{
							if(!puzzle1[i+row].equals("00")   && i<(row*(column-1)))
							{
								puzzle1[i] = puzzle1[i+row];
								puzzle1[i+row] ="bb";
								i=total;
								totalmoves1D++; 
							}
							else
								System.out.println("this move (D) can not be made");
						}
					}
			break;
			default:
				System.out.println("Invalid Choice..");
		}
	}	
	/**
	 * @return return  board is true or false 
	 */
	@Override
	boolean isSolved() {
		
		boolean finish = true;
		for (int i = 0; i < total; ++i)
		{
			if(!puzzle1[i].equals(correctpuzzle1[i]))
				{
					return false;
				}
		}
		return finish;
	}
	/**
	 * @return return  data in given indexs
	 * @param i index i
	 * @param y index y
	 */
	@Override
	String cell(int i, int y)
	{
		return puzzle1[i+y];
	}	
	/**
	 * @return return String 
	 */
	@Override
	public String toString() {
		
		String str ="";
		int sayac =0;
		for(int i = 0; i<column ;i++)
		{
			for(int k = 0; k<row ;k++) 
			{
				str += puzzle1[sayac];
				str+=" ";
				sayac++;
			}
			str += "\n";
		}	
		return str;
	}
	/**
	 * @return return  last move  
	 */
	@Override
	char lastMove() 
	{
		return lastmovee;
	}
	/**
	 * @return return  number of moves  
	 */
	@Override
	int numberOfMoves()
	{
		return totalmoves1D;
	}
	/**
	 * @param filename write  
	 * @exception FileNotFoundException when there is no file
	 */
	@Override
	void writeToFile(String filename) throws IOException {
		 BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
		    writer.write(toString());
		    writer.close();
	}
	/**
	 * @return return  Boards are equals or not equals 
	 */
	boolean Equals(BoardArray1D other)
	{
		String[] board1 =this.puzzle1 ;
		String[] board2 =other.puzzle1;
		for(int i =0;i<total;i++ )
			if(!board1[i].equals(board2[i]))
				return false;
		return true;
	}
	


}
