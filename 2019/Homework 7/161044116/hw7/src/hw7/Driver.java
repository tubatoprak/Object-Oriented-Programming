package hw7;

public class Driver {
	public static void main(String[] args) throws Exception
	{
		
		System.out.println("----WELCOME TO HW7 :)----");
		System.out.println("---- For BoardArray1D----");
		BoardArray1D one1 = new BoardArray1D();
		String str ="dene.txt";
		one1.readFromFile(str);
		one1.reset_correct();
		System.out.println("-----Before Moving----- \n" +one1.toString());
		one1.move('R');
		one1.move('U');
		one1.move('L');
		one1.move('R');
		System.out.println("----After Moving------ \n" +one1.toString());
		System.out.println("Number of Moves: "+one1.numberOfMoves());
		System.out.println("Last Move: "+one1.lastMove());
		System.out.println("Cell(5): "+one1.cell(0,5));
		System.out.println("-----Reset-----");
		one1.reset();
		if(one1.isSolved())
			System.out.println("You Winnn....");
		else
			System.out.println("Try Again....");
		String filename = "writetofile.txt";
		one1.writeToFile(filename);
		System.out.println("Board Saved..");
		
		BoardArray1D one2 = new BoardArray1D();
		
		one2.readFromFile(str);
		one2.reset_correct();
		one2.reset();
		if(one1.Equals(one2))
			System.out.println("Boards Equal...");
		else 
			System.out.println("Boards Not Equal...");
		System.out.println("Number Of Boards: "+one1.NumberOfBoards());
		System.out.println("---- For BoardArray2D----");
		BoardArray2D two1 = new BoardArray2D();
		String strr ="dene.txt";
		two1.readFromFile(strr);
		two1.reset_correct();
		System.out.println("-----Before Moving----- \n" +two1.toString());
		two1.move('R');
		two1.move('U');
		two1.move('L');
		two1.move('R');
		System.out.println("----After Moving------ \n" +two1.toString());
		System.out.println("Number of Moves: "+two1.numberOfMoves());
		System.out.println("Last Move: "+two1.lastMove());
		System.out.println("Cell(0,5): "+two1.cell(0,5));
		System.out.println("-----Reset-----");
		two1.reset();
		if(two1.isSolved())
			System.out.println("You Winnn....");
		else
			System.out.println("Try Again....");
		two1.writeToFile(filename);
		System.out.println("Board Saved..");
		
		BoardArray2D two2 = new BoardArray2D();
		two2.readFromFile(str);
		two2.reset_correct();
		two2.reset();
		if(two1.Equals(two2))
			System.out.println("Boards Equal...");
		else 
			System.out.println("Boards Not Equal...");
		
	}		
}
	
